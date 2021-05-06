##############################################################################
#                          UNIVERSIDAD SERGIO ARBOLEDA
#                      COMPUTACIÓN PARALELA Y DISTRIBUIDA
#                            Felipe Uribe Guevara
#                               CC: 1000970791
##############################################################################
# setup.py
###############################################################################

from distutils.core import setup, Extension
from Cython.Build import cythonize
import numpy

setup(ext_modules=cythonize("cy_functionE.pyx"),
    include_dirs=[numpy.get_include()]
)
