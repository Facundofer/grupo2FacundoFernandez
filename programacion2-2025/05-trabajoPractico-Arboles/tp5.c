#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tp_arboles.h"
#include "..\libs\colas\headers\colas.h"
#include "..\libs\pilas\headers\pilas.h"
#include "..\libs\listas\headers\listas.h"
#include "..\libs\arboles\headers\arbol-avl.h"
#include "..\libs\arboles\headers\arbol-binario-busqueda.h"
#include "..\libs\validaciones\headers\validaciones.h"



// Ejercicio 2.a

void recorrer_arbol_2a(NodoArbol nodo, Lista L){
    TipoElemento x;
    if (a_es_rama_nula(nodo)){
        return;
    }
    else if(a_es_rama_nula(n_hijoizquierdo(nodo)) && a_es_rama_nula(n_hijoderecho(nodo))){
        x = n_recuperar(nodo);
        l_agregar(L, x);
        return; 
    }else{
        recorrer_arbol_2a(n_hijoizquierdo(nodo), L);
        recorrer_arbol_2a(n_hijoderecho(nodo), L);
    }
}

Lista a_ej2_hojas(ArbolBinario A){
    Lista l_resultado = l_crear();
    NodoArbol nodos;
    nodos = a_raiz(A);
    recorrer_arbol_2a(nodos, l_resultado);
    return l_resultado;
}

// Ejercicio 2.b

void recorrer_arbol_2b(NodoArbol nodo, Lista L){
    TipoElemento x;
    if (a_es_rama_nula(nodo)){
        return;
    }
    else{
        recorrer_arbol_2b(n_hijoizquierdo(nodo), L);
        recorrer_arbol_2b(n_hijoderecho(nodo), L);
    }
    if(!a_es_rama_nula(n_hijoizquierdo(nodo)) || !a_es_rama_nula(n_hijoderecho(nodo))){
        x = n_recuperar(nodo);
        l_agregar(L, x);
        return;
    } 
}

Lista a_ej2_interiores(ArbolBinario A){
    Lista l_resultado = l_crear();
    NodoArbol nodos;
    nodos = a_raiz(A);
    recorrer_arbol_2b(n_hijoizquierdo(nodos), l_resultado);
    recorrer_arbol_2b(n_hijoderecho(nodos), l_resultado);
    return l_resultado;
}


// Ejercicio 2.c

void buscar_ocurrencias_clave(NodoArbol nodo, Lista L, int clave){
    TipoElemento x;
    if (a_es_rama_nula(nodo)){ //nodo == NULL
        return;
    }
    if (nodo->datos->clave == clave){
        NodoArbol nodo_aux = (NodoArbol) malloc(sizeof(NodoArbol));
        nodo_aux = nodo;
        TipoElemento te = te_crear_con_valor(clave, nodo_aux);//probar pasando directamente el nodo sin crear otra variable nodoarbol
        l_agregar(L, te);
    }
    buscar_ocurrencias_clave(n_hijoizquierdo(nodo), L, clave);
    buscar_ocurrencias_clave(n_hijoderecho(nodo), L,  clave);
}

Lista a_ej2_buscarclave(ArbolBinario A, int clave){
    Lista l_resultado = l_crear();
    NodoArbol nodos;
    nodos = a_raiz(A);
    buscar_ocurrencias_clave(nodos, l_resultado, clave);
    return l_resultado;
}


// Ejercicio 3.a
void recuperar_padre(NodoArbol nodo, int clave, TipoElemento padre){
    if (a_es_rama_nula(nodo)){ //nodo == NULL
        return;
    }
    TipoElemento aux = n_recuperar(nodo);
    if (!a_es_rama_nula(n_hijoizquierdo(nodo)))
    {
        if(n_hijoizquierdo(nodo)->datos->clave == clave){
        padre->clave =aux->clave;
        return;
    }
    }
    if (!a_es_rama_nula(n_hijoderecho(nodo))){
        if(n_hijoderecho(nodo)->datos->clave == clave){
        padre->clave = aux->clave;
        return;
    }
    }
    recuperar_padre(n_hijoizquierdo(nodo), clave, padre);
    recuperar_padre(n_hijoderecho(nodo), clave, padre);
}


