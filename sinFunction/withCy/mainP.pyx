#cython: language_level=3
from math import pi

def factorial(long double number):
    if (number == 0):
        return 1
    else:
        return factorial(number-1)*number

def sinFunction(long double number, long double i, long double size, long double acum):
    if (i == size):
        return acum
    else:
        acum += ((-1)**i * arg**(2*i+1))/(factorial(2*i+1))
        return sinFunction(number, i+1, size, acum)

if __name__ == '__main__':
    import sys
    #cdef long double number, size, arg, result
    number, size = map(float, sys.argv[1:])
    arg = number/180*pi  
    result = sinFunction(number, 0, size, 0)
    print(result)