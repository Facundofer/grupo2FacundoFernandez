#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "tp_conjunto.h"
#include "..\libs\conjuntos\headers\conjuntos.h"
#include "..\libs\validaciones\headers\validaciones.h"

//EJERCICIO 2

Conjunto c_ej2_union(Conjunto A, Conjunto B){
    Conjunto cto = cto_union(A, B);
    return cto;
}

Conjunto c_ej2_interseccion(Conjunto A, Conjunto B){
    Conjunto cto = cto_interseccion(A, B);
    return cto;
}

Conjunto c_ej2_diferencia(Conjunto A, Conjunto B){
    Conjunto cto = cto_crear();
    if(cto_es_vacio(A)){
        return cto;
    }else if(cto_es_vacio(B)){
        cto = cto_union(A, cto);
        return cto;
    }
    cto = cto_diferencia(A, B);
    return cto;
}

bool c_ej2_pertenencia(Conjunto A, int clave){
    if (!cto_pertenece(A, clave))
    {
        return false;
    }      
    return true;
}

//EJERCICIO 3

Conjunto c_ej3_uniones(Lista l_de_conjuntos){
    Conjunto cto_resul = cto_crear();
    Conjunto cto_aux = cto_crear();
    Iterador ite = iterador(l_de_conjuntos);
    TipoElemento te;
    while(hay_siguiente(ite)){
        te = siguiente(ite);
        cto_aux = (Conjunto) te->valor;
        cto_resul = cto_union(cto_resul, cto_aux);
    }
    return cto_resul;
}

Conjunto c_ej3_intersecciones(Lista l_de_conjuntos){
    Conjunto cto_prueba = cto_crear();
    Conjunto cto_aux = cto_crear();
    Conjunto cto_resul = cto_crear();
    Iterador ite = iterador(l_de_conjuntos);
    TipoElemento te, clave_te;
    bool encontrado = true;
    te = siguiente(ite);
    cto_aux = (Conjunto) te->valor;
    for(int i = 1; i <= cto_cantidad_elementos(cto_aux); i++){
        clave_te = cto_recuperar(cto_aux, i);
        encontrado = true;
        ite = iterador(l_de_conjuntos);
        while(hay_siguiente(ite) && encontrado != false){
            te = siguiente(ite);
            cto_prueba = (Conjunto) te->valor;
            if(!cto_pertenece(cto_prueba, clave_te->clave)){
                encontrado = false;
            }     
        }
        if(encontrado != false){
            cto_agregar(cto_resul, clave_te);
        }
    }  
    return cto_resul;
}

//EJERCICIO 4
bool c_ej4_transitividad(Conjunto A, Conjunto B, Conjunto C){
    if (pertenencia_auxiliar(A, B) && pertenencia_auxiliar(B, C))
    {
        return true;        
    }else return false;  
}

//EJERCICIO 5
Conjunto c_ej5_dif_simetrica(Conjunto A, Conjunto B){
    Conjunto cto_diferencias = c_ej2_diferencia(A, B);
    Conjunto cto_diferencias_bis = c_ej2_diferencia(B, A);
    return cto_union(cto_diferencias, cto_diferencias_bis);

}

//EJERCICIO 6
bool c_ej6_subconjuntopropio(Conjunto A, Conjunto B){
    if (pertenencia_auxiliar(A, B) && cto_cantidad_elementos(A) < cto_cantidad_elementos(B)){
        return true;        
    }else{
        return false;
    } 
}

//EJERCICIO 7
void verificar_subconjunto(Conjunto A, Conjunto B, char* nombre_A, char* nombre_B) {
    int cantidad = 0;
    TipoElemento te;
    int tam_A = cto_cantidad_elementos(A);
    int umbral = (tam_A % 2 == 0) ? (tam_A / 2) : (tam_A / 2) + 1;
    if (pertenencia_auxiliar(A, B) || cto_es_vacio(A)) {
        printf("%s es subconjunto TOTAL de %s\n", nombre_A, nombre_B);
        return;
    }

    if (!cto_es_vacio(A) && cto_es_vacio(B)) {
        //No es ni total ni parcial
        return;
    }

    for (int i = 1; i <= tam_A; i++) {
        te = cto_recuperar(A, i);
        if (cto_pertenece(B, te->clave)) {
            cantidad += 1;
        }
    }

    if (cantidad >= umbral) {
        printf("%s es subconjunto PARCIAL de %s\n", nombre_A, nombre_B);
    }
}

void c_ej7_subconjtotalparcial(Conjunto A, Conjunto B, Conjunto C){
    verificar_subconjunto(A, B, "A", "B");
    verificar_subconjunto(A, C, "A", "C");
    verificar_subconjunto(B, C, "B", "C");
    verificar_subconjunto(B, A, "B", "A");
    verificar_subconjunto(C, A, "C", "A");
    verificar_subconjunto(C, B, "C", "B");
}

//EJERCICIO 8
bool c_ej8_soniguales(Conjunto A, Conjunto B){
    if ((cto_cantidad_elementos(A) == cto_cantidad_elementos(B)) && pertenencia_auxiliar(A, B))
    {
        return true;
    }else{
    return false;
    }
    
}