int a_ej3_clavepadre(ArbolBinario A, int clavehijo){
    NodoArbol nodo = a_raiz(A);
    TipoElemento padre = te_crear(-2);
    int resul;
    if(nodo->datos->clave == clavehijo){
        //Significa que no tiene padre
        return clavehijo;
    }
    recuperar_padre(nodo, clavehijo, padre);
    resul = padre->clave;
    return resul;
}

// Ejercicio 3.b
void recuperar_hijos(NodoArbol nodo, int clave, Lista resultado, bool *salida){
    if (a_es_rama_nula(nodo)){
        return;
    }
    if (nodo->datos->clave == clave && *salida == false)
    {
        NodoArbol nodo_hi = n_hijoizquierdo(nodo);
        NodoArbol nodo_hd = n_hijoderecho(nodo);
        nodo_hi = n_hijoizquierdo(nodo);
        if(!a_es_rama_nula(nodo_hi)){
            TipoElemento te_hi = te_crear(nodo_hi->datos->clave);
            l_agregar(resultado, te_hi);
        }
        if(!a_es_rama_nula(nodo_hd)){
            TipoElemento te_hd = te_crear(nodo_hd->datos->clave);
            l_agregar(resultado, te_hd);
        }
        //agregamos un booleano para que solo me de la primera aparicion
        *salida = true;
        return;
    }
    
    recuperar_hijos(n_hijoizquierdo(nodo), clave, resultado, salida);
    recuperar_hijos(n_hijoderecho(nodo), clave, resultado, salida);
}

Lista a_ej3_hijos(ArbolBinario A, int clavepadre){
    bool salida = false;
    TipoElemento te_hi, te_hd; 
    NodoArbol nodo = a_raiz(A);
    NodoArbol nodo_hi, nodo_hd;
    Lista resul = l_crear();
    if(nodo->datos->clave == clavepadre){
        nodo_hd = n_hijoderecho(nodo);
        if(!a_es_rama_nula(nodo_hd)){
            te_hd = te_crear(nodo_hd->datos->clave);
            l_agregar(resul, te_hd);
        }
        nodo_hi = n_hijoizquierdo(nodo);
        if(!a_es_rama_nula(nodo_hi)){
            te_hi = te_crear(nodo_hi->datos->clave);
            l_agregar(resul, te_hi);
        }
    }else{
        recuperar_hijos(nodo, clavepadre, resul, &salida);
    }
    return resul;
}

// Ejercicio 3.c

int a_ej3_hermano(ArbolBinario A, int clave){ 
    //Si no se permiten valores repetidos igualamos a clave de lo contrario F
    int hermano = -1;
    int padre = -2;
    Lista l_hijos = l_crear();
    Iterador ite; 
    TipoElemento te;

    padre = a_ej3_clavepadre(A, clave);
    l_hijos = a_ej3_hijos(A, padre);
    if (padre == -2)
    {
        return padre;
    }
    
    //Iniciamos el iterador luego de cargar la lista porque sino da error :v
    ite = iterador(l_hijos);
    while(hay_siguiente(ite)){
        te = siguiente(ite);
        if(te->clave != clave){
            //Siempre que no sea igual a la clave (o sea no trabajo valores repetidos)
            hermano = te->clave;
        }
    }
    
    return hermano;
} 

// Ejercicio 3.d
//Nivel: se determina por la longitud desde la raiz a un nodo especifico (dato del nodo)
void buscar_nivel(NodoArbol nodo, int *nivel, int clave, int posicion){
    if(a_es_rama_nula(nodo)){
        return;
    }else if(nodo->datos->clave == clave){
        *nivel = posicion;
        return;
    }
    posicion++;
    buscar_nivel(n_hijoizquierdo(nodo), nivel, clave, posicion);
    buscar_nivel(n_hijoderecho(nodo), nivel, clave, posicion);
    posicion--;
}

int a_ej3_nivel(ArbolBinario A, int clave){
    int nivel = -1;
    NodoArbol nodo = a_raiz(A);
    if(nodo->datos->clave == clave){
        nivel = 0;
        return nivel;
    }
    buscar_nivel(nodo, &nivel, clave, 0);
    return nivel;
}

