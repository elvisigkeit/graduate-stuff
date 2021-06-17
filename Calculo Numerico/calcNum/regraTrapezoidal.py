# -*- coding: utf-8 -*-
"""
Created on Wed Oct  5 16:42:50 2016

@author: arctos
"""

import numpy as np
import matplotlib.pyplot as plt

print "Por favor, indique o intervalo"
a, b = np.float32(input('a, b = '))

print "Agora indique o nr de pontos"
N = np.int32(input('N = '))

def f(t):
  return 1./t

X, h = np.linspace(a, b, N+1, retstep=True)
Y1 = f(X)
soma = Y1[0] + Y1[-1]
soma += 2*np.sum(Y1[1:N])
trap = soma*h/2

print "Aproximacao feita: %7.5f" %trap
print "Para conferir, ln(b) - ln(a) = ", np.log(b)-np.log(a)

Y2 = np.zeros_like(X)
f_h = (b-a)/20.
M = np.amax(Y1)
m = np.amin(Y1)
f_v = (M-m)/20
plt.plot(X, Y1, 'r-', label='f(t)')
plt.fill_between(X, Y1, Y2, where=None, color='yellow')
plt.plot([a,a], [0.,Y1[0]], 'k--')
plt.plot([b,b], [0.,Y1[-1]], 'k--')
plt.title("Integral da funcao 1/t")
plt.legend(loc='best')
plt.xlabel('X')
plt.ylabel('Y')
A = min(0., a)-f_h
B = max(0., b)+f_h
Ym = min(0., m)-f_v
YM = max(0., M)+f_v
plt.grid(True)
plt.axhline(y=0, xmin=A, xmax=B, c='k')
plt.axvline(x=0, ymin=Ym, ymax=YM, c='k')
plt.axis([A, B, Ym, YM])
plt.show()
