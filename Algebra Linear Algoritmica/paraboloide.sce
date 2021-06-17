clear

//Definida positiva
//A = [2, 0; 0, 2]

//Definida negativa
//A = [-4, 1; 2, -5]

//Semidefinida positiva
//A = [2, 2; 1, 1]

//Semidefinida negativa
//A = -1*[2, 2; 1, 1]

//Indefinida
//A = [-4, 2; 0, 7]

A = -1*[2, 2; 1, 1]
b = [1; 1]
c = 3

x = -4:0.1:4
y = -4:0.1:4

cx = length(x)
cy = length(y)

for i = 1:cx
    for j = 1:cy
        v = [x(i); y(j)]
        Z(i, j) = v'*A*v + b'*v + c
    end
end

surf(x, y, Z)