// Ejercicio 3.e
//Altura: se determina por el numero maximo de nodos de una rama
int altura_recu(NodoArbol nodo){
    if(a_es_rama_nula(nodo)){
        return 0;
    }
    int HI_altura = altura_recu(n_hijoizquierdo(nodo));
    int HD_altura = altura_recu(n_hijoderecho(nodo));
    if(HI_altura >= HD_altura){
        return 1 + HI_altura;
    }else{
        return 1 + HD_altura;
    }
}

int a_ej3_alturarama(ArbolBinario A, int clave){
    Pila P = p_crear();
    NodoArbol N;
    TipoElemento X;
    bool salida = false;
    int altura;
    N = a_raiz(A);
    while((!p_es_vacia(P) || !a_es_rama_nula(N))){
        while(!a_es_rama_nula(N)){
            X = n_recuperar(N);
            if(X->clave == clave && salida != true){
               altura = altura_recu(N); 
               salida = true;
            }
            p_apilar(P, te_crear_con_valor(0, N));
            N = n_hijoizquierdo(N);
        }
        X = p_desapilar(P);
        N = (NodoArbol) X->valor;
        N = n_hijoderecho(N);
    }
    if(salida == false){
        altura = -1;
    }
    return altura;
}

// Ejercicio 3.f
void buscar_nodos_x_nivel(ArbolBinario A, NodoArbol nodo, int nivel, Lista l, int posicion){
    if(a_es_rama_nula(nodo)){
        return;
    }
    //int nivel_x = a_ej3_nivel(A, nodo->datos->clave);
    if(posicion == nivel){
        //Verificar que no piso la memoria
        TipoElemento te = te_crear(nodo->datos->clave);
        l_agregar(l, te);
    }
    posicion++;
    buscar_nodos_x_nivel(A, n_hijoizquierdo(nodo), nivel, l, posicion);
    buscar_nodos_x_nivel(A, n_hijoderecho(nodo), nivel, l, posicion);
    posicion--;
}

Lista a_ej3_clavesmismonivel(ArbolBinario A, int nivel){
    //agregamos posicion 
    int posicion = 0;
    Lista l_resul = l_crear();
    TipoElemento te;
    NodoArbol nodo = a_raiz(A);;
    if(nivel == 0){
        te = te_crear(nodo->datos->clave);
        l_agregar(l_resul, te);
        return l_resul;
    }
    buscar_nodos_x_nivel(A, nodo, nivel, l_resul, posicion);
    return l_resul;
}

//EJERCICIO 4
// a.	Dado un arbol n-ario, devolver en forma de lista el resultado del recorrido en anchura del arbol  (solo las claves).

void anchura_recu(NodoArbol nodo, Lista L, Cola C){
    if(a_es_rama_nula(nodo)){
        return;
    }
    TipoElemento te = te_crear_con_valor(0, nodo);
    l_agregar(L, te);
    if(!a_es_rama_nula(n_hijoizquierdo(nodo))){
        TipoElemento te_cola = te_crear_con_valor(0, n_hijoizquierdo(nodo));
        c_encolar(C, te_cola);
    }
    anchura_recu(n_hijoderecho(nodo), L, C);
}

Lista a_ej4_anchura(ArbolBinario A){
    Cola c = c_crear();
    Lista l_resul = l_crear();
    NodoArbol nodo = a_raiz(A);
    TipoElemento valor;
    TipoElemento te = te_crear_con_valor(0, nodo);
    c_encolar(c,te);
    do{
        valor = c_desencolar(c);
        NodoArbol nodo_aux = (NodoArbol)valor->valor;
        anchura_recu(nodo_aux, l_resul, c); 

    }while(!c_es_vacia(c));
    return l_resul;
}

//Ejercicio 4 b.	Escribir una funcion que, dado un arbol n-ario, devuelva el numero (cantidad) de hojas de dicho arbol.
void hojas_recu(NodoArbol nodo, int *cant_hojas){
    if(a_es_rama_nula(nodo)){
        return;
    }
    if(a_es_rama_nula(n_hijoizquierdo(nodo))){
        *cant_hojas += 1;
    }
    
    hojas_recu(n_hijoderecho(nodo), cant_hojas);
    hojas_recu(n_hijoizquierdo(nodo), cant_hojas);
}

