## Programa para automatizar las ejecuciones de cython, python yC
## Posteriormente llevar a un archivo csv
from timeit import repeat
from subprocess import check_output
import csv

def tiempos(arg, niter, nombre, modulo):
    stmt = "%s(%s)" %(nombre,arg)
    setup = "from %s import %s" % (modulo, nombre)
    tiempo = min(repeat(stmt=stmt, setup=setup, number=niter))/float(niter)*1e9
    return tiempo

### Ejecución para fib(0) con N repeticiones
N = 10
py_tiempo = tiempos(0, N, nombre='pyfib', modulo='pyfib')
#cy_tiempo = tiempos(0, N, nombre='pyfib', modulo='cyfib')
c_tiempo = float(check_output(('./cfib.x 0 %d' % N).split()))

#print('sddssd')
print("Tiempo en Py {}\n".format(py_tiempo))
#print("Tiempo en Cy {}\n".format(cy_tiempo))
print("Tiempo en C {}\n".format(c_tiempo))