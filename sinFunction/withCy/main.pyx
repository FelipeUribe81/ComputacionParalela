#cython: language_level=3
from math import pi

cdef int factorial(cdef int number):
    if (number == 0):
        return 1
    else:
        return factorial(number-1)*number

cdef double sinFunction(cdef double number, cdef int i, cdef int size, cdef double acum):
    if (i == size):
        return acum
    else:
        acum += ((-1)**i * arg**(2*i+1))/(factorial(2*i+1))
        return sinFunction(number, i+1, size, acum)
    
if __name__ == '__main__':
    import sys
    number, size = map(float, sys.argv[1:])
    arg = number/180*pi  
    cdef double result = sinFunction(number, 0, size, 0)
    print(result)
  