#include "..\libs\colas\headers\colas.h"
#include "..\libs\pilas\headers\pilas.h"
#include "..\libs\listas\headers\listas.h"
#include "..\libs\validaciones\headers\validaciones.h"
#include "tp_4_colas.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX 11

/*EJERCICIO 2
2. Resolver los siguientes puntos: 
    a. Informar si un elemento dado se encuentra en la cola. 
    b. Agregar un nuevo elemento en una posición dada (colarse). 
    c. Dado un elemento sacarlo de la cola todas las veces que aparezca. 
    d. Contar los elementos de la cola. 
    e. Realizar una función que realice una copia de una cola. 
    f. Invertir el contenido de una cola sin destruir la cola original.
*/

//a.
bool c_ej2_existeclave(Cola c, int clave){
    Cola cola_aux = c_crear();
    TipoElemento te, aux;
    bool resul = false;
    while(!c_es_vacia(c)){
        te = c_desencolar(c);
        aux = te_crear(te->clave);
        if(aux->clave == clave){
            resul = true;
        }
        c_encolar(cola_aux, aux);
    }
    intercambiar(cola_aux, c);
    return resul;
}

//b.
Cola c_ej2_colarelemento(Cola c, int posicionordinal, TipoElemento X){
    Cola cola_aux = c_crear();
    Cola cola_aux1 = c_crear();
    Cola cola_nueva = c_crear();
    TipoElemento te, aux, valor;
    int pos = 1;
    cola_aux1 = c_ej2_copiar(c);
    if(c_es_llena(c)){
        printf("La cola esta llena.\n");
        return cola_aux1;
    }
    while(!c_es_vacia(c)){
        te = c_desencolar(c);
        aux = te_crear(te->clave);
        valor = te_crear(te->clave);
        if(pos == posicionordinal){
            c_encolar(cola_nueva, X);
        }
        c_encolar(cola_nueva, valor);
        c_encolar(cola_aux, aux);
        pos++;

    }
    intercambiar(cola_aux, c);
    if(pos <= posicionordinal){
        printf("La posicion es mayor al tamanio de la cola.\n");
        return cola_aux1;
    }
    return cola_nueva;
}

//c.
Cola c_ej2_sacarelemento(Cola c, int clave){
    Cola cola_aux = c_crear();
    Cola cola_nueva = c_crear();
    TipoElemento te, aux, valor;
    bool x = true;
    while(!c_es_vacia(c)){
        te = c_desencolar(c);
        aux = te_crear(te->clave);
        valor = te_crear(te->clave);
        if(aux->clave != clave){
            c_encolar(cola_nueva, valor);
        }else if (aux->clave == clave)
        {
            x = false;
        }
        c_encolar(cola_aux, aux);
    }
    intercambiar(cola_aux, c);
    if(x == false && c_es_vacia(cola_nueva)){
        printf("Todos los elementos eran la clave.\n");
    }else if (x == true){
        printf("La clave no existe en la cola.\n");
    } 
    return cola_nueva;  
}

//d.
int c_ej2_contarelementos(Cola c){
    Cola cola_aux = c_crear();
    TipoElemento te, aux;
    int resul = 0;
    if(c_es_vacia(c)){
        return resul;
    }    
    while(!c_es_vacia(c)){
        te = c_desencolar(c);
        aux = te_crear(te->clave);
        c_encolar(cola_aux, aux);
        resul++;
    }
    intercambiar(cola_aux, c);
    return resul;
}

//e.
Cola c_ej2_copiar(Cola c){
    Cola cola_copia = c_crear();
    Cola cola_aux = c_crear();
    TipoElemento te, teaux;
    if(c_es_vacia(c)){
        return c;
    } 
    while (!c_es_vacia(c))
    {
        te = c_desencolar(c);
        teaux = te_crear(te->clave);
        c_encolar(cola_copia, teaux);
        c_encolar(cola_aux, te);
    }
    intercambiar(cola_aux, c);
    return cola_copia;   
}

