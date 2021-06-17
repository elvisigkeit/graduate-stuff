import numpy as np
#import matplotlib.pyplot as plt
import scipy.linalg as spl
from pylab import *
from mpl_toolkits.mplot3d import Axes3D

# Grafico de Curva de Niveis em 2D
xi = -2.0; xf = 2.0; numx = 150
yi = -2.0; yf = 2.0; numy = 150
def f(x,y):
     return cos(x)
contourfillflag = True
contourfillonlyflag = False
contourlevels = True
#contourlevels = 20
# contourlevels = linspace(0.0,1.0,10)
# contourlevels = (0.0,0.2,0.4,0.6,0.8,1.0)
contourlabelsflag = True
contourlevelsbarflag = True
xlabeltext = r'x'; ylabeltext = r'y'
titletext = r'$f(x,y)=\,\cos(\pi\,x\,y)^2 e^{-\frac{x^2+y^2}{2}}$'
gridflag = True
## Name of the file where the plot is saved (in current directory).
## Possible extensions : png, pdf, ps, eps and svg :
plotfilename = 'grafcontorno.png'
##############################################################################
# Nso mexe daqui pra baixo

x = arange(xi, xf, (xf-xi)/(numx-1))
y = arange(yi, yf, (yf-yi)/(numy-1))
X,Y = meshgrid(x, y)
z = f(X,Y)
if contourfillflag:
    if contourlevels == True:
        if not contourfillonlyflag:
            c1 = contour(x,y,z,colors='k')
        c2 = contourf(x,y,z)
    else:
        if not contourfillonlyflag:
            c1 = contour(x,y,z,contourlevels,colors='k')
        c2 = contourf(x,y,z,contourlevels)
    if contourlevelsbarflag:
        cb2 = colorbar(c2)
else:
    if contourlevels == True:
        c1 = contour(x,y,z)
    else:
        c1 = contour(x,y,z,contourlevels)
    if contourlevelsbarflag:
        colorbar(c1)
if contourlabelsflag and ((not contourfillflag) or (not contourfillonlyflag)):
    l1 = clabel(c1)
xlabel(xlabeltext); ylabel(ylabeltext); title(titletext)
grid(gridflag)
## To show instead of saving the plot, just use 'show()' :
show()
#savefig(plotfilename)

##grafico 3d


n_angulos = 72
n_raios = 4

# linspace() - Cria um vetor de raios.

raio = np.linspace(0.125, 1.0, n_raio)

# Criando os angulos.
# O intervalo vai de 0 a 2 e multiplicado por pi.
# endpoint=True - Significa que o numero final do intervalo entra no calculo.
angulos = np.linspace(0, 2 * np.pi, n_angulos, endpoint=True)

# Criando a malha
# Para cada raio repetiremos o vetor dos angulos.
angulos = np.repeat(angulos[..., np.newaxis], n_raios, axis=1)

# Convertendo os pontos de coordenadas polares (raio e angulo)
# para coordenadas cartesianas (x e Y).
# Atraves do append estamos adicionado zero como ponto inicial.
x = np.append(0, (raio * np.cos(angles)).flatten())
y = np.append(0, (raio * np.sin(angles)).flatten())

# Aplicando os pontos criados nos pontos da malha.
z = np.sin(-x * (y ** 2)) + np.cos((x ** 2) * -y)

# Criando uma figura.
fig = plt.figure()

# Indicando que a projecao da figura sera 3D.
ax = fig.gca(projection='3d')

# plot_trisurf() - Gera o grafico (x, y, z).
# cmap - Gera a cor da malha que e exibida no grafico.
# linewidth - Comprimento da linha, este valor vai de 0 a 1.
ax.plot_trisurf(x, y, z, cmap='Greens', linewidth=0.1)

# Exibe o grafico.
plt.show()



