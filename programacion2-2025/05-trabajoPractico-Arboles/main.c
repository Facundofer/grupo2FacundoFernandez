#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tp_arboles.h"
#include "../libs/arboles/headers/nodo.h"
#include "../libs/listas/headers/listas.h"
#include "../libs/arboles/headers/arbol-binario.h"
#include "../libs/validaciones/headers/validaciones.h"
#define MAX 100

int main() {
    int ejercicio = 0, subopcion, clave, nivel, resultado, cantidadclavesagenerar, valorminimo, valormaximo, N_repeticiones;
    ArbolBinario arbol, arbol_dos;
    Lista lista_resultado = l_crear();
    NodoArbol nodo_Binario;
    TipoElemento te, te_aux;
    Iterador ite;
    ArbolAVL arbol_AVL;
    ArbolBinarioBusqueda arbol_BB;
    do {
        ejercicio = validareleccion_arboles();
        if (ejercicio == -1) break;

        arbol = a_crear();
        arbol_dos = a_crear();       
        switch (ejercicio) {
        case 2:
            printf("\nEjercicio 2\n");
            printf("\nCargar Arbol Binario \n");
            cargar_arbol_binario(arbol);
             do{
                printf("\nEjercicio 2\n");
                printf("1) a) Listar hojas.\n");
                printf("2) b) Listar nodos interiores.\n");
                printf("3) c) Buscar ocurrencias de una clave.\n");
                subopcion = validarentradaentero_arboles("Seleccione una opcion (1-3): ");
                switch (subopcion) {
                    case 1:
                        if (a_es_vacio(arbol))
                        {
                            printf("El arbol esta vacio.\n");
                            
                        }else{
                            lista_resultado = a_ej2_hojas(arbol);                                                  
                            printf("Nodos teminaless u Hojas del arbol:\n");
                            l_mostrar(lista_resultado);    
                        }                  
                        break;
                    case 2:
                        if (a_es_vacio(arbol))
                        {
                            printf("El arbol esta vacio.\n");
                            
                        }else{
                            lista_resultado = a_ej2_interiores(arbol);
                            if (!l_es_vacia(lista_resultado))
                                {                               
                                    printf("Nodos interiores del arbol:\n");
                                    l_mostrar(lista_resultado);    
                                }else printf("No hay nodos interiores.\n");
                        }
                        break;
                    case 3:
                        if (a_es_vacio(arbol))
                        {
                            printf("El arbol esta vacio.\n");
                           
                        }else{
                            clave = validarentradaentero_arboles("Ingrese una clave a buscar: ");
                            lista_resultado = a_ej2_buscarclave(arbol, clave);
                            if (!l_es_vacia(lista_resultado))
                            {
                                printf("Ocurrencias de la clave %d:\n", clave);
                                l_mostrar(lista_resultado);
                            }else printf("La clave no se encuentra en el arbol.\n");
                        }
                        break;
                    default:
                        printf("Opcion invalida.\n");
                }
                if (!l_es_vacia(lista_resultado))
                {
                    l_vaciar(lista_resultado);
                }
                ejercicio = validarsalida();
            } while (ejercicio != -1);
            printf("La complejidades algoritmicas del ejercicio 2 son:\n");
            printf("a) Complejidad lineal. Recorre todo el arbol para encontrar las hojas u nodos terminales\n");
            printf("a) Complejidad lineal. recorre todo el arbol buscndo nodos ineriores.\n");
            printf("a) Complejidad lineal. Recorre todo el arbol buscando la clave peor caso la encuentra en el ultimo nodo.\n");
        break;
        case 3:
            printf("\nEjercicio 3\n");
            printf("\nCargar Arbol Binario \n");
            cargar_arbol_binario_Natural(arbol);
            do
            {                   
                printf("\nEjercicio 3\n");
                printf("1) a) Clave del padre.\n");
                printf("2) b) Listar hijos.\n");
                printf("3) c) Clave del hermano.\n");
                printf("4) d) Nivel del nodo.\n");
                printf("5) e) Altura de la rama.\n");
                printf("6) f) Claves en el mismo nivel.\n");
                subopcion = validarentradaentero_arboles("Ingresa una opcion (1 - 6): ");
                switch (subopcion) {
                    case 1:
                       if (a_es_vacio(arbol))
                       {
                           printf("El arbol esta vacio.\n");
                       }else{
                           clave = validarentradaentero_arboles("Ingrese una clave del padre a buscar: ");
                           nodo_Binario = a_raiz(arbol);
                               if (clave != nodo_Binario->datos->clave)
                               {
                               resultado = a_ej3_clavepadre(arbol, clave);
                                   if (resultado != -2){ //cambio a -2 antes era 0
                                       printf("Clave del padre: %d\n", resultado);
                                   }else printf("No se encuentra el elemento en el arbol.\n");
                               }else printf("La clave ingresada es la Raiz del arbol, no tiene padre.\n"); 
                           }
                           break;
                       case 2:
                           if (a_es_vacio(arbol))
                           {
                               printf("El arbol esta vacio.\n");
                           }else{
                                clave = validarentradaentero_arboles("Ingrese una clave del padre a buscar los hijos: ");
                                lista_resultado = a_ej3_hijos(arbol, clave);
                                if (!l_es_vacia(lista_resultado))
                                {
                                    printf("Hijos del padre dado:\n");
                                    l_mostrar(lista_resultado);
                                }else printf("No tiene hijos.\n");
                            }
                            break;
                        case 3:
                            if (a_es_vacio(arbol))
                            {
                                printf("El arbol esta vacio.\n");
                            }else{
                                clave = validarentradaentero_arboles("Ingrese clave para buacar sus hermanos: ");
                                resultado = a_ej3_hermano(arbol, clave);
                                nodo_Binario = a_raiz(arbol);
                                if (nodo_Binario->datos->clave != clave)
                                {
                                        if (resultado == -1)
                                    {
                                        printf("No tiene hermanos.\n");
                                    }else if (resultado == -2)
                                    {
                                        printf("No se encuentra la clave en el arbol.\n");
                                    }else printf("Hermano de la clave %d: %d\n", clave, resultado);
                                }else printf("La clave ingresada es la Raiz del arbol, no tiene padre.\n"); 
                                
                                
                               
                            }
                            break;
                        case 4:
                            if (a_es_vacio(arbol))
                            {
                                printf("El arbol esta vacio.\n");
                            }else{
                                clave = validarentradaentero_arboles("Ingrese el nodo a buscar:");
                                resultado = a_ej3_nivel(arbol, clave);
                                if (resultado != -1)
                                {
                                    printf("Nivel del nodo con clave %d: %d\n", clave, resultado);
                                }else printf("La clave no se encuentra en el arbol.\n");
                            }
                            break;
                        case 5:
                            if (a_es_vacio(arbol))
                            {
                                printf("El arbol esta vacio.\n");
                            }else{
                            clave = validarentradaentero_arboles("Ingrese Nodo a buscar altura: ");
                            resultado = a_ej3_alturarama(arbol, clave);
                            if(resultado < 0){
                                printf("La clave no existe en el arbol.\n");
                            }else printf("Altura de la rama de la clave %d: %d\n", clave, resultado);
                            }
                            break;
                        case 6:
                            if (a_es_vacio(arbol))
                            {
                                printf("El arbol esta vacio.\n");
                            }else{
                            nivel = validarentradaentero_arboles("Ingrese el nivel a buscar nodos: ");
                            while (nivel < 0)
                            {
                                nivel = validarentradaentero_arboles("Error el nivel no puede ser menor a 0. Ingrese el nivel a buscar nodos: ");
                            }
                            
                            lista_resultado = a_ej3_clavesmismonivel(arbol, nivel);
                            if (!l_es_vacia(lista_resultado))
                            {
                                printf("Claves en el nivel %d:\n", nivel);
                                l_mostrar(lista_resultado);
                            }else printf("El nivel ingresado es mayor al nivel del arbol.\n");
                            }
                            break;
                        default:
                            printf("Opcion invalida.\n");
                }
                    if (!l_es_vacia(lista_resultado))
                    {
                        l_vaciar(lista_resultado);
                    }
                    ejercicio = validarsalida();
                } while (ejercicio != -1);                                
                break;
        case 4:
            printf("\nEjercicio 4\n");
            printf("\nCargar Arbol Binario \n");
            cargar_arbol_binario(arbol);
            do
            {
            printf("\nEjercicio 4\n");
            printf("1) a) Anchura del arbol.\n");
            printf("2) b) Cantidad de hojas.\n");
            printf("3) c) Determinas si es misma estructura.\n");
            printf("4) d) Buscar padre del nodo.\n");
            printf("5) e) Buscar hermanos del nodo.\n");
            subopcion = validarentradaentero_arboles("Ingresa una opcion (1 - 5): ");                    

            switch (subopcion) {
            case 1:
                if (a_es_vacio(arbol))
                {
                    printf("El arbol esta vacio.\n");
                }else{
                    lista_resultado = a_ej4_anchura(arbol);
                    printf("Liasta con los elementos recorridos en anchura: \n");
                            ite = iterador(lista_resultado);
                            while (hay_siguiente(ite)) {
                                TipoElemento te = siguiente(ite);
                                NodoArbol nodo_aux = (NodoArbol)te->valor;
                                TipoElemento te_aux = n_recuperar(nodo_aux);
                                printf("Clave: %d\n",te_aux->clave);
                            }
                        }
                        break;
                    case 2:
                        if (a_es_vacio(arbol))
                        {
                            printf("El arbol esta vacio.\n");
                        }else{
                            resultado =  a_ej4_q_hojas(arbol);
                            if (resultado == 0)
                            {
                                printf("No tiene Hojas.\n");
                            }else printf("La cantidad de hojas es: %d\n", resultado);
                        }
                        break;
                    case 3:
                        cargar_arbol_binario(arbol_dos);
                        if (a_ej4_similares(arbol, arbol_dos))
                        {
                            printf("Son arboles similares (Tienen la misma estructura).\n");
                        }else printf("Son arboles diferentes.\n");
                        
                        break;
                    case 4:
                        if (a_es_vacio(arbol))
                        {
                            printf("El arbol esta vacio.\n");
                        }else{
                            clave = validarentradaentero_arboles("Ingrese el nodo a buscar el padre:");
                            te = a_ej4_padre(arbol, clave);
                            nodo_Binario = a_raiz(arbol);
                            if (nodo_Binario->datos->clave == clave)
                            {
                                printf("La clave ingresada no tiene padre, es la raiz.\n");
                            }
                            else if(te == NULL){
                                printf("La clave ingresada no existe en el arbol.\n");
                            }else{
                                nodo_Binario = (NodoArbol)te->valor;
                                te_aux = n_recuperar(nodo_Binario);
                                printf("El padre es: %d\n",te_aux->clave);
                            }
                        }
                        
                        break;
                    case 5:
                        clave = validarentradaentero_arboles("Ingrese el nodo a buscar Hermanos:");
                        if (!a_es_vacio(arbol))
                        {
                            if (!l_es_vacia(lista_resultado))
                            {
                                printf("Los hermanos de %d son: ", clave);
                                l_mostrar(lista_resultado);
                            }else printf("No contiene hermanos o no se encuentra la clave en el arbol.\n");
                        
                        }else printf("El arbol esta vacio.\n");
                        break;
                    default:
                        printf("Opcion invalida.\n");
                }
                    if (!l_es_vacia(lista_resultado))
                    {
                        l_vaciar(lista_resultado);
                    }
                    ejercicio = validarsalida();
                    } while (ejercicio != -1); 
                break;
        case 7:
            printf("\nEjercicio 7\n");
            printf("Determinar si dos arboles binarios son equivalentes.\n");
            printf("\nCargar Arbol Binario \n");
            cargar_arbol_binario(arbol);
            
            printf("\nCargar segundo Arbol Binario \n");
            cargar_arbol_binario(arbol_dos);         
            if (a_ej7_equivalente(arbol, arbol_dos))
            {
                printf("Son arboles equivalentes.\n");
            }else printf("Son arboles distintos.\n");
            
            break; 
                    
        case 8:
            printf("\nEjercicio 8\n");
            printf("\nCargar Arbol N-ario transformado\n");
            cargar_arbol_binario(arbol);
            do
            {
            printf("\nEjercicio 4\n");
            printf("1) a) Determinar la altura.\n");
            printf("2) b) Determinar el nivel de un nodo.\n");
            printf("3) c) Listar todos los nodos internos.\n");
            printf("4) d) Determinar si todas las hojas estan al mismo nivel.\n");
            subopcion = validarentradaentero_arboles("Ingresa una opcion (1 - 4): ");                    

            switch (subopcion) {
                case 1:
                    if (a_es_vacio(arbol))
                    {
                        printf("El arbol esta vacio\n");
                    }else {
                        resultado = a_ej8_altura(arbol);
                        printf("La altura es %d.\n",resultado);
                    }
                    break;
                case 2:
                    clave = validarentradaentero_arboles("Ingresa el nodo a buscar nivel: ");
                    resultado = a_ej8_nivel(arbol, clave);
                    if (a_es_vacio(arbol))
                    {
                        printf("El arbol esta vacio\n");
                    }
                    else if (resultado == -1)
                    {
                        printf("El elemento no se encuentra en el arbol\n");
                    }else printf("La altura es %d.\n",resultado);
                    break;
                case 3:
                if (a_es_vacio(arbol))
                    {
                        printf("El arbol esta vacio\n");
                    }else {
                        lista_resultado = a_ej8_internos(arbol);
                        if (l_es_vacia(lista_resultado))
                        {
                            printf("No hay nodos internos.\n");
                        }else {printf("Los nodos internos son: \n");
                            l_mostrar(lista_resultado);
                        }
                    }
                    break;
                case 4:
                    if (a_es_vacio(arbol))
                    {
                        printf("El arbol esta vacio\n");
                    }
                    else if (a_ej8_hojasmismonivel(arbol))
                    {
                        printf("Las hojas estan al mismo nivel\n");
                    }else printf("Las hojas estan a distinto nivel\n");
                    break;
                default:
                    printf("Opcion invalida.\n");
            }
                if (!l_es_vacia(lista_resultado))
                {
                    l_vaciar(lista_resultado);
                }
                ejercicio = validarsalida();
                } while (ejercicio != -1); 
                break;
        case 9:
            printf("\nEjercicio 9\n");
            printf("Construir un arbol binario de busqueda balanceado (AVL).\n");
            printf("\nCargar Arbol Binario \n");
            cargar_arbol_binario(arbol);
            if (a_es_vacio(arbol))
            {
                printf("El arbol esta vacio\n");
                printf("La diferencia de altura es 0\n");
            }else {
                arbol_AVL = a_ej9_construiravl(arbol);
                resultado = a_ej9_diferenciaalturas(arbol, arbol_AVL);
                printf("La diferencia de altura es %d.\n", resultado);
            }
            printf("La complejidad total del Ejercicio 9 es O(n log n), por la construccion del arbol AVL.\n");
            break;

        case 10:
            printf("\nEjercicio 10\n");
            printf("Cargar la misma serie en un arbol binario de busqueda y en un arbol binario balanceado “AVL”.\n");
            cantidadclavesagenerar = validarentradaentero_arboles("Cantidad de claves a generar: ");
        
            while ((cantidadclavesagenerar > 10 || cantidadclavesagenerar < 1) && (cantidadclavesagenerar != 0))
            {
                cantidadclavesagenerar = validarentradaentero_arboles("Error debe ingresar hasta un maximo de 10 claves: ");
            }
            if (cantidadclavesagenerar == 0)
            {
                printf("Los arboles estan vacios");
                break;
            }
            
            valorminimo = validarentradaentero_arboles("Ingrese un valor minimo del conjunto: ");
            valormaximo = validarentradaentero_arboles("Ingrese un valor maximo del conjunto: ");
            //Corroboramos el intervalo para la cantidad de claves
            while ((valormaximo - valorminimo) < cantidadclavesagenerar)
            {

                printf("Error. tamano del conjunto debe ser mayor a la cantidad de claves.\n");
                valorminimo = validarentradaentero_arboles("Ingrese un valor minimo del conjunto: ");
                valormaximo = validarentradaentero_arboles("Ingrese un valor maximo del conjunto: ");
            }
            N_repeticiones = validarentradaentero_arboles("Ingrese la cantidad de repeticiones a hacer: ");
            while (N_repeticiones < 0)
            {
                printf("No puede ser cantidad negativa.\n");
                N_repeticiones = validarentradaentero_arboles("Ingrese la cantidad de repeticiones a hacer: ");
            }
            lista_resultado = a_ej10_comparacionarboles(N_repeticiones, valorminimo, valormaximo, cantidadclavesagenerar);
            if (l_es_vacia(lista_resultado))
            {
                printf("Los arboles estan vacios.\n");
            }else {
                printf("Las diferencias de altura son: \n");
                l_mostrar(lista_resultado);
            }
            
            break;
        default:
            printf("Ejercicio no valido. Solo se permiten 2 o 10.\n");
        }
        printf("\nQuiere probar otro tipo de ejercicio?\n");
        ejercicio = validarsalida();

    } while (ejercicio != -1);

    printf("Programa finalizado.\n");
    return 0;
}