int a_ej4_q_hojas(ArbolBinario A){
    NodoArbol nodo = a_raiz(A);
    int total_hojas = 0;
    hojas_recu(nodo, &total_hojas);
    return total_hojas;
}

// //Ejercicio 4c.	Escribir una funcion booleana que dados dos arboles generales determine si tienen la misma estructura, sin importar los datos del mismo (arbol similar).
void similares_recu(NodoArbol A, NodoArbol B, bool *resu){
    if(a_es_rama_nula(A) && a_es_rama_nula(B) || !resu){ // caso base si ambas son no nulas sigue porque quiero verificar la estructura en el siguiente if
        return;
    }
    else if (!a_es_rama_nula(A) && a_es_rama_nula(B) || a_es_rama_nula(A) && !a_es_rama_nula(B)) // aca verifico si alguno de los dos tiene un hijo diferente para ya saber que la estructura es diferente 
    {
        *resu = false;
        return;
    }
    similares_recu(n_hijoizquierdo(A), n_hijoizquierdo(B), resu);
    similares_recu(n_hijoderecho(A), n_hijoderecho(B), resu);
}

bool a_ej4_similares(ArbolBinario A, ArbolBinario B){
    bool resul = true;
    NodoArbol n_A = a_raiz(A);
    NodoArbol n_B = a_raiz(B);
    similares_recu(n_A, n_B, &resul);
    return resul;
}



// //Ejercicio 4d.	Retornar el padre de un nodo del arbol (tipo_elemento).
void padre_recu(NodoArbol nodo, bool *resu, Cola C, Cola C_aux, int clave){
    if(a_es_rama_nula(nodo) || !resu){
        return;
    }
    if(nodo->datos->clave == clave){
        *resu = true;
        return;
    }
    if(!a_es_rama_nula(n_hijoizquierdo(nodo))){
        //Guarda HI
        TipoElemento te_cola = te_crear_con_valor(0, n_hijoizquierdo(nodo));
        c_encolar(C, te_cola);
        //Guarda Padres
        TipoElemento te_cola_aux = te_crear_con_valor(0, nodo);
        c_encolar(C_aux, te_cola_aux);
    }
    padre_recu(n_hijoderecho(nodo), resu, C, C_aux, clave);
}

TipoElemento a_ej4_padre(ArbolBinario A, int clave){
    Cola c = c_crear();
    Cola c_padres = c_crear();
    bool resu = false;
    NodoArbol nodo = a_raiz(A);
    if(nodo->datos->clave == clave){   
        return NULL;
    }
    TipoElemento valor, p_valor;
    TipoElemento te = te_crear_con_valor(0, nodo);
    c_encolar(c,te);
    do{
        valor = c_desencolar(c);
        NodoArbol nodo_aux = (NodoArbol)valor->valor;
        padre_recu(nodo_aux, &resu, c, c_padres, clave);
        if (!resu)
        {
            p_valor = c_desencolar(c_padres);
        }else c_desencolar(c_padres);
    }while(!c_es_vacia(c));
    return p_valor;
}

// //Ejercicio 4e.	Retornar los hermanos de un nodo del arbol (lista de hermanos).

void Buscar_Hermanos(NodoArbol nodo, NodoArbol N_padre, int clave, Lista lista_hermanos){
    if(a_es_rama_nula(nodo)){
        return;
    }
    if(N_padre->datos->clave == nodo->datos->clave){
        NodoArbol HI = n_hijoizquierdo(nodo); 
        if(HI->datos->clave != clave){
            TipoElemento te_hi = te_crear(HI->datos->clave);
            l_agregar(lista_hermanos, te_hi);
        }
        while(!a_es_rama_nula(n_hijoderecho(HI))){
            if(n_hijoderecho(HI)->datos->clave != clave){
                TipoElemento hermano = te_crear(n_hijoderecho(HI)->datos->clave);
                l_agregar(lista_hermanos, hermano);
            }
            HI = n_hijoderecho(HI);  
        }
        return;
    }
    Buscar_Hermanos(n_hijoizquierdo(nodo), N_padre, clave, lista_hermanos);
    Buscar_Hermanos(n_hijoderecho(nodo), N_padre, clave, lista_hermanos);
}

