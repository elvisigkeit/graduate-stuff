P4 = 20
P1 = 1
P2 = 1
P3 = 1

t = [-4: 0.1: 4]
nt = length(t)

for i = 1:nt
    for j = 1:nt
        Z(i,j) = 8*sqrt((t(i)^2)+(t(j)^2))
        plano(i,j) = (1/P3)*(P4-P1*t(i)-P2*t(j))
    end
end

plot3d(t, t, Z)
plot3d(t, t, -Z)
plot3d(t, t, list(plano, color("red")*ones(1, max(size(plano)))))
