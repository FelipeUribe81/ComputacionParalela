#Estudiante: Diana Carolina Quintero Bedoya
#Correo: diana.quintero01@correo.usa.edu.co 
#Carrera: Ciencia Computacional e Inteligencia Artificial
#Estudiante: David Fernando Cruz Martinez
#Correo: david.cruz01@correo.usa.edu.co
#Carrera: Ingenieria de Sistemas y Telecomunicaciones
#Profesor: John Jairo Corredor Franco
#MATERIA: Computacion Paralela y Distribuida
#UNIVERSIDAD SERGIO ARVOLEDA
#FECHA: 22/04/

#Polinomios de Hermite

#Todos los polinomios de Hermite de orden n>2 se pueden expresar 
#en términos de los dos primeros polinomios H0(x) y H1(x), 
#de orden cero y uno respectivamente, mediante la siguiente 
#relación de recurrencia.

#Hn(x)=2x⋅Hn−1(x)−2(n−1)Hn−2(x)

def herminate(n, x):
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
    