//f.
Cola c_ej2_invertir(Cola c){
    Pila pila = p_crear();
    Cola cola_nueva = c_crear();
    TipoElemento te, teaux, teauxresul;
    if(c_es_vacia(c)){
        return c;
    }
    while (!c_es_vacia(c))
    {
        te = c_desencolar(c);
        teaux = te_crear(te->clave);
        p_apilar(pila, teaux);
        c_encolar(cola_nueva, te);
    }
    intercambiar(cola_nueva, c);
    while (!p_es_vacia(pila))
    {
        teaux = p_desapilar(pila);
        teauxresul = te_crear(teaux->clave);
        c_encolar(cola_nueva, teauxresul);
    }
    return cola_nueva;
}
//3.
bool c_ej3_iguales(Cola c1, Cola c2){
    Cola cola_aux = c_crear();
    TipoElemento te1, te2, aux1, aux2;
    bool iguales = true;
    if(c_ej2_contarelementos(c1) != c_ej2_contarelementos(c2)){
        printf("Las colas no tienen la misma longitud.\n");
        return false;
    }else{
        int cantidad = c_ej2_contarelementos(c1);
        for(int i = 0; i < cantidad; i++){
            te1 = c_desencolar(c1);
            te2 = c_desencolar(c2);
            aux1 = te_crear(te1->clave);
            aux2 = te_crear(te2->clave);
            c_encolar(cola_aux, aux1);
            if(te1->clave != te2->clave){
                iguales = false;
            }
            c_encolar(c1, te1);
            c_encolar(c2, te2);
        }
    }
    return iguales;
}


//4.
Cola  c_ej4_colanorepetidos(Cola c){
    Cola cola_aux = c_crear();
    Cola cola_nueva = c_crear();
    Cola cola_resultado = c_crear();
    bool boleano = false;
    int primeravuelta = 0;
    TipoElemento te, teaux, teaux1, teaux2;
    while (!c_es_vacia(c))
    {
        te = c_desencolar(c);
        teaux2 = te_crear(te->clave);
        if (primeravuelta != 1)
        {
            c_encolar(cola_aux, te);
        }
        while (!c_es_vacia(c))
        {
            teaux = c_desencolar(c);
            teaux1 =te_crear(teaux->clave);
            if (te->clave != teaux->clave)
            {
                c_encolar(cola_nueva, teaux1);
            }else boleano = true;
            if (primeravuelta != 1)
            {
                c_encolar(cola_aux, teaux);
            }
        }
        primeravuelta = 1;
        if (!boleano)
        {
            c_encolar(cola_resultado, teaux2);
        }
        intercambiar(cola_nueva, c);
        boleano = false;       
    }
    intercambiar(cola_aux, c);
    return cola_resultado; 
}

//5.
Cola c_ej5_divisortotal(Cola c){
    Cola ColaAux = c_crear();
    Cola ColaResultado = c_crear();
    Cola ColaDuplicada = c_crear();
    TipoElemento te; 
    TipoElemento aux; //para guardar los elementos en pila auxiliar
    TipoElemento resul; //Para guardar los datos en la cola resultado
    TipoElemento dupli;
    int Max = 0, Min, contador_actual, mitad, resto, cantidad;
    bool salir = false;
    cantidad = c_ej2_contarelementos(c);
    //Obtengo el %50 y redondeo para arriba
    mitad = (cantidad % 2 == 0) ? cantidad / 2 : (cantidad / 2) + 1;
//---------Buscar el MAX y MIN y copio en ColaAux para no perder la cola------
    aux = c_recuperar(c);
    Min = aux->clave;
    while(!c_es_vacia(c)){
        aux = c_desencolar(c);
        if(aux->clave < Min){
            Min = aux->clave;
        }
        if(aux->clave > Max){
            Max = aux->clave;
        }
        //para la pila auxiliar
        te = te_crear(aux->clave); 
        c_encolar(ColaAux, te);
        //para la duplicada
        dupli = te_crear(aux->clave);
        c_encolar(ColaDuplicada, dupli);
    }
    Max = Max/2;
    intercambiar(ColaAux, c);
//------------Evaluo los divisores parciales-----------
    for(int divisor = Max; divisor > Min; divisor--){
        int contador = 0;
        while(!c_es_vacia(c)) {
            aux = c_desencolar(c);
            if (aux->clave % divisor == 0){
                contador++;
            } 
            c_encolar(ColaAux, aux);
        }
        intercambiar(ColaAux, c);
        if(contador >= mitad){
            bool *es_parcial = malloc(sizeof(bool));
            *es_parcial = false;
            te = te_crear_con_valor(divisor, es_parcial);
            c_encolar(ColaResultado, te);
        }
    }
//------------Evaluo el divisor total-------------
        while(!c_es_vacia(c) && salir != true){
            aux = c_desencolar(c);
            resto = aux->clave % Min;
            if(resto != 0){
                salir = true;
            }
            te = te_crear(aux->clave);
            c_encolar(ColaAux, te);  
        }
//----------no pierdo la pila original------------
        intercambiar(ColaAux, c);
        if(salir != true){
            bool *es_total = malloc(sizeof(bool));
            *es_total = true;
            resul = te_crear_con_valor(Min, es_total); 
            c_encolar(ColaResultado, resul);
        }
        return ColaResultado;
}
//6.

