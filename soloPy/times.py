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
N = 10**9
py_tiempo = tiempos(0, N, nombre='pfib', modulo='pfib')
cy_tiempo = tiempos(0, N, nombre='pfib', modulo='cyfib')
c_tiempo= float(check_output(('./cfib.x 0 %d' % N).split())


### Calculo de SpeedUP
py0SpeedUp = 1.0
cy0SpeedUp = py_tiempo / cy_tiempo
c_0SpeedUp = py_tiempo / c_tiempo


### Ejecución para fib(0) con N repeticiones
N = 10**9
py_tiempo_90 = tiempos(90, N, nombre='pfib', modulo='pfib')
cy_tiempo_90 = tiempos(90, N, nombre='pfib', modulo='cyfib')
c_tiempo_90 = 0 float((check_output('./cfib.x 90 %d' %N).split())

### Calculo de SpeedUP
py90SpeedUp = 1.0
cy90SpeedUp = py_tiempo_90 / cy_tiempo_90
c_90SpeedUp = py_tiempo_90 / c_tiempo_90


### Formato de datos 
formato_datos = "{:s},{:f},{:f},{:f}\n"

### Se crea un archivo del tipo csv, para almacenar 
### los tiempos de cada version/argumento junto con el speedUp

with open("fiboTimeSP.csv", w) as fh:
    fh.write("Version,fib(0) [ns],SpeedUp,fib(90) [ns],SpeedUp\n")
    fh.write(formato_datos.format("Python", py_tiempo,py0SpeedUp, py_tiempo_90,py90SpeedUp))
    fh.write(formato_datos.format("Cython", cy_tiempo,cy0SpeedUp, cy_tiempo_90,py90SpeedUp))
    fh.write(formato_datos.format("Solo C", c_tiempo,c_0SpeedUp, c_tiempo_90,c_90SpeedUp))
    