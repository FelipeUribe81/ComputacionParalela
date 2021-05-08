all:
		python3 setup.py build_ext --inplace
		cython -a cy_simulador.pyx
clean:
		rm -rf build *.so cy_simulador.c *html

