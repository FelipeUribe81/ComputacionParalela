from distutils.core import setup
from distutils.extension import Extension
from Cython.Build import cythonize
from Cython.Distutils import build_ext


ext_modules = [
    Extension('cy_simulador',
              ['cy_simulador.pyx'],
              libraries=['m'],
              extra_compile_args=['-ffast-math',
                                  '-fopenmp', '-march=native'],
              extra_link_args=['-fopenmp']
              )]

setup(
    name='cy_simulador',
    cmdclass={'build_ext': build_ext},
    ext_modules=ext_modules,
)
