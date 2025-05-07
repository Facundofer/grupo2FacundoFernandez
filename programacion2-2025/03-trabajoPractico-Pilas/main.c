#include <stdio.h>
#include <stdlib.h>
#include "tp_3_pilas.h"
#include "..\libs\pilas\headers\pilas.h"
#include "..\libs\tipoElemento\headers\tipo_elemento.h"
#include "..\libs\validaciones\headers\validaciones.h"
#define MAX 10
void main(){
TipoElemento te;
int entrada = 0;
int ejercicio, enteroresul, tamanopila1, tamanopila2, enteroaux1, enteroaux2;
bool boleano;
char *charresultado;
Pila pila1, pila2, pilaresultado;
pila1 = p_crear();
pila2 = p_crear();
pilaresultado = p_crear();

while (entrada != -1)
{
    printf("Que ejercicio desea probar entre 2 y 8.");
    ejercicio = validarentradaentero();
    switch (ejercicio)
    {
    case 2:
        printf("A) \n");
        tamanopila1 = validartamanopila();
        if (tamanopila1 != 0)
        {
            pila1 = cargarpila(tamanopila1);
        }
        tamanopila2 = validartamanopila();
        if (tamanopila2 != 0)
        {
            pila2 = cargarpila(tamanopila2);
        }
        printf("Ingresando el valor a buscar en las pilas.\n");
        enteroresul = validarentradaentero();
        if (p_ej2_existeclave(pila1, enteroresul))
        {
            printf("El valor esta en la Pila 1.\n");
        }else printf("El valor no esta en la Pila 1.\n");
        
        if (p_ej2_existeclave(pila2, enteroresul))
        {
            printf("El valor esta en la Pila 2.\n");
        }else printf("El valor no esta en la Pila 2.\n");
        printf("Pila 1 original: \t");
        p_mostrar(pila1);
        printf("Pila 2 original: \t");
        p_mostrar(pila2);
        printf("\n");

        printf("B) \n");
        printf("Ingrese el valor a ingresar.\n ");
        enteroresul = validarentradaentero();
        te = te_crear(enteroresul);
        printf("Ingrese la posicion a agregarlo.\n ");
        enteroaux1 = validarentradaentero();
        pilaresultado = p_ej2_colocarelemento(pila1, enteroaux1, te);
        printf("Agregar elemento pila 1: \t");
        p_mostrar(pilaresultado);
        vaciarpila(pilaresultado);
        pilaresultado = p_ej2_colocarelemento(pila2, enteroaux1, te);
        printf("Agregar elemento pila 2: \t");
        p_mostrar(pilaresultado);
        printf("Pila 1 original: \t");
        p_mostrar(pila1);
        printf("Pila 2 original: \t");
        p_mostrar(pila2);
        printf("\n");

        printf("c) \n");
        printf("Ingrese la clave a eliminar.\n ");
        enteroaux1 = validarentradaentero();
        pilaresultado = p_ej2_eliminarclave(pila1, enteroaux1);
        printf("Pila 1 sin la clave: \t");
        p_mostrar(pilaresultado);
        vaciarpila(pilaresultado);
        pilaresultado = p_ej2_eliminarclave(pila1, enteroaux1);
        printf("Pila 2 sin la clave: \t");
        p_mostrar(pilaresultado);
        vaciarpila(pilaresultado);
        printf("Pila 1 original: \t");
        p_mostrar(pila1);
        printf("Pila 2 original: \t");
        p_mostrar(pila2);
        printf("\n");

        printf("D) \n");
        printf("Ingresando la posicion 1 a cambiar.\n");
        enteroaux1 = validarentradaentero();
        if (enteroaux1 > tamanopila2 || enteroaux1 < 0 )
        {
            while (enteroaux1 > tamanopila2 || enteroaux1 < 0 )
            {
                printf("El tamano de la pila2 es %d debe eleguir una posicion mas chica pero no menor a 0.\n", tamanopila2);
                enteroaux1 = validarentradaentero();
            }
        }
        if (enteroaux1 > tamanopila1 || enteroaux1 < 0 )
        {
            while (enteroaux1 > tamanopila1 || enteroaux1 < 0 )
            {
                printf("El tamano de la pila1 es %d debe eleguir una posicion mas chica pero no menor a 0.\n", tamanopila2);
                enteroaux1 = validarentradaentero();
            }
        }
        printf("Ingresando la posicion 2 a cambiar.\n");
        enteroaux2 = validarentradaentero();
        if (enteroaux2 > tamanopila2 || enteroaux2 < 0 )
        {
            while (enteroaux2 > tamanopila2 || enteroaux2 < 0 )
            {
                printf("El tamano de la pila2 es %d debe eleguir una posicion mas chica pero no menor a 0.\n", tamanopila2);
                enteroaux2 = validarentradaentero();
            }
        }
        if (enteroaux2 > tamanopila1 || enteroaux2 < 0 )
        {
            while (enteroaux2 > tamanopila1 || enteroaux2 < 0 )
            {
                printf("El tamano de la pila1 es %d debe eleguir una posicion mas chica pero no menor a 0.\n", tamanopila2);
                enteroaux2 = validarentradaentero();
            }
        }
        pilaresultado = p_ej2_intercambiarposiciones(pila1, enteroaux1, enteroaux2);
        printf("Elementos intercambiados de la pila 1: \t");
        p_mostrar(pilaresultado);
        vaciarpila(pilaresultado);
        pilaresultado = p_ej2_intercambiarposiciones(pila2, enteroaux1, enteroaux2);
        printf("Elementos intercambiados de la pila 2: \t");
        p_mostrar(pilaresultado);
        vaciarpila(pilaresultado);
        printf("Pila 1 original: \t");
        p_mostrar(pila1);
        printf("Pila 2 original: \t");
        p_mostrar(pila2);
        printf("\n");

        printf("E) \n");
        pilaresultado = p_ej2_duplicar(pila1);
        printf("Pila 1 duplicada: \t");
        p_mostrar(pilaresultado);
        vaciarpila(pilaresultado);
        pilaresultado = p_ej2_duplicar(pila2);
        printf("Pila 2 duplicada: \t");
        p_mostrar(pilaresultado);
        vaciarpila(pilaresultado);
        printf("Pila 1 original: \t");
        p_mostrar(pila1);
        printf("Pila 2 original: \t");
        p_mostrar(pila2);
        printf("\n");
        
        printf("F) \n");
        enteroaux1 = p_ej2_cantidadelementos(pila1);
        enteroaux2 = p_ej2_cantidadelementos(pila1);
        printf("La pila 1 tiene %d elementos, y la Pila 2 tiene %d elementos.\n", enteroaux1, enteroaux2);
        printf("Pila 1 original: \t");
        p_mostrar(pila1);
        printf("Pila 2 original: \t");
        p_mostrar(pila2);
        printf("\n");
        break;
    
    case 3:
        tamanopila1 = validartamanopila();
        tamanopila2 = validartamanopila();
        while (tamanopila1 != tamanopila2)
        {
            printf("El tamano de las pilas debe ser el mismo.\n");
            tamanopila1 = validartamanopila();
            tamanopila2 = validartamanopila();
        }
        if (tamanopila1 != 0)
        {
            pila1 = cargarpila(tamanopila1);
            pila2 = cargarpila(tamanopila2);
        }
        if (p_ej3_iguales(pila1, pila2))
        {
            printf("Las pilas son iguales\n");
        }else printf("Las pilas son distintas\n");
        printf("Pila 1 original: \t");
        p_mostrar(pila1);
        printf("Pila 2 original: \t");
        p_mostrar(pila2);
        printf("La complejidad algoritmica utilizada es: O(n), donde n es la cantidad de elementos de las pilas.");
        vaciarpila(pila1);
        vaciarpila(pila2);
        break;

    case 4:
        charresultado = (char*)malloc(sizeof(char)*MAX);
        printf("Ingresando un numero decimal.\n");
        enteroaux1 = validarentradaentero();
        printf("Ingresando la base:\n");
        enteroaux2 = validarentradaentero();
        while (enteroaux2 < 2 || enteroaux2 > 16)
        {
            printf("La base debe ser un valor entre 2 a 16.\n");
            enteroaux2 = validarentradaentero();
        }
        charresultado = p_ej4_cambiarbase(enteroaux1, enteroaux2);
        printf("%s\n", charresultado);
        printf("La complejidad algoritmica utilizada es: O(log nrobasedecimal)");
        break;
    
    case 5:
        tamanopila1 = validartamanopila();
        if (tamanopila1 != 0)
        {
            pila1 = cargarpila(tamanopila1);
        }
        pilaresultado = p_ej5_invertir(pila1);
        printf("Pila 1 original: \t");
        p_mostrar(pila1);
        printf("Pila resultado: \t");
        p_mostrar(pilaresultado);
        vaciarpila(pila1);
        vaciarpila(pilaresultado);
        printf("La complejidad algoritmica utilizada es: O(n)");
        break;
        
    case 6:
        printf("Ingresando el valor a eliminar. \n");
        enteroaux1 = validarentradaentero();
        tamanopila1 = validartamanopila();
        if (tamanopila1 != 0)
        {
            pila1 = cargarpila(tamanopila1);
        }
        pilaresultado = p_ej6_eliminarclave(pila1, enteroaux1);
        printf("Caso iterativo: \t");
        p_mostrar(pilaresultado);    
        vaciarpila(pilaresultado);
        pilaresultado = p_ej6_eliminarclave_r(pila1, enteroaux1);
        printf("Caso recursivo: \t");
        p_mostrar(pilaresultado); 
        printf("Pila 1 original: \t");
        p_mostrar(pila1);   
        printf("La complejidad algoritmica utilizada en caso iterativo es: O(n)");
        printf("La complejidad algoritmica utilizada en caso recursivo es: O(n)");
        vaciarpila(pilaresultado);
        vaciarpila(pila1);    
        break;  
    case 7:
        tamanopila1 = validartamanopila();
        if (tamanopila1 != 0)
        {
            pila1 = cargarpila(tamanopila1);
        }
        
        pila1 = cargarpila(tamanopila1);
        tamanopila2 = validartamanopila();
        if (tamanopila2 != 0)
        {
            pila2 = cargarpila(tamanopila2);
        } 
        pilaresultado = p_ej7_elementoscomunes(pila1, pila2);
        printf("Pila 1 original: \t");
        p_mostrar(pila1);
        printf("Pila 2 original: \t");
        p_mostrar(pila2);
        printf("Pila resultado: \t");
        p_mostrar(pilaresultado);
        printf("La complejidad algoritmica utilizada es: O(n*m)");
        vaciarpila(pila1);
        vaciarpila(pila2);
        vaciarpila(pilaresultado);
        break;
        
    case 8:
        tamanopila1 = validartamanopila();
        if (tamanopila1 != 0)
        {
            pila1 = cargarpila(tamanopila1);
        }
        pilaresultado =  p_ej8_sacarrepetidos(pila1);
        printf("Pila 1 original: \t");
        p_mostrar(pila1);
        printf("Pila con los resultados: \n");
        while (!p_es_vacia(pilaresultado)) {
            te = p_desapilar(pilaresultado);
            enteroaux1 = *((int*)te->valor);
            printf("Clave: %d, Cantidad: %d\n", te->clave, enteroaux1);
        }
        break;
        printf("La complejidad algoritmica utilizada es: O(n elevado 2)");
    default:
        printf("Error, debe elegir un valor entre 2 y 8.\n");
    break;
    }
    entrada = validarsalida();
}
system("pause");
return;
}