Lista a_ej4_hermanos(ArbolBinario A, int clave){
    TipoElemento te_padre = a_ej4_padre(A, clave);
    NodoArbol Nodo_padre = (NodoArbol)te_padre->valor;
    NodoArbol N_raiz = a_raiz(A);
    Lista hermanos = l_crear();
    Buscar_Hermanos(N_raiz, Nodo_padre, clave, hermanos);
    return hermanos;
}

//EJERCICIO 7
void equivalente_recu(NodoArbol A, NodoArbol B, bool *resu){
    if(a_es_rama_nula(A) && a_es_rama_nula(B) || !resu){ // caso base si ambas son no nulas sigue porque quiero verificar la estructura en el siguiente if
        return;
    }
    else if (!a_es_rama_nula(A) && a_es_rama_nula(B) || a_es_rama_nula(A) && !a_es_rama_nula(B)) // aca verifico si alguno de los dos tiene un hijo diferente para ya saber que la estructura es diferente 
    {
        *resu = false;
        return;
    }
    
    if (A->datos->clave != B->datos->clave)
    {
        *resu = false;
    }
    equivalente_recu(n_hijoizquierdo(A), n_hijoizquierdo(B), resu);
    equivalente_recu(n_hijoderecho(A), n_hijoderecho(B), resu);
}

bool a_ej7_equivalente(ArbolBinario A, ArbolBinario B){
    
    if(a_es_vacio(A) && a_es_vacio(B)){
        return true;
    } else if(a_es_vacio(A) || a_es_vacio(B)){
        return false;
    }
    bool resul = true;
    NodoArbol n_A = a_raiz(A);
    NodoArbol n_B = a_raiz(B);
    if(n_A->datos->clave != n_B->datos->clave){
        resul = false;
        return resul;
    }
    equivalente_recu(n_A, n_B, &resul);
    return resul;
}

//EJERCICIO 8

// EJERCICIO 8a.	Determinar la altura del mismo.

int altura_recu_N_Ario(NodoArbol nodo){
    if(a_es_rama_nula(nodo)){
        return 0;
    }
    int max_altura = 0;
    NodoArbol hijo = n_hijoizquierdo(nodo);

    while (!a_es_rama_nula(hijo)) {
        int altura_hijo = altura_recu_N_Ario(hijo);
        if (altura_hijo > max_altura) {
            max_altura = altura_hijo;
        }
        hijo = n_hijoderecho(hijo); // pasar al siguiente hermano
    }

    return 1 + max_altura;    
}

int a_ej8_altura(ArbolBinario A){
    NodoArbol N;
    N = a_raiz(A);
    int altura = altura_recu_N_Ario(N);
    return altura;
}

// EJERCICIO 8b.	Determinar el nivel de un nodo.
int nivel_recu_N_Ario(NodoArbol nodo, int clave) {
    if (a_es_rama_nula(nodo)) {
        return -1;
    }

    if (nodo->datos->clave == clave) {
        return 0; 
    }

    NodoArbol hijo = n_hijoizquierdo(nodo);
    while (!a_es_rama_nula(hijo)) {
        int nivel_encontrado = nivel_recu_N_Ario(hijo, clave);
        if (nivel_encontrado >= 0) {
            return nivel_encontrado + 1;
        }
        hijo = n_hijoderecho(hijo);
    }

    return -1; 
}

int a_ej8_nivel(ArbolBinario A, int clave){
    NodoArbol N;
    N = a_raiz(A);
    int nivel = nivel_recu_N_Ario(N, clave);
    return nivel;
}

// EJERCICIO 8c.	Listar todos los nodos internos (solo las claves).
void internos_recu(NodoArbol nodo, Lista L){
    if(a_es_rama_nula(nodo)){
        return;
    }
    if (!a_es_rama_nula(n_hijoizquierdo(nodo)))
    {
        TipoElemento te = te_crear(nodo->datos->clave);
        l_agregar(L, te);
    }
    internos_recu(n_hijoizquierdo(nodo), L);
    internos_recu(n_hijoderecho(nodo), L);
}

Lista a_ej8_internos(ArbolBinario A){
    Lista l_internos = l_crear();
    NodoArbol nodo = a_raiz(A);
    if(!a_es_rama_nula(n_hijoizquierdo(nodo))){
        internos_recu(n_hijoizquierdo(nodo), l_internos);
    }else{
        //Si no tiene HI significa que es solo la raiz --> retorno lista vacia
        return l_internos;
    }
    return l_internos;
}

