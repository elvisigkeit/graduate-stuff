# -*- coding: utf-8 -*-
"""
Created on Sat Dec 17 13:24:11 2016
"""

import sys as sys
import numpy as np
from matplotlib import pyplot as plt
from matplotlib import cm as cm
import scipy.linalg as la
import matplotlib.animation as animation
import scipy.ndimage as im
from scipy.integrate import odeint
from pylab import *
from mpl_toolkits.mplot3d import Axes3D

variaveis = [
    (5.0, 5.0),  # dimensoes do dominio D: (b, d)
    (0.0, 0.0),  # posicao da origem do dominio D: (a, c)
    'sin(t)+cos(y)', # f(t,y)
    40, # Nt
    40, # Ny
    ]

# setup inicial
Dl,Do,f,Nt,Ny = variaveis
f = eval('lambda t, y:'+f)
a, c = np.array(Do)
b, d = np.array(Do)+np.array(Dl)
dt = (b-a)/Nt
dy = (d-c)/Ny
paleta = 'afmhot'

## questao 1-a
## ===========
T = np.arange(a, b, dt)
Y = np.arange(c, d, dy)
T, Y = np.meshgrid(T, Y)
Z = f(T, Y)

#Parte da questão C
G1, G2 = np.gradient(Z)

fig = plt.figure()
ax = Axes3D(fig)
ax.plot_surface(T, Y, Z, rstride=1, cstride=1, cmap='hot')
plt.title("Grafico 3D da f(t, y)")
plt.show()


# questao 1-b
# ===========
Nniv = 10

szmul = 1
ti = a; tf = b; numt = Nt*szmul
yi = c; yf = d; numy = Ny*szmul

t = np.arange(ti, tf+1, (tf+1-ti)/(numt))
y = np.arange(yi, yf+1, (yf+1-yi)/(numy))
T,Y = np.meshgrid(t, y)
Z = f(T, Y)
zflat = Z.flatten()

vmin = min(zflat)
vmax = max(zflat)

extent = (a, b, c, d)
fig,ax = plt.subplots()
cax = ax.imshow(Z, extent=extent, cmap=paleta, interpolation="nearest", vmin=vmin, vmax=vmax)
c1 = ax.contour(T, Y, Z, levels=np.arange(vmin, vmax, (vmax-vmin)/Nniv), colors='k', vmin=vmin, vmax=vmax)
c2 = ax.contourf(T, Y, Z, levels=np.arange(vmin, vmax, (vmax-vmin)/Nniv), cmap=paleta, vmin=vmin, vmax=vmax)
fig.colorbar(cax)
plt.show()


##questao 1-c
# ===========

G = [G1*G1, G2*G2]
G = [G1/np.sqrt(G[0]+G[1]), G2/np.sqrt(G[0]+G[1])]
G1, G2 = G
plt.quiver(T, Y, G1, G2, color = 'black', headlength = 5)
plt.title("Campo Normalizado 2D")
plt.show()

##questao 1-d
# ===========

u0 = 0.0
t0 = 0.0
v1 = np.pi
t1 = 0.0

intervalou = np.arange(t0, b, dt)
intervalov = np.arange(t1, b, dt)

u = odeint (f, u0, intervalou)
v = odeint (f, v1, intervalov)

plot (intervalou, u, label="u(t)")
plt.legend(loc='best')
plt.xlabel('t')
plot (intervalov, v, label="v(t)")
plt.legend(loc='best')
plt.xlabel('t')
plt.title("Grafico das solucoes u e v")
show()

