#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "..\libs\colas\headers\colas.h"
#include "..\libs\listas\headers\listas.h"
#include "..\libs\pilas\headers\pilas.h"
#include "..\libs\hash\headers\tabla_hash.h"
#include "..\libs\arboles\headers\arbol-avl.h"
#include "..\libs\validaciones\headers\validaciones.h"
#include "tp_thash.h"


int main(){
    int q_claves, q_repeticiones, rango_desde, rango_hasta, dia_v, mes_v, anio_v, clave, ejercicio;
    char fecha[15];
    Lista l;
    int continuacion = 0;
    while (continuacion != -1)
    {
        ejercicio = validarentradaentero_arboles("Ingrese un el ejercicio a probar (4 , 5, 6): ");
        switch (ejercicio)
        {
        case 4:
            th_ej4_abm();
            break;
        case 5:
            q_claves  = validarentradaentero_arboles("Ingrese la cantidad de claves a generar: ");
            while (q_claves < 0 || q_claves > 2000)
            {
                printf("No puede ingresar menos de 0 claves o mas de 2000 claves.\n");
                q_claves  = validarentradaentero_arboles("Ingrese la cantidad de claves a generar: ");
            }
            
            q_repeticiones = validarentradaentero_arboles("Ingrese la cantidad de repeticiones a hacer: ");
            while (q_repeticiones < 0)
            {
                printf("No puede ingresar menos de 0 repeticiones.\n");
                q_claves  = validarentradaentero_arboles("Ingrese la cantidad de repeticiones a hacer: ");
            }
            rango_desde  = validarentradaentero_arboles("Ingrese el extemo minimo del rango: ");
            rango_hasta  = validarentradaentero_arboles("Ingrese el extremo maximo del rango: ");
            while ((rango_hasta - rango_desde) < q_claves){
                printf("Error. tamano del conjunto debe ser mayor a la cantidad de claves.\n");
                rango_desde = validarentradaentero_arboles("Ingrese un valor minimo del conjunto: ");
                rango_hasta = validarentradaentero_arboles("Ingrese un valor maximo del conjunto: ");
            }
            if (q_claves == 0)
            {
                printf("Hay 0 claves, no hay nada que hacer, tiempo : 0\n");
            }else if (q_repeticiones == 0)
            {
                printf("Hay 0 repeticiones, No hay nada que hacer, tiempo : 0\n");
            }else{
                if (q_repeticiones > 500)
                {
                    printf("En ejecucion, muchas iteraciones, va a demorar un poco...\n");
                }printf("En ejecucion.\n");
                th_ej5_comparacion(q_claves, q_repeticiones, rango_desde, rango_hasta);
            }
            break;
        case 6:
            th_ej6_covid();
            break;
        
        default:
            printf("Opcion incorrecta");
            break;
    }
    printf("\nQuiere probar otro tipo de ejercicio?\n");
    continuacion = validarsalida();
    }
    return 0;
}