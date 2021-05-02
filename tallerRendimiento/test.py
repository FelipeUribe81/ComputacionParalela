from functionE import rbf_network as py
from cy_functionE import rbf_network as cy
import numpy as np
import time

D = 5
N = 1500
X = np.array([np.random.rand(N) for d in range(D)]).T
beta = np.random.rand(N)
tetha = 10


initial = time.time()
py(X, beta, tetha)
tiempoPy = time.time() - initial

initial = time.time()
cy(X, beta, tetha)
tiempoCy = time.time() - initial

SpeedUp = round(tiempoPy/tiempoCy, 3)

print("tiempo Py: {}\n".format(tiempoPy))
print("tiempo Cy: {}\n".format(tiempoCy))
print("SpeedUp: {}\n".format(SpeedUp))
