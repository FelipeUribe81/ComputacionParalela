from cy_functionE import rbf_network as py
import numpy as np
import time

D = 5
N = 1500
X = np.array([np.random.rand(N) for d in range(D)]).T
beta = np.random.rand(N)
tetha = 10

print(py(X, beta, tetha))

