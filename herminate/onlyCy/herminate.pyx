#cython: lenguaje_level = 3

#Estudiante: Diana Carolina Quintero Bedoya
#Correo: diana.quintero01@correo.usa.edu.co 
#Carrera: Ciencia Computacional e Inteligencia Artificial
#Estudiante: David Fernando Cruz Martinez
#Correo: david.cruz01@correo.usa.edu.co
#Carrera: Ingenieria de Sistemas y Telecomunicaciones
#Profesor: John Jairo Corredor Franco
#MATERIA: Computacion Paralela y Distribuida
#UNIVERSIDAD SERGIO ARVOLEDA
#FECHA: 22/04/2021


def herminate(int n, int x):
    if n == 0:
        return 1
    elif n == 1:
        return 2*x
    else:
        return 2 * x * herminate(n-1, x) - 2 * (n-1) * herminate(n -2, x)           

if __name__ == "__main__":

    import sys

    n, x = map(int, sys.argv[1:])

    print(herminate(n, x))
    

