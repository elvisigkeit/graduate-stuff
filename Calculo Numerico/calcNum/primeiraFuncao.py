# -*- coding: utf-8 -*-
"""
Created on Wed Oct  5 15:21:42 2016

@author: arctos
"""

import pylab as plt

X = plt.linspace(-2, 2, 30)
Y = X**2

print "%5s | %3s" %('X', 'Y')
print 15*'-'
for (x, y) in zip(X, Y):  
  print "%+6.1f| %+4.2f" %(x, y)

plt.plot(X, Y, 'r-')
plt.show()