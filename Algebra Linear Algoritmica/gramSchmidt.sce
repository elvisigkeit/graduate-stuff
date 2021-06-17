clear

W = [1,0,5;2,1,2;-3,1,0],
[n,k] = size(W)
Q = zeros(n, k)

for j = 1:k
    s = zeros(n,1)
    for p = 1:(j-1)
        s = s + Q(:,p) * Q(:,p)' * W(:,j);
    end
    s = W(:,j) - s
    Q(:,j) = s/norm(s,2)
end

disp('base original')
disp(W)
disp('base ortogonal')
disp(Q)

//para encontrar os termos de vetor nos eixos ortonormais novos

x = [1;2;3]
for i = 1:k
    coef(i) = norm(Q(:,i)*Q(:,i)'*x, 2)
end
