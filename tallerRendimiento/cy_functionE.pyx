##############################################################################
#                          UNIVERSIDAD SERGIO ARBOLEDA
#                      COMPUTACIÓN PARALELA Y DISTRIBUIDA
#                            Felipe Uribe Guevara
#                               CC: 1000970791
##############################################################################
# cy_functionE.pyx
###############################################################################

#cython: lenguaje_level=3
#from math import exp
cdef extern from "math.h":
        double exp(double x)
        double pow(double x, double y)

import numpy as np
cimport numpy as cnp 

def rbf_network(cnp.ndarray[cnp.double_t, ndim=2] X, cnp.ndarray[cnp.double_t, ndim=1] beta, int theta):
    cdef int N = X.shape[0]
    cdef int D = X.shape[1] 
    cdef cnp.ndarray[cnp.double_t, ndim=1] Y
    Y = np.zeros(N)     
    cdef int i
    cdef int j
    cdef int d
    cdef double r
    for i from 0 <=i < N:
        for j from 0 <=j < N:
            r = 0
            for d from 0 <= d < D:
                r += pow((X[j,d] - X[i, d]),2)
            r = pow(r, 0.5) 
            Y[i] += beta[j] * exp(pow(-(r * theta),2))
    return Y

