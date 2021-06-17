H = read ('/convidado/Codigos/arquivo.txt', 280, 252)
H(:,1) = 0
H(1,:) = 0
figure
Matplot(H)
[nl, nc] = size(H)
N = 255*ones(nl, nc)
theta = %pi/8
A = [1.2, 0; -0.3, 1.2]
//A = [cos(theta) -sin(theta); sin(theta) cos(theta)] //rotacao
for i = 1:nl
    for j = 1:nc
        if H(i, j) < 255 then
            w = [i; j]
            wn = round(A*w)
            wr = A*w
            if (wn(1)<=nl)&(wn(1)>=1)&(wn(2)<=nc)&(wn(2)>=1) then
                N(wn(1), wn(2)) = H(i, j)
            end
        end
        if j>3 & (N(i,j)==0 & N(i, j-2) ==0) then
            N(i, j-1) = 0;
        end
        if i>3 & (N(i,j)==0 & N(i-2, j) ==0) then
            N(i-1, j) = 0;
        end
    end
end
figure
Matplot(N)
