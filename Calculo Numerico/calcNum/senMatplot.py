# -*- coding: utf-8 -*-
"""
Created on Wed Oct  5 16:03:50 2016

@author: arctos
"""

import pylab as plt

X = plt.linspace(-plt.pi, plt.pi, 51)
Y = plt.cos(X)
Z = plt.sin(X)

plt.plot(X, Y, 'r-', label='cos(x)')
plt.plot(X, Z, 'b-', label='sen(x)')

plt.title('Funcoes Trigonometricas')
plt.legend(loc='best')
plt.xlabel('X')
plt.ylabel('Y')
plt.grid(True)
plt.axhline(y=0, xmin=-plt.pi, xmax=plt.pi, c='k')
plt.axvline(x=0, ymin=-1.5, ymax=1.5, c='k')
plt.axis([-plt.pi, plt.pi, -1.5, 1.5])
plt.show()