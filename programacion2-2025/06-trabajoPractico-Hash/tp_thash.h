#ifndef TP_ARBOLES_H
#define TP_ARBOLES_H

#include <stdbool.h>
#include "..\libs\listas\headers\listas.h"
#include "..\libs\hash\headers\tabla_hash.h"


/**
4. Desarrollar un algoritmo que dado un archivo que contendra los datos de alumnos  (legajo, apellido, nombres, domicilio, TE) 
   genere una tabla hash donde la clave sera el legajo y se guardara como dato la posición física 
   del registro para realizar accesos directos.  
   Hacer un ABM para poder cargar manualmente el archivo.  El “legajo" es un valor de 6 dígitos. 
*/
void th_ej4_abm();


/**
5. Realizar una comparación de los tiempos de accesos a las claves entre un arbol AVL y una Tabla Hash. 
   El operador debe poder indicarle cuantas claves se deben generar (entre 1 y 2000), cuantas repeticiones 
   se realizaran y cual es el rango de las claves a generar.   
   Luego se tomaran claves al azar dentro del mismo rango y se buscaran en ambas estructuras.  
   El proceso se repetira “n” veces (repeticiones a ingresar por el operador).  
   Documentar la conclusión final respecto a los tiempos de accesos de ambas estructuras. 
*/
void th_ej5_comparacion(int q_claves, int q_repeticiones, int rango_desde, int rango_hasta);


/**
6. Se desea poder implementar una solución para encontrar de forma rapida los datos de las personas que a una fecha
   determinada se presentaron a vacunar contra el COVID.  
   Es decir dada una fecha determinada debería obtener quienes se vacunaron. 
   De cada persona se guarda basicamente el DNI, Apellido y Nombre.  
   Se debe ademas hacer una pantalla de carga donde se pueda especificar la fecha y los datos de las personas 
   que se vacunaron en esa fecha. 
*/
int th_ej6_covid();

#endif // TP_ARBOLES_H
