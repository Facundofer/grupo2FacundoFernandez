#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "tp_3_pilas.h"
#include "..\libs\pilas\headers\pilas.h"
#include "..\libs\validaciones\headers\validaciones_TP3_pilas.h"
#define MAX 10



// Ejercicio 2.a
bool p_ej2_existeclave(Pila p, int clave){
    TipoElemento te;
    bool boleano = false;
    Pila aux = p_crear();
    while (!p_es_vacia(p))
    {
       te = p_desapilar(p);
       if (te->clave == clave)
       {
        boleano = true;
       }
       p_apilar(aux, te);
    }
    P_intercambiar(aux, p);
    return boleano;
}

// Ejercicio 2.b
Pila p_ej2_colocarelemento(Pila p, int posicionordinal, TipoElemento x){
    TipoElemento te;
    TipoElemento teAux;
    Pila auxp = p_crear();
    Pila auxf = p_crear();
    int poss = 1;
    if (p_es_llena(p))
    {
        printf("La pila esta llena");
        return p;
    }
    if (p_es_vacia(p))
    {
        p_apilar(p, x);
        return p;
    }
    while (!p_es_vacia(p))
    {
        te = p_desapilar(p);
        teAux = te_crear(te->clave);
        p_apilar(auxf, te);
        if (poss == posicionordinal)
        {
            p_apilar(auxp, x);
        }
        p_apilar(auxp, teAux);
        poss++;
    }
    if (posicionordinal > poss && !p_es_llena(auxp))
    {
        printf("La posicion es mas grande que la pila, se agregara el elemto en la base.\n");
        p_apilar(auxp, x);
    }
    
    P_intercambiar(auxf, p);
    P_intercambiar(auxp, auxf);
    return auxf;
}

// Ejercicio 2.c

Pila p_ej2_eliminarclave(Pila p, int clave){
    TipoElemento te;
    TipoElemento teAux;
    TipoElemento teAux1;
    Pila auxp = p_crear();
    Pila auxf = p_crear();
    int poss = 1;
    int borrado = 0;
    while (!p_es_vacia(p))
    {
        te = p_desapilar(p);
        teAux = te_crear(te->clave);
        teAux1 = te_crear(te->clave);
        if (teAux->clave == clave && borrado == 0)
        {
            p_apilar(auxf, te);
            borrado +=1;
        }else p_apilar(auxf, teAux);
        p_apilar(auxp, teAux1);
    }
    
    P_intercambiar(auxf, p);
    P_intercambiar(auxp, auxf);
    return auxf;
}

// Ejercicio 2.d
Pila p_ej2_intercambiarposiciones(Pila p, int pos1, int pos2){
    Pila auxOri = p_crear();
    Pila aux1 = p_crear();
    Pila aux = p_crear();
    TipoElemento te, teaux, tepos1, tepos2;
    int poss = 1;
    while (!p_es_vacia(p))
    {
        te = p_desapilar(p);
        teaux = te_crear(te->clave);
        p_apilar(auxOri, te);
        if (poss == pos1)
        {
            tepos1 = teaux;
        }else if (poss == pos2)
        {
            tepos2 = teaux;
        }        
        poss++;
    }
    poss --;
    while (!p_es_vacia(auxOri))
    {
        te = p_desapilar(auxOri);
        teaux = te_crear(te->clave);
        p_apilar(p, te);
        if (poss == pos2)
        {
            p_apilar(aux, tepos1);
        }else if (poss == pos1)
        {
            p_apilar(aux, tepos2);
        }else p_apilar(aux, teaux);
        
        poss --;        
    }
    return aux;    
    
}


// Ejercicio 2.e
Pila p_ej2_duplicar(Pila p){
    TipoElemento te, teaux;
    Pila aux = p_crear();
    Pila aux1 = p_crear();
    if (p_es_vacia(p))
    {
        return p;
    }
    
    while (!p_es_vacia(p))
    {
        te = p_desapilar(p);
        teaux = te_crear(te->clave);
        p_apilar(aux, teaux);
        p_apilar(aux, teaux);
        p_apilar(aux1, te);
    }
    P_intercambiar(aux1, p);
    P_intercambiar(aux, aux1);
    return aux1;    
}

// Ejercicio 2.f
int p_ej2_cantidadelementos(Pila p){
    TipoElemento te;
    Pila aux = p_crear();
    int poss = 0;
    while (!p_es_vacia(p))
    {
        te = p_desapilar(p);
        p_apilar(aux, te);
        poss++;
    }
    P_intercambiar(aux, p);
    return poss;    
}


//EJERCICIO 3

bool p_ej3_iguales(Pila p1, Pila p2){
    Pila aux = p_crear();
    TipoElemento te, teaux, teaux1;
    bool boleano = true;
    while (!p_es_vacia(p1))
    {
        te = p_desapilar(p1);
        teaux = p_desapilar(p2);
        if (te->clave != teaux->clave)
        {
            boleano = false;
        }
        p_apilar(aux, te);
        p_apilar(aux, teaux);
    }
    while (!p_es_vacia(aux))
    {
        teaux1 = p_desapilar(aux);
        p_apilar(p2,teaux1);
        teaux1 = p_desapilar(aux);
        p_apilar(p1,teaux1);
    }
    return boleano;        
}

