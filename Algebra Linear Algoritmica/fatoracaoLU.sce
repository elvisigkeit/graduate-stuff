//Matriz A, mxn
//A = [6, -2, 0; 9, -1, 1; 3, 7, 5]; MATRIZ LINDA
//A = [0, 0, -2; 2, 4, -10; 2, 5, 1]; MATRIZ QUE TROCA
A = [0, 3, 1; 2, -2, 1; 1, 5, 2.5];
//vetor b
//b = [1, 2, 3]

[m, n]= size(A);
P = eye(m, n);
L = zeros(m, n);

//Ultima linha válida da matriz, linha nao nulas
lnn = m;

for p = 1:lnn
   //Encontrar o proximo pivo
   linhap = m;
   colunap = n;
   for r = p:lnn
      c=1;
      //corre os numeros zero antes do pivo
      while (c<=n & A(r,c)==0)
         c = c+1;
      end
      //se a linha está vazia, troca ela com a ultima válida
      if c == (n+1) then
         for q = 1:n
            aux = A(r,q);
            A(r,q) = A(lnn,q);
            A(lnn,q) = aux;
         end
         lnn = lnn-1;
      end
      //Atualizando caso o pivo de r seja o mais à esquerda
      if c < colunap then
         colunap = c;
         linhap = r;
      end
   end
   //se o menor pivo não estiver na atual linha, troque essas linhas
   if p~=linhap then
      for r = 1:n
         aux = A(p,r);
         A(p,r) = A(linhap,r);
         A(linhap,r) = aux;
         aux = P(p,r);
         P(p,r) = P(linhap,r);
         P(linhap,r) = aux;
         aux = L(p,r);
         L(p,r) = L(linhap,r);
         L(linhap,r) = aux;
      end
   end
   pivo = A(p,colunap);
   L(p, colunap) = A(p, colunap);
   
   
   //dividir a linha do pivo pelo valor do pivo
   if pivo ~= 0 then
      for q = colunap:n
         A(p,q) = A(p,q)/pivo;
      end
   end
   
   //zerar os elementos abaixo do pivo
   for r = (p+1):lnn
      mult = A(r,colunap);
      L(r, colunap) = A(r, colunap);
      for q = colunap:n 
         A(r,q) = A(r,q) - mult*A(p,q);
      end
   end
end

verA = inv(P)*L*A;

//no final, a matriz A possui os valores de U
disp (verA, "A: ", L, "L: ", A, "U: ", P, "P: ");
