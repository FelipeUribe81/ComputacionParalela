##############################################################################
#                          UNIVERSIDAD SERGIO ARBOLEDA
#                      COMPUTACIÓN PARALELA Y DISTRIBUIDA
#                            Felipe Uribe Guevara
#                               CC: 1000970791
##############################################################################
# py_functionE.py
###############################################################################

from math import exp
import numpy as np

def rbf_network(X, beta, theta):
    N = X.shape[0]
    D = X.shape[1]
    Y = np.zeros(N)

    for i in range(N):
        for j in range(N):
            r = 0
            for d in range(D):
                r += (X[j,d] - X[i, d]) ** 2
            r = r**0.5 
            Y[i] += beta[j] * exp(-(r * theta)**2)
    return Y

#D = 5
#N = 1500
#X = np.array([np.random.rand(N) for d in range(D)]).T
#beta = np.random.rand(N)
#tetha = 10

#print(rbf_network(X, beta, tetha))
