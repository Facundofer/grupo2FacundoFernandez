#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "tp_conjunto.h"
#include "..\libs\validaciones\headers\validaciones.h"
#include "..\libs\conjuntos\headers\conjuntos.h"

void main(){
    int ejercicio, clave, salida = 0;
    int continuacion = 0;
    Conjunto A = cto_crear();
    Conjunto B = cto_crear();
    Conjunto C = cto_crear();
    Lista coleccion = l_crear();
    while (continuacion != -1)
    {
        ejercicio = validarentradaentero_arboles("Ingrese el ejercicio a probar (2-8): ");
        switch (ejercicio)
        {
        case 2:
            printf("\n\n");
            printf("CARGA DEL 1er CONJUNTO: \n");
            cargar_conjunto(A);
            printf("\n\n");
            printf("CARGA DEL 2do CONJUNTO: \n");
            cargar_conjunto(B);
            printf("\n\n");
            printf("Primer conjunto: \t");
            cto_mostrar(A);
            printf("\n\n");
            printf("Segundo conjunto: \t");
            cto_mostrar(B);
            printf("\n\n");

            printf("1. UNION: \t");
            C = c_ej2_union(A, B);
            if(cto_es_vacio(C)){
                printf("Los conjuntos estan vacios. ");
                cto_mostrar(C);
            }else{
                cto_mostrar(C);
            }
            printf("\n\n");
            
            vaciar_conjunto(C);

            printf("2. INTERSECCION: \t");
            C = c_ej2_interseccion(A, B);
            if(cto_es_vacio(C)){
                printf("No hay elementos pertenecientes a ambos conjuntos.\n");
            }else{
                cto_mostrar(C);
            }
            printf("\n\n");

            vaciar_conjunto(C);
        
            printf("3. DIFERENCIA ENTRE A-B: ");
            C = c_ej2_diferencia(A, B);
            if(cto_es_vacio(C) && !cto_es_vacio(A)){
                printf("Todos los elementos se encuentran en el segundo.\n");
            }else if(cto_es_vacio(A))
            {
                printf("El primer conjunto esta vacio.\n");
            }
            else{
                cto_mostrar(C);
            }
            printf("\n\n");
        
            vaciar_conjunto(C);

            printf("4. DIFERENCIA ENTRE B-A: ");
            C = c_ej2_diferencia(B, A);
            if(cto_es_vacio(C) && !cto_es_vacio(B)){
                printf("Todos los elementos se encuentran en el segundo.\n");
            }else if(cto_es_vacio(B))
            {
                printf("El segundo conjunto esta vacio.\n");
            }
            else{
                cto_mostrar(C);
            }
            printf("\n\n");
        
            vaciar_conjunto(C); 

            do{
                clave = validarentradaentero_arboles("Ingrese la clave a buscar: ");
                printf("5. PERTENENCIA %d - > A: ", clave);
                if(c_ej2_pertenencia(A, clave)){
                    printf("SI PERTENECE.\n");
                }else{
                    printf("NO PERTENECE.\n");
                }
            
                printf("PERTENENCIA %d -> B: ", clave);
                if(c_ej2_pertenencia(B, clave)){
                    printf("SI PERTENECE.\n");
                }else{
                    printf("NO PERTENECE.\n");
                }
                printf("¿Quiere buscar otra clave?\n");
                salida = validarsalida();
            }while(salida != -1);

            vaciar_conjunto(A);
            vaciar_conjunto(B);
            break;
        case 3:
            printf("A continuacion cargue los conjuntos...\n");
            coleccion_conjuntos(coleccion);
            mostrar_con_valor(coleccion);
            C = c_ej3_uniones(coleccion);
            printf("UNION: \t");
            cto_mostrar(C);

            B = c_ej3_intersecciones(coleccion);
            printf("INTERSECCION: \t");
            if(cto_es_vacio(B)){
                printf("No hay ningun elemento compartido por todos los conjuntos.\n");
            }else{
                cto_mostrar(B);
            }
            vaciar_conjunto(C);
            vaciar_conjunto(B);
            break;
        case 4:
            printf("\n\n");
            printf("CARGA DEL 1er CONJUNTO: \n");
            cargar_conjunto(A);
            printf("\n\n");
            printf("CARGA DEL 2do CONJUNTO: \n");
            cargar_conjunto(B);
            printf("\n\n");
            printf("CARGA DEL 3er CONJUNTO: \n");
            cargar_conjunto(C);
            printf("\n\n");
            printf("Primer conjunto: ");
            cto_mostrar(A);
            printf("\n\n");
            printf("Segundo conjunto: ");
            cto_mostrar(B);
            printf("\n\n");
            printf("Tercer conjunto: ");
            cto_mostrar(C);
            printf("\n\n");
            if(c_ej4_transitividad(A, B, C)){
                printf("\tEl conjunto A se compone de: ");
                cto_mostrar(A);
                printf("\n\n");
                printf("\tA es subconjunto de B como se puede observar: ");
                cto_mostrar(B);
                printf("\n\n");
                printf("\tComo B es subconjunto de C: ");
                cto_mostrar(C);
                printf("\n\n");
                printf("\tSe concluye que A es subconjunto de C.\n");
            }else{
                printf("\tA no es subconjunto de C.\n");
            }
            vaciar_conjunto(A);
            vaciar_conjunto(B);
            vaciar_conjunto(C);
            break;
        case 5:
            printf("\n\n");
            printf("CARGA DEL 1er CONJUNTO: \n");
            cargar_conjunto(A);
            printf("\n\n");
            printf("CARGA DEL 2do CONJUNTO: \n");
            cargar_conjunto(B);
            printf("\n\n");
            printf("Primer conjunto: ");
            cto_mostrar(A);
            printf("\n\n");
            printf("Segundo conjunto: ");
            cto_mostrar(B);
            printf("\n\n");
            C = c_ej5_dif_simetrica(A, B);
            if(!cto_es_vacio(C)){
                printf("DIFERENCIA SIMETRICA entre ambos conjuntos es: ");
                cto_mostrar(C);
            }else{
                printf("No hay DIFERENCIA SIMETRICA entre ambos conjuntos.\n");
            }
            vaciar_conjunto(A);
            vaciar_conjunto(B);
            vaciar_conjunto(C);
            break;
        case 6:
            printf("\n\n");
            printf("CARGA DEL 1er CONJUNTO: \n");
            cargar_numeros_naturales(A);
            printf("\n\n");
            printf("CARGA DEL 2do CONJUNTO: \n");
            cargar_numeros_naturales(B);
            printf("\n\n");
            printf("Primer conjunto: ");
            cto_mostrar(A);
            printf("\n\n");
            printf("Segundo conjunto: ");
            cto_mostrar(B);
            printf("\n\n");
            if(c_ej6_subconjuntopropio(A, B)){
                printf("A es SUBCONJUNTO PROPIO de B.\n");
            }else{
                printf("A NO es SUBCONJUNTO PROPIO de B.\n");
            }
            if(c_ej6_subconjuntopropio(B, A)){
                printf("B es SUBCONJUNTO PROPIO de A.\n");
            }else{
                printf("B NO es SUBCONJUNTO PROPIO de A.\n");
            }

            printf("COMPLEJIDAD ALGORITMICA\n"); 
            printf("\tSin considerar la TAD --> O(n) = n\n");
            printf("\tCon TAD de listas:\n");
            printf("\t\tListas_arreglos --> O(n) = cuadratica\n");
            printf("\t\tListas_cursores --> O(n) = cuadratica\n");
            printf("\t\tListas_punteros -->  O(n) = cuadratica\n");
            printf("\tCon TAD de Arbol AVL --> O(n) = cuadratica\n");

            vaciar_conjunto(A);
            vaciar_conjunto(B);
            break;
        case 7:
            printf("\n\n");
            printf("CARGA DEL 1er CONJUNTO: \n");
            cargar_conjunto(A);
            printf("\n\n");
            printf("CARGA DEL 2do CONJUNTO: \n");
            cargar_conjunto(B);
            printf("\n\n");
            printf("CARGA DEL 3er CONJUNTO: \n");
            cargar_conjunto(C);
            printf("\n\n");
            printf("Primer conjunto: ");
            cto_mostrar(A);
            printf("\n\n");
            printf("Segundo conjunto: ");
            cto_mostrar(B);
            printf("\n\n");
            printf("Tercer conjunto: ");
            cto_mostrar(C);
            printf("\n\n");
            c_ej7_subconjtotalparcial(A, B, C);

            printf("COMPLEJIDAD ALGORITMICA\n");
            printf("\tSin considerar la TAD --> O(n) = n\n");
            printf("\tCon TAD de listas:\n");
            printf("\t\tListas_arreglos --> O(n) = cuadratica\n");
            printf("\t\tListas_cursores --> O(n) = cuadratica\n");
            printf("\t\tListas_punteros -->  O(n) = cuadratica\n");
            printf("\tCon TAD de Arbol AVL --> O(n) = cuadratica\n");

            vaciar_conjunto(A);
            vaciar_conjunto(B);
            vaciar_conjunto(C);
            break;
        case 8:
            printf("\n\n");
            printf("CARGA DEL 1er CONJUNTO: \n");
            cargar_numeros_naturales(A);
            printf("\n\n");
            printf("CARGA DEL 2do CONJUNTO: \n");
            cargar_numeros_naturales(B);
            printf("\n\n");
            printf("Primer conjunto: ");
            cto_mostrar(A);
            printf("\n\n");
            printf("Segundo conjunto: ");
            cto_mostrar(B);
            printf("\n\n");
            if(c_ej8_soniguales(A, B) == true){
                printf("SI SON IGUALES.\n");
            }else{
                printf("NO SON IGUALES.\n");
            }

            printf("COMPLEJIDAD ALGORITMICA\n");
            printf("\tSin considerar la TAD --> O(n) = n\n");
            printf("\tCon TAD de listas:\n");
            printf("\t\tListas_arreglos --> O(n) = cuadratica\n");
            printf("\t\tListas_cursores --> O(n) = cuadratica\n");
            printf("\t\tListas_punteros -->  O(n) = cuadratica\n");
            printf("\tCon TAD de Arbol AVL --> O(n) = cuadratica\n");

            vaciar_conjunto(A);
            vaciar_conjunto(B);
            break;
        default:
            printf("OPCION INCORRECTA.\n");
            break;
        }
        printf("\n¿Quiere probar otro de ejercicio?\n");
        continuacion = validarsalida();
    }
    return;
}