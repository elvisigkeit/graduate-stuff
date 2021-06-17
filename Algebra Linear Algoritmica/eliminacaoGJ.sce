//Matriz A, mxn
A = [1, 1; 1, 0];
//vetor b
b = [4, 6];

[m, n]= size(A);

//No de linhas não-nulas
lnn = m;

for p = 1:lnn
   //Encontrar o proximo pivo
   linhap = m;
   colunap = n;
   for r = p:lnn
      c=1;
      while (c<=n & A(r,c)==0)
         c = c+1;
      end
      if c == (n+1) then
         if b(r) ~= 0 then
            disp("Sistema Impossivel");
            abort;
         end
         for q = 1:n
            aux = A(r,q);
            A(r,q) = A(lnn,q);
            A(lnn,q) = aux;
         end
         aux = b(r);
         b(r) = b(lnn);
         b(lnn) = aux;
         lnn = lnn-1;
      end
      //Atualizando caso o pivo de r seja o mais à esquerda
      if c < colunap then
         colunap = c;
         linhap = r;
      end
   end
   if p~=linhap then
      for r = 1:n
         aux = A(p,r);
         A(p,r) = A(linhap,r);
         A(linhap,r) = aux;
      end
      aux = b(p);
      b(p) = b(linhap);
      b(linhap) = aux;
   end
   pivo = A(p,colunap);
   
   //dividir a linha do pivo pelo valor do pivo
   for q = colunap:n
      A(p,q) = A(p,q)/pivo;
   end
   b(p) = b(p)/pivo;
   
   //zerar os elementos abaixo do pivo
   for r = (p+1):lnn
      mult = A(r,colunap);
      for q = colunap:n 
         A(r,q) = A(r,q) - mult*A(p,q);
      end
      b(r) = b(r)-mult*b(p);
   end
   
   //zerar os elementos acima do pivo
   if p>1 then
      for r=1:(p-1)
         mult = A(r,colunap);
         for q = colunap:n
            A(r,q)=A(r,q)-mult*A(p,q);
         end
         b(r) = b(r)-mult*b(p);
      end
   end
end

disp (A, b);
