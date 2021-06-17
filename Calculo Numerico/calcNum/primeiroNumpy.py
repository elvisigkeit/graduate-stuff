# -*- coding: utf-8 -*-
"""
Created on Wed Oct  5 07:21:28 2016

@author: arctos
"""

import numpy as np

#lista para ndarray
#y = [[1.2, 3.5], [2.6, 0]]
y = [[1.2, 3.5, 2.6, 0]]

x = np.array(y)
x.shape = (2, 2)

print "\nX transformado de uma lista:\n", x

#funções de criação

x = np.arange(0, 10, 2)
print "\narange(0, 10, 2): ", x


x = np.linspace(1, 10, 5)
#np.linspace(1, 10, 5, False) -> indica 5 intervalos 
print "\nlinspace(1, 10, 5): ", x