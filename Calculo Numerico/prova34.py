import numpy as np
import scipy.sparse.linalg as la
import numpy.linalg as li
A = np.array([[1.0, 0.0, -1.0], [0.0, 1.0, 0.0], [1.0, 0.0, 1.0]])

invA = li.inv(A)
vSE, valores, vSD = la.svds(A, min(A.shape)-1)
vSE, invValores, vSD = la.svds(invA, min(invA.shape)-1)

print "UE :", invValores[0]

print("Numero de Condicao 1 ")
print li.cond(A, 1)
print("Norma 1 ")
print li.norm(A, 1)
print("Numero de Condicao Infinito ")
print li.cond(A, np.inf)
print("Norma Infinita ")
print li.norm(A, np.inf)
print("Numero de Condicao 2 ")
print valores[0]*invValores[0]
print("Norma 2")
print valores[0]