// EJERCICIO 8d.	Determinar si todas las hojas estan al mismo nivel.
void Hojas_recu_N_arios(Cola C, NodoArbol nodo){
    if(a_es_rama_nula(nodo)){
        return;
    }
    
    if (a_es_rama_nula(n_hijoizquierdo(nodo)))
    {
        TipoElemento te = te_crear(nodo->datos->clave);
        c_encolar(C, te);
    }
    Hojas_recu_N_arios(C, n_hijoizquierdo(nodo));
    Hojas_recu_N_arios(C, n_hijoderecho(nodo));

}

bool a_ej8_hojasmismonivel(ArbolBinario A){
    Cola hojas = c_crear();
    NodoArbol nodo = a_raiz(A);
    bool respuesta = true;
    TipoElemento te;
    int nivel_actual, nivel_nuevo;
    if(!a_es_rama_nula(n_hijoizquierdo(nodo))){
        Hojas_recu_N_arios(hojas, n_hijoizquierdo(nodo));
    }else{
        //Si no tiene HI significa que es solo la raiz --> retorno lista vacia
        return false;
    }
    te = c_desencolar(hojas);
    nivel_actual = nivel_recu_N_Ario(nodo, te->clave);
    while (!c_es_vacia(hojas) && respuesta)
    {
        te = c_desencolar(hojas);
        nivel_nuevo = nivel_recu_N_Ario(nodo, te->clave);
        if (nivel_actual != nivel_nuevo)
        {
            respuesta = false;
        }
    }
    return respuesta;

}

//Ejercicio 9
// Primero llamamos para construir el AVL
void cargar_arbol_AVL(NodoArbol nodo, ArbolAVL A){
    if (a_es_rama_nula(nodo))
    {
        return;
    }
    if(!avl_es_lleno(A)){
        avl_insertar(A, nodo->datos);
        cargar_arbol_AVL(n_hijoizquierdo(nodo), A);
        cargar_arbol_AVL(n_hijoderecho(nodo), A);
    }else{
        printf("Arbol lleno, no puede seguir cargando claves.\n");
        return;
    }
    
}

ArbolAVL a_ej9_construiravl(ArbolBinario A){
    ArbolAVL arbol_AVL = avl_crear();
    NodoArbol raiz = a_raiz(A);
    cargar_arbol_AVL(raiz, arbol_AVL);

    return arbol_AVL;
}

int altura_recu_AVL(NodoArbol nodo){
    if(avl_es_rama_nula(nodo)){
        return 0;
    }
    int HI_altura = altura_recu_AVL(n_hijoizquierdo(nodo));
    int HD_altura = altura_recu_AVL(n_hijoderecho(nodo));
    if(HI_altura >= HD_altura){
        return 1 + HI_altura;
    }else{
        return 1 + HD_altura;
    }
}

int alturarama_AVL(ArbolAVL A, int clave){
    Pila P = p_crear();
    NodoArbol N;
    TipoElemento X;
    bool salida = false;
    int altura;
    N = avl_raiz(A);
    while((!p_es_vacia(P) || (!avl_es_rama_nula(N)) || (!salida))){
        while(!avl_es_rama_nula(N)){
            X = n_recuperar(N);
            if(X->clave == clave){
               altura = altura_recu_AVL(N); 
               salida = true;
            }
            p_apilar(P, te_crear_con_valor(0, N));
            N = n_hijoizquierdo(N);
        }
        X = p_desapilar(P);
        N = (NodoArbol) X->valor;
        N = n_hijoderecho(N);
    }
    return altura;
}

int a_ej9_diferenciaalturas(ArbolBinario A, ArbolAVL AVL){
    NodoArbol raiz_binario = a_raiz(A);
    int altura_binario = a_ej3_alturarama(A, raiz_binario->datos->clave);
    NodoArbol raiz_AVL = avl_raiz(AVL);
    int altura_AVL = alturarama_AVL(AVL, raiz_AVL->datos->clave);
    int altura = altura_binario - altura_AVL;
    printf("la altura del arbol AVL es: %d\n", altura_AVL);
    return altura;
}

