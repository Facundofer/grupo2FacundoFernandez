#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "..\libs\listas\headers\listas.h"
#include "tp_2_listas_1.h"
#include "..\libs\validaciones\headers\validaciones.h"



void main(){
    int valor = 0;
    int ejercicio, tamano, tamano2;
    bool boleano;
    float prom;
    double x, y, sumando;
    ResultadoValorMinimo Minimo;
    ResultadosMul Multiplo;
    Lista lista1, lista2, aux;
    TipoElemento te;
    Iterador ite;
    lista1 = l_crear();
    lista2 = l_crear();
    aux = l_crear();        
    while (valor != -1)
    {   printf("Que ejercicio desea probar del 2 al 6.\n");
        ejercicio = validarentradaentero();
        switch (ejercicio)
        {
            case 2:
                tamano = validartamanolist();
                lista1 = rellenarLista(tamano);
                printf("Lista 1 cargada, cargar lista 2.\n");
                tamano = validartamanolist();
                lista2 = rellenarLista(tamano);
                printf("a) Vlores No repetido Lista 1 en Lista 2: \t");
                aux = verElementosQueNoSeRepiten(lista1, lista2);
                if (l_es_vacia(aux))
                {
                    printf("Se repiten todos los valores.\n");
                }else l_mostrar(aux);
                
                l_vaciar(aux);
                aux = verElementosQueNoSeRepiten(lista2, lista1);
                printf("b) Vlores No repetido Lista 2 en Lista 1: \t");
                if (l_es_vacia(aux))
                {
                    printf("Se repiten todos los valores.\n");
                }else l_mostrar(aux);
                
                l_vaciar(aux);
                printf("c) Valores repetidos en ambas listas: \t");
                aux = verElementosRepetidos(lista1, lista2);
                if (l_es_vacia(aux))
                {
                    printf("No se repiten los valores.\n");
                }else l_mostrar(aux);
                printf("d) Promedios ambas listas: \t");
                prom = promedio(lista1);
                printf("Promedio Lista 1: %f\n", prom); 
                prom = promedio(lista2);
                printf("\t\t\t\tPromedio Lista 2: %f\n", prom);
                printf("e) Valor Minimo en ambas listas y su posicion: \t");
                Minimo = valorMinimo(lista1, lista2);
                printf("Minimo Lista 1: %d en la posicion: %d\n", Minimo.valor, Minimo.pos);
                printf("\t\t\t\t\tMinimo Lista 2: %d en la posicion: %d\n", Minimo.valor_2, Minimo.pos_2);
                l_vaciar(aux);
                l_vaciar(lista1);
                l_vaciar(lista2);
                break;
            case 3:
                tamano = validartamanolist();
                lista1 = rellenarLista(tamano);
                while (l_buscar(lista1, 0) != NULL)
                {
                    printf("Opcion invalida. La lista no puede incluir 0.");
                    tamano = validartamanolist();
                    lista1 = rellenarLista(tamano);
                }
                printf("Lista 1 cargada, cargar lista 2.\n");
                tamano = validartamanolist();
                lista2 = rellenarLista(tamano);
                Multiplo = multiplo(lista1, lista2);
                if (Multiplo.esMultiplo)
                {
                    printf("Lista 2 es multiplo de Lista 1.\n");
                }else if (Multiplo.escalar)
                {
                    printf("Es multiplo por un escalar el cual es: %d\n", Multiplo.numEscalar);
                }else printf("Lista 2 No es multiplo de Lista 1.\n");
                l_vaciar(lista1);
                l_vaciar(lista2);
                break;
            case 4:
                tamano = validartamanolist();
                printf("Tamano Lista 1 ingresado.\n");
                tamano2 = validartamanolist();
                while (tamano != tamano2)
                {
                    printf("Tamanos incorrectos. Deben ser iguales.\n");
                    tamano = validartamanolist();
                    printf("Tamano Lista 1 ingresado.\n");
                    tamano2 = validartamanolist();
                }
                printf("Cargar Lista 1: \n");
                lista1 = rellenarLista(tamano);
                printf("Cargar Lista 2: \n");
                lista2 = rellenarLista(tamano2);
                valor = CompararListas(lista1, lista2);
                switch (valor)
                {
                case 0:
                    printf("Las Listas son iguales.\n");
                    break;
                
                case 1:
                    printf("La Listas 1 es mayor a Lista 2.\n");
                    break;
                case 2:
                    printf("La Listas 1 es menor a Lista 2.\n");
                    break;
                l_vaciar(lista1);
                l_vaciar(lista2);
                break;
                }
                printf("La complejidad algoritmica en este ejercicio es o(n) siendo n el tamano de la lista al ser del mismo tamano las dos listas se recorren de forma lineal y completa ya que las estoy comparando item a item.\n");
                break;
            case 5:
                    lista1 = l_crear();
                    lista2 = l_crear();
                    printf("Ingresar el primer extremo del intervalo.\n");
                    x = validarReales();
                    printf("Ingresar el segundo extremo del intervalo.\n");
                    y = validarReales();
                    printf("Ingresar valor de salto entre los valores.\n");
                    sumando = validarReales();
                    while (sumando < 0)
                    {
                        printf("Opcion invalida el salto no puede ser negativo.");
                        sumando = validarReales();
                    }
                    hacerPolinomio(lista1);
                    lista2 = calcularRango(lista1,  x,  y, sumando);
                    ite = iterador(lista2);
                    printf("Los valores del polinomio en los puntos son: \n");
                    while (hay_siguiente(ite))
                    {   
                        te = siguiente(ite);
                        prom = *((float*)te->valor);
                        printf("%f\t", prom);
                    }
                    printf("\n");
                break;
            case 6:
                tamano = validartamanolist();
                lista1 = rellenarLista(tamano);
                printf("Lista 1 cargada, cargar lista 2.\n");
                tamano = validartamanolist();
                lista2 = rellenarLista(tamano);
                if (esSublista(lista1, lista2))
                {
                    printf("La Lista 2 es sublista de Lista 1.\n");
                }else printf("La Lista 2 No es sublista de Lista 1.\n");
                l_vaciar(lista1);
                l_vaciar(lista2);
                printf("La complejidad algoritmica de esta funcion empleada es o(m * n) siendo m el largo de la segunda lista y n el largo de la primera lista.\n");
                printf("Es esta complejidad ya que en el peor caso va a recorrer la segunda lista la cantidad de elementos que tiene la primera lista comprobando que todos se encuentren en la otra lista.\n");
                break;
            default:
                printf("Error, debe elegir un valor entre 2 y 6.\n");
            break;    
        }
        valor = validarsalida();
    }
    
    system("pause");
}


