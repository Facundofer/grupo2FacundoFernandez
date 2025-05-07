#include "..\libs\colas\headers\colas.h"
#include "..\libs\pilas\headers\pilas.h"
#include "..\libs\listas\headers\listas.h"
#include "..\libs\validaciones\headers\validaciones.h"
#include "tp_4_colas.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main(){
    Cola solucion = c_crear();
    Cola cola1 = c_crear();
    Cola cola2 = c_crear();
    Cola cola3 = c_crear();
    Lista lista = l_crear();
    Pila pila = p_crear();
    Iterador ite;
    TipoElemento te;
    bool boleano;
    int entrada = 0;
    int ejercicio, resultado, claveBuscar, posicionordinal, elementoagregar, tiempodecola;
    while (entrada != -1)
    {
        printf("Que ejercicio quiere probar entre 2 y 7.\n");
        ejercicio = validarentradaentero();
        switch (ejercicio)
        {
        case 2:
            vaciarcola(cola1);
            printf("cargando cola1\n");
            c_cargar(cola1);
            while (entrada != -1)
                {
                printf("Que ejercicio quiere probar del 1 =a al 6 =f. \n");    
                ejercicio = validarentradaentero();
                switch (ejercicio)
                {
                case 1:
                    printf("a)\n");
                    printf("Que clave desea buscar?\n");
                    claveBuscar = validarentradaentero();
                    if (c_ej2_existeclave(cola1, claveBuscar))
                    {
                        printf("El elemento esta en la cola\n");
                    }else printf("El elemento NO esta en la cola.\n");
                    
                    break;
                
                case 2:
                    printf("b)\n");
                    printf("En que posicion desea agregar el elemento?\n");
                    posicionordinal = validarentradaentero();
                    printf("Que elemento desea agregar?\n");
                    elementoagregar = validarentradaentero();
                    te = te_crear(elementoagregar);
                    solucion = c_ej2_colarelemento(cola1, posicionordinal, te);
                    printf("Cola solucion\n");
                    c_mostrar(solucion);
                    vaciarcola(solucion);
                    break;
            
                case 3:
                    printf("c)\n");
                    printf("Que clave deseas eliminar?\n");
                    claveBuscar = validarentradaentero();
                    solucion = c_ej2_sacarelemento(cola1, claveBuscar);
                    printf("Cola solucion\n");
                    c_mostrar(solucion);                    
                    vaciarcola(solucion);
                    break;
                
                case 4:
                    printf("d)\n");
                    resultado = c_ej2_contarelementos(cola1);
                    printf("La cola tiene %d elementos.\n", resultado);
                    break;
                    
                case 5:
                    printf("e)\n");
                    solucion = c_ej2_copiar(cola1);
                    printf("Cola solucion\n");
                    c_mostrar(solucion);                    
                    vaciarcola(solucion);
                    break;  
                case 6:
                    printf("f)\n");
                    solucion = c_ej2_invertir(cola1);
                    printf("Cola solucion\n");
                    c_mostrar(solucion);                    
                    vaciarcola(solucion);
                    break;
                
                default: 
                    printf("debe eleguir un valor entre 1 y 6.\n");
                break;
                }
                printf("Quiere seguir probando otro punto del 2?\n");   
                entrada = validarsalida();
                
            }
            break;
        
        case 3:
            vaciarcola(cola1);
            printf("cargando cola1\n");
            c_cargar(cola1);
            printf("cargando cola2\n");
            c_cargar(cola2);
            if (c_ej3_iguales(cola1, cola2))
            {
                printf("Son iguales.\n");
            }else printf("Son distintas.\n");
            vaciarcola(cola1);
            vaciarcola(cola2);
            break;
    
        case 4:
            printf("cargando cola1\n");
            c_cargar(cola1);
            solucion = c_ej4_colanorepetidos(cola1);
            c_mostrar(solucion);
            vaciarcola(cola1);
            vaciarcola(solucion);
            break;
        
        case 5:
            printf("cargando cola1\n");
            c_cargar(cola1);
            solucion = c_ej5_divisortotal(cola1);
            if(c_es_vacia(solucion)){
                printf("COLA VACIA\n");
            }else{
                while(!c_es_vacia(solucion)){
                    te = c_desencolar(solucion);
                    boleano = (*(bool*)te->valor);
                    if(boleano == true){
                        printf("Valor Total %d\n", te->clave); 
                    }else{
                        printf("Valor/es Parciales %d\n", te->clave); 
                    }
                }
            }
            vaciarcola(cola1);
            break;
            
        case 6:
            printf("cargando cola1\n");
            c_cargar(cola1);
            printf("Cuantos elementos quiere en la pila.\n");
            elementoagregar = validarentradaentero();
            pila = cargarpila(elementoagregar);
            lista = c_ej6_comunesapilaycola(pila, cola1);
            ite = iterador(lista);
            while (hay_siguiente(ite)) {
                te = siguiente(ite);
                char *charresul = (char*)te->valor;
                printf("%s\n", charresul);
            }
            vaciarcola(cola1);
            vaciarpila(pila);
            break;  
        case 7:
            printf("cargando cola1\n");
            c_cargar(cola1);
            printf("cargando cola2\n");
            c_cargar(cola2);
            printf("cargando cola3\n");
            c_cargar(cola3);
            tiempodecola = validarentradaentero();
            while (tiempodecola <= 0)
            {
                printf("Error el tiempo no puede ser menor igual a 0.\n");
                tiempodecola = validarentradaentero();
            }
            solucion = c_ej7_atenderclientes(cola1, cola2, cola3, tiempodecola);
            while(!c_es_vacia(solucion)){
                te = c_desencolar(solucion);
                char *charresul = (char*)te->valor;
                printf("%s\n", charresul); 
            }
            vaciarcola(cola1);
            vaciarcola(cola2);
            vaciarcola(cola3);
            vaciarcola(solucion);
            break;
            
        default:
            printf("Debe poner una opcion correcta entre 2 y 7.\n");
            break;
    
        }
        printf("Quiere seguir probando otro ejercicio del 2 al 8?\n");
        entrada = validarsalida();
    }
    system("pause");
    return 0;
}
