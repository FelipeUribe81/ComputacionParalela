##############################################################################
#                             UNIVERSIDAD SERGIO ARBOLEDA
#                         COMPUTACIÓN PARALELA Y DISTRIBUIDA
#                                 Felipe Uribe Guevara
#                                    CC: 1000970791
##############################################################################
#Comparativa de rendimiento entre Python y Cython
#Requerimientos del problema:
#1.- Escribir la función rbf_network y la función principal (test) en Python.
#2.- Trancribir la función rbf_network y el test a Cython.
#3.- Realizar una comparativa en cuanto al rendimiento en Cython.
#4.- Graficar demostrando la superioridad de cython.
###############################################################################

from py_functionE import rbf_network as py_rbf_network
from cy_functionE import rbf_network as cy_rbf_network
import numpy as np
import time

# La función runTest que ejecuta el programa 6 veces con un D mayor 
# cada iteracion
def runTest(N, beta, tetha):
    for D in range (5, 105, 20):
        X = np.array([np.random.rand(N) for d in range(D)]).T
        initial = time.time()
        py_rbf_network(X, beta, tetha)
        tiempoPy = time.time() - initial

        initial = time.time()
        cy_rbf_network(X, beta, tetha)
        tiempoCy = time.time() - initial

        SpeedUp = round(tiempoPy/tiempoCy, 3)

        print("tiempo Py: {}\n".format(tiempoPy))
        print("tiempo Cy: {}\n".format(tiempoCy))
        print("SpeedUp: {}\n".format(SpeedUp))

N = 1500
beta = np.random.rand(N)
tetha = 10
runTest(N,beta,tetha)
