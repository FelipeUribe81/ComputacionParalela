all:
		python3 setup.py build_ext --inplace
		cython -a cy_functionE.pyx
clean:
		rm -rf build *.so cy_functionE.c *html