//EJERCICIO 4
char*  p_ej4_cambiarbase(int nrobasedecimal, int nrootrabase){
    Pila pila = p_crear();
    TipoElemento te;
    int resto, valor;
    char *resultado = (char*)malloc(sizeof(char)*MAX);
    char *auxc = resultado;
    if (nrobasedecimal < 0)
    {
        printf("Es negativo se lo tratara como positivo.\n");
        nrobasedecimal = nrobasedecimal + (nrobasedecimal* -2);
    }
    
    while (nrobasedecimal >= nrootrabase)
    {
        resto = nrobasedecimal % nrootrabase;
        te = te_crear(resto);
        p_apilar(pila, te);
        nrobasedecimal /= nrootrabase;
    }
    te = te_crear(nrobasedecimal);
    p_apilar(pila, te);
    while (!p_es_vacia(pila))
    {
        te = p_desapilar(pila);
        valor = te->clave;
    // Convertimos el número a carácter
        if (valor < 10){
        *auxc = '0' + valor; 
        }     // para 0-9
         else *auxc = 'A' + (valor - 10); // para 10-15 → A-F

    auxc++;
    }
    *auxc = '\0';
    return resultado;
}
//EJERCICIO 5
Pila  p_ej5_invertir(Pila p){
    Pila pila = p_crear();
    Pila aux = p_crear();
    TipoElemento te, teaux;
    while (!p_es_vacia(p))
    {
        te = p_desapilar(p);
        teaux = te_crear(te->clave);
        p_apilar(pila, te);
        p_apilar(aux, teaux);
    }
    P_intercambiar(pila, p);
    return aux;
}

//EJERCICIO 6
//ITERATIVA
Pila p_ej6_eliminarclave(Pila p, int clave){
    TipoElemento te;
    TipoElemento teAux;
    Pila auxp = p_crear();
    Pila auxf = p_crear();
    int poss = 1;
    while (!p_es_vacia(p))
    {
        te = p_desapilar(p);
        teAux = te_crear(te->clave);
        if(teAux->clave != clave)
        {
            p_apilar(auxp, teAux);
        }
        p_apilar(auxf, te);
    }
    
    P_intercambiar(auxf, p);
    P_intercambiar(auxp, auxf);
    return auxf;
}
//RECURSIVA
Pila p_ej6_eliminarclave_r(Pila p, int clave){
    if (p_es_vacia(p))
    {
        return p_crear();
    }
    TipoElemento te = p_desapilar(p); 
    Pila pila = p_ej6_eliminarclave_r(p, clave);
    if (te->clave != clave)//acordate de que esta todo guardado en la memoria aca solo lo uso.
    {
        p_apilar(pila, te);
    }
    p_apilar(p,te);
    return pila;    
}


//EJERCICIO 7
Pila p_ej7_elementoscomunes(Pila p1, Pila p2){
    Pila pila = p_crear();
    Pila paux1 = p_crear();
    Pila pauxf = p_crear();
    TipoElemento te1, te2, teaux1, teaux2;
    while (!p_es_vacia(p1))
    {
        te1 = p_desapilar(p1);
        teaux1 = te_crear(te1->clave);
        while (!p_es_vacia(p2))
        {
            te2 = p_desapilar(p2);
            teaux2 = te_crear(te2->clave);
            if (te1->clave == te2->clave)
            {
                p_apilar(pauxf, teaux2);
            }
            p_apilar(pila, te2);
        }
        P_intercambiar(pila, p2);
        p_apilar(paux1, te1);
    }
    P_intercambiar(paux1, p1);    
    return pauxf;
}

//EJERCICIO 8
Pila p_ej8_sacarrepetidos(Pila p){
    int i = 0;
    int contador = 1;
    int *valor;
    Pila pila = p_crear();
    Pila paux = p_crear();
    Pila pfinal = p_crear();
    TipoElemento te, te1, teaux, teaux1, teaux2, teaux3;
    while (!p_es_vacia(p))
    {   
        te = p_desapilar(p);
        te1 = te_crear(te->clave);
        teaux = te_crear(te->clave);
        if (i != 1)
        {
            p_apilar(pila, te1);
        }
        while (!p_es_vacia(p))
        {   
            teaux1 = p_desapilar(p);
            te1 = te_crear(teaux1->clave);
            teaux2 = te_crear(teaux1->clave);
            if (i != 1){
                p_apilar(pila, te1);
            }
            if (teaux->clave == teaux2->clave)
            {
                contador++;
            }else p_apilar(paux, teaux2);
        }
        valor = (int*) malloc(sizeof(int));
        *valor = contador;
        teaux3 = te_crear_con_valor(te->clave, valor);
        p_apilar(pfinal, teaux3);
        P_intercambiar(paux, p);
        i = 1;
        contador = 1;
    }
    P_intercambiar(pila, p);
    return pfinal;
}