Lista c_ej6_comunesapilaycola(Pila p, Cola c) {
    Cola caux = c_crear();
    Pila pilaaux = p_crear();
    Lista lista = l_crear();
    TipoElemento tecola, tecolaaux, tepila, tepilaaux;
    int possp = 1;
    int possc;

    P_intercambiar(p, pilaaux);
    while (!p_es_vacia(pilaaux)) {
        tepila = p_desapilar(pilaaux);
        tepilaaux = te_crear(tepila->clave);
        possc = 1; 
        while (!c_es_vacia(c)) {
            tecola = c_desencolar(c);
            tecolaaux = te_crear(tecola->clave);

            if (tepilaaux->clave == tecolaaux->clave) {
                char *posiciones = malloc(sizeof(char) * 20);
                sprintf(posiciones, "%d:%d:%d", tepila->clave, possp, possc);
                TipoElemento nuevo = te_crear_con_valor(tepilaaux->clave, posiciones);
                l_agregar(lista, nuevo);

            }
            c_encolar(caux, tecolaaux);
            possc++;
        }

        intercambiar(caux, c);
        p_apilar(p, tepilaaux);
        possp++;
    }
    return lista;
}


//7.
Cola c_ej7_atenderclientes(Cola c1, Cola c2, Cola c3, int tiempoatencion){
    Cola c1aux = c_ej2_copiar(c1);
    Cola c2aux = c_ej2_copiar(c2);
    Cola c3aux = c_ej2_copiar(c3);
    Cola colaresultado = c_crear();
    TipoElemento tec1, tec2, tec3, teclaveresul;
    int poscola1 = 1;
    int poscola2 = 1;
    int poscola3 = 1;
    while (!c_es_vacia(c1aux) || !c_es_vacia(c2aux) || !c_es_vacia(c3aux))
    {   
        if (!c_es_vacia(c1aux)){   
            tec1 = c_recuperar(c1aux);
            tec1->clave -= tiempoatencion;
            if (tec1->clave <= 0)
            {
                char *resultado1 = malloc(sizeof(char) * 20);
                sprintf(resultado1, "Cliente %d Cola %d", poscola1, 1);
                teclaveresul =te_crear_con_valor(tec1->clave, resultado1);
                c_encolar(colaresultado, teclaveresul);
                c_desencolar(c1aux);
                poscola1++;
            }
        }
        if (!c_es_vacia(c2aux)){
            tec2 = c_recuperar(c2aux);
            tec2->clave -= tiempoatencion;
            if (tec2->clave <= 0)
            {
                char *resultado2 = malloc(sizeof(char) * 20);
                sprintf(resultado2, "Cliente %d Cola %d", poscola2, 2);
                teclaveresul =te_crear_con_valor(tec2->clave, resultado2);
                c_encolar(colaresultado, teclaveresul);
                c_desencolar(c2aux);
                poscola2++;
            }
        }
        if (!c_es_vacia(c3aux)){
            tec3 = c_recuperar(c3aux);
            tec3->clave -= tiempoatencion;
            if (tec3->clave <= 0)
            {
                char *resultado3 = malloc(sizeof(char) * 20);
                sprintf(resultado3, "Cliente %d Cola %d", poscola3, 3);
                teclaveresul =te_crear_con_valor(tec3->clave, resultado3);
                c_encolar(colaresultado, teclaveresul);
                c_desencolar(c3aux);
                poscola3++;
            }
        }
    }
    return colaresultado;
}