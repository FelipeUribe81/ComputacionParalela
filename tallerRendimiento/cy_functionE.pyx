#cython: lenguaje_level=3
#from math import exp
cdef extern from "math.h":
        double exp(double x)
cdef extern from "math.h":
        double pow(double x, double y)

import numpy as np

def rbf_network(X, beta, theta):
    N = X.shape[0]
    D = X.shape[1] 
    Y = np.zeros(N)     

    for i from 0 <=i < N:
        for j from 0 <=j < N:
            r = 0
            for d from 0 <= d < D:
                r += pow((X[j,d] - X[i, d]),2)
            r = pow(r, 0.5) 
            Y[i] += beta[j] * exp(pow(-(r * theta),2))
    return Y

