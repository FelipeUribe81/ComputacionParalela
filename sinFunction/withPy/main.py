
############################################################################################################
#                                         Universidad Sergio Arboleda                                              
#                                   Escuela de Ciencias Exactas e Ingeniería                                      
#                                      Autores: Juan José Montenegro Pulido,                             
#                           Camilo Andres Romero Maldonado & Felipe Uribe Guevara                            
#                                      Programación Paralela y Distribuida                                        
#                                  Profesor: Ph.D. John Jairo Corredor Franco                                   
#############################################################################################################

#   Este programa tiene como objetivo calcular el valor de la función seno según el ángulo 
#   y las iteraciones de la serie indicadas    

################################################ RESUMEN ####################################################

# Este archivo implementa las funciones recursivas factorial y seno con las cuales se calcula 
# el valor de seno según la fórmula de serie de seno

##################################### INSTRUCCIONES PARA EJECUTAR ###########################################

# Para ejecutar el programa se utliza el interprete de python en este caso python3 de la 
# siguiente manera: python3 "nombreDelprograma.py" "Angulo en grados" "N refieriendo al tamaño de la serie"
# El limite de la variable "N numero de la serie, es de "85" debido a que pasa la capasidad de almacenamiento
# de la varibale del tipo foltante.

#############################################################################################################

from math import pi

def factorial(number):
    if (number == 0):
        return 1
    else:
        return factorial(number-1)*number

def sinFunction(number, i, size, acum):
    if (i == size):
        return acum
    else:
        acum += ((-1)**i * arg**(2*i+1))/(factorial(2*i+1))
        return sinFunction(number, i+1, size, acum)

if __name__ == '__main__':
    import sys
    number, size = map(float, sys.argv[1:])
    arg = number/180*pi  
    result = sinFunction(number, 0, size, 0)
    print(result)