//Ejercicio 10
Lista a_ej10_generarlistaclaves(int cantidadclavesagenerar, int valorminimo, int valormaximo){
    Lista l_claves = l_crear();
    int clave = 0;
    int i = 0;
    while(i < cantidadclavesagenerar){
        clave = rand();
        clave = valorminimo + rand() % (valormaximo - valorminimo + 1);
        if(l_buscar(l_claves, clave) == NULL){
            TipoElemento te = te_crear(clave);
            l_agregar(l_claves, te);
            i++;   
        }
    }
    return l_claves;
}

// Ahora se la paso a la funcion que crea los 2 arboles
ArbolBinarioBusqueda a_ej10_crearABB(Lista L){
    ArbolBinarioBusqueda arbol_busqueda = abb_crear();
    Iterador ite = iterador(L);
    while(hay_siguiente(ite)){
        TipoElemento valor = siguiente(ite);
        abb_insertar(arbol_busqueda, valor);
    }
    return arbol_busqueda;
}
ArbolAVL a_ej10_crearAVL(Lista L){
    ArbolAVL arbol_AVL = avl_crear();
    Iterador ite = iterador(L);
    while(hay_siguiente(ite)){
        TipoElemento valor = siguiente(ite);
        avl_insertar(arbol_AVL, valor);
    }
    return arbol_AVL;
}

// Ahora llamos a la funcion que compara las alturas.  La comparacion es Altura(ABB) - Altura(AVL).
int altura_recu_ABB(NodoArbol nodo){
    if(abb_es_rama_nula(nodo)){
        return 0;
    }
    int HI_altura = altura_recu_ABB(n_hijoizquierdo(nodo));
    int HD_altura = altura_recu_ABB(n_hijoderecho(nodo));
    if(HI_altura >= HD_altura){
        return 1 + HI_altura;
    }else{
        return 1 + HD_altura;
    }
}

int alturarama_ABB(ArbolBinarioBusqueda A, int clave){
    Pila P = p_crear();
    NodoArbol N;
    TipoElemento X;
    bool salida = false;
    int altura;
    N = abb_raiz(A);
    while((!p_es_vacia(P) || (!abb_es_rama_nula(N)) || (!salida))){
        while(!abb_es_rama_nula(N)){
            X = n_recuperar(N);
            if(X->clave == clave){
               altura = altura_recu_ABB(N); 
               salida = true;
            }
            p_apilar(P, te_crear_con_valor(0, N));
            N = n_hijoizquierdo(N);
        }
        X = p_desapilar(P);
        N = (NodoArbol) X->valor;
        N = n_hijoderecho(N);
    }
    return altura;
}

int a_ej10_difalturas(ArbolBinarioBusqueda ABB, ArbolAVL AVL){
    NodoArbol raiz_AVL = avl_raiz(AVL);
    int altura_AVL = alturarama_AVL(AVL, raiz_AVL->datos->clave);
    NodoArbol raiz_abb = abb_raiz(ABB); 
    int altura_ABB = alturarama_ABB(ABB, raiz_abb->datos->clave);
    int altura = altura_ABB - altura_AVL;
    return altura;
}

// Este proceso se debera repetir N veces  (N se debera poder tomar por teclado).

// LLamada general del proceso.  retorna una lista con todas las diferencias de las comparaciones.
Lista a_ej10_comparacionarboles(int N_repeticiones, int valorminimo, int valormaximo, int cantidaclavesagenerar){
    int rep = 0;
    int diferencias;
    Lista l_claves = l_crear();
    Lista l_diferencias = l_crear();
    ArbolBinarioBusqueda Arbol_BB = abb_crear();
    ArbolAVL arbol_AVL = avl_crear();
    while(rep < N_repeticiones){
        
        l_claves = a_ej10_generarlistaclaves(cantidaclavesagenerar, valorminimo, valormaximo);
        Arbol_BB = a_ej10_crearABB(l_claves);
        arbol_AVL = a_ej10_crearAVL(l_claves);
        diferencias = a_ej10_difalturas(Arbol_BB, arbol_AVL);
        TipoElemento te = te_crear(diferencias);
        l_agregar(l_diferencias, te);
        free(arbol_AVL);
        free(Arbol_BB);
        l_vaciar(l_claves);
        rep++;
    }
    return l_diferencias;
}