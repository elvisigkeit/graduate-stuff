# -*- coding: utf-8 -*-
"""
Created on Wed Oct  5 14:06:06 2016

@author: arctos
"""

import pylab as pyl

x = [2.1, 2.4, 2.6, 2.1]
y = [3.2, 2.8, 3.0, 3.2]

pyl.plot(x, y, 'b-', label='Lados')
pyl.plot(x, y, 'bo', label='Vertices')
pyl.title('Triangulo')
pyl.legend(loc='best')
pyl.xlabel('X')
pyl.ylabel('Y')
pyl.axis([2.0, 2.7, 2.7, 3.3])
pyl.show()