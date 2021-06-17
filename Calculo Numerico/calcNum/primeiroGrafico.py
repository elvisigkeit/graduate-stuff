# -*- coding: utf-8 -*-
"""
Created on Wed Oct  5 06:30:51 2016

@author: arctos
"""

from pylab import *

x = arange(1, 13, 1)

y = [0.125, 0.15625, 0.1875,
     0.21875, 0.25, 0.3125,
     0.375, 0.4375, 0.5,
     0.625, 0.75, 0.875]
     
print "Y = ", y
print "Veja o gráfico: "

yticks(y)
xticks(x)
grid(True)
plot(x, y, 'ro', x, y, 'b-')
show()