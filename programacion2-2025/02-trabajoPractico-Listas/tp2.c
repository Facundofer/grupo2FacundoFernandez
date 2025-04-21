#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "..\libs\listas\headers\listas.h"
#include "tp_2_listas_1.h"
#include "math.h"
#include "..\libs\validaciones\headers\validaciones.h"
#define MAX 100

Lista rellenarLista(int elementos) {
    Lista l1 = l_crear();
    if (l1 == NULL) {
        printf("Error al crear la lista.\n");
        return NULL;
    }

    char auxiliar[MAX];
    bool agregar;
    
    printf("Ingrese %d elementos enteros:\n", elementos);
    
    for (int i = 0; i < elementos; i++) {
        TipoElemento te;
        int valor;
        printf("Elemento %d/%d: ", i+1, elementos);
        fgets(auxiliar, MAX, stdin);
        auxiliar[strcspn(auxiliar, "\n")] = '\0';
        valor = (int)validar_entero(auxiliar);  
        te = te_crear(valor);
        if (te == NULL) {
            printf("Error al crear el elemento.\n");
            l_vaciar(l1);
            return l1;
        } 
        agregar = l_agregar(l1, te);
        if (!agregar) {
            printf("Error al agregar elemento a la lista.\n");
            l_vaciar(l1);
            return l1;
        }
    }
    
    return l1;
}

// Ejercicio 2
Lista verElementosRepetidos(Lista l1, Lista l2){
    TipoElemento te;
    TipoElemento auxte;
    Iterador ite = iterador(l1);
    Lista aux;
    aux = l_crear();
    while (hay_siguiente(ite) != false)
    {   
        te = siguiente(ite);
        auxte = te;
        if (l_buscar(l2, te->clave))
        {
            l_agregar(aux, auxte);
        }
    }
    return aux;
}

Lista verElementosQueNoSeRepiten(Lista l1, Lista l2){
    TipoElemento te;
    TipoElemento auxte;
    Iterador ite = iterador(l1);
    Lista aux;
    aux = l_crear();
    while (hay_siguiente(ite) != false)
    {   
        te = siguiente(ite);
        auxte = te;
        if (!(l_buscar(l2, te->clave)))
        {
            l_agregar(aux, auxte);
        }
    }
    return aux;
}

float promedio(Lista l1){
    float promedio = 0;
    int longuitud = l_longitud(l1);
    Iterador ite;
    TipoElemento te;
    ite = iterador(l1);
    while (hay_siguiente(ite))
    {
        te = siguiente(ite);
        promedio += te->clave;
    }

    promedio /= longuitud;
    return promedio;
}
/*Resultados promedioAmbasListas(Lista l1, Lista l2){
    Resultados resultado;
    float promedio1, promedio2;
    promedio1 = promedio(l1);
    promedio2 = promedio(l2);
    resultado.resultado1 = promedio1;
    resultado.resultado2 = promedio2;
    return resultado;   
}*/

ResultadoValorMinimo valorMinimo(Lista l1, Lista l2){
    TipoElemento te1, te2;
    Iterador ite1, ite2;
    int minimo1, minimo2, pos = 1;
    ResultadoValorMinimo resultado;
    ite1 = iterador(l1);
    ite2 = iterador(l2);
    te1 = siguiente(ite1);
    te2 = siguiente(ite2);
    minimo1 = te1->clave;
    minimo2 = te2->clave; 
    resultado.pos = 1, resultado.pos_2 = 1; 
    while (hay_siguiente(ite1) || hay_siguiente(ite2)) {
        if (hay_siguiente(ite1)) {
            te1 = siguiente(ite1);
            if (te1->clave < minimo1) {
                minimo1 = te1->clave;
                resultado.pos = pos+1;
            }
        }
        
        if (hay_siguiente(ite2)) {
            te2 = siguiente(ite2);
            if (te2->clave < minimo2) {
                minimo2 = te2->clave;
                resultado.pos_2 = pos+1;
            }
        }
        
        pos++;
    }
    
    resultado.valor = minimo1;
    resultado.valor_2 = minimo2;
    return resultado;
}


// ejercicio 3

ResultadosMul multiplo(Lista l1, Lista l2){
    TipoElemento te1, te2;
    ResultadosMul resultado;
    Iterador ite1 = iterador(l1);
    Iterador ite2 = iterador(l2);
    te1 = siguiente(ite1);
    te2 = siguiente(ite2);
    resultado.esMultiplo = true;
    resultado.escalar = true;
    resultado.numEscalar = te2->clave / te1->clave;
    int longitud = l_longitud(l1);
    int escalar;

    while (hay_siguiente(ite1) && hay_siguiente(ite2))
    {
        te1= siguiente(ite1);
        te2= siguiente(ite2);
        if (te2->clave % te1->clave != 0)
        {
            resultado.esMultiplo = false;
        }
        escalar = te2->clave / te1->clave;
        if (escalar != resultado.numEscalar)
        {
            resultado.escalar = false;
        }
    }
    return resultado;
}

// Ejercicio 4

int CompararListas(Lista l1, Lista L2){
    TipoElemento te1, te2;
    Iterador ite1 = iterador(l1);
    Iterador ite2 = iterador(L2);
    int contadorL1=0;
    int contadorL2=0;
    while (hay_siguiente(ite1) && hay_siguiente(ite2)) {
        te1 = siguiente(ite1);
        te2 = siguiente(ite2);

        if (te1->clave > te2->clave) {
            contadorL1++;
        } else if (te1->clave < te2->clave) {
            contadorL2++;
        }
    }

    if (contadorL1 > contadorL2) {
        return 1;  
    } else if (contadorL1 < contadorL2) {
        return 2;
    } else {
        return 0;
    }
}

// Ejercicio 5
void hacerPolinomio(Lista list){
    TipoElemento te;
    float valor;
    float *clave;
    bool agregar = true;
    int tamano;
    char auxiliar[MAX];  
    printf("Ingrese el grado del polinomio: ");
    fgets(auxiliar, MAX, stdin);
    auxiliar[strcspn(auxiliar, "\n")] = '\0';
    tamano = validar_entero(auxiliar);
    while (tamano <= 0)
    {
        printf("El grado del polinomio no puede ser 0 o menor. Ingrese uno correcto.");
        tamano = validar_entero(auxiliar);
    }
    
    printf("Ingrese los coeficientes iniciando con el termino independiente hasta el primero. \n");
    for (int i = 0; i <= tamano; i++)
    {   
        valor = (float)validarReales();
        clave = (float*) malloc(sizeof(float));
        *clave = valor;
        te = te_crear_con_valor(i, clave);
        agregar = l_agregar(list, te);
        if (!agregar)
        {
            printf("ERROR AL CARGAR LISTA.");
            return;
        }
    }
    return;
}

float evaluarPolinomio(Lista list, float x) {
    float resultado = 0;
    Iterador ite = iterador(list);
    TipoElemento te;
    int grado = l_longitud(list) - 1;
    
    while (hay_siguiente(ite)) {
        te = siguiente(ite);
        float coef = *((float*)te->valor);
        resultado += coef * pow(x, grado - te->clave);
    }
    return resultado;
}

Lista calcularRango(Lista list, double x, double y, double sumando){
    Lista l1;
    l1 = l_crear();
    TipoElemento te;
    float *resultado;
    int cont = 0;
    bool agregar = true;
    while (x <= y && agregar)
    {   
        resultado = (float*) malloc(sizeof(float));
        *resultado = evaluarPolinomio(list, x);
        te = te_crear_con_valor(cont++, resultado);
        agregar = l_agregar(l1, te);
        x += sumando;
    }
    return l1;    
}



// Ejercicio 6

bool esSublista(Lista l1, Lista l2){
    TipoElemento te;
    Iterador ite = iterador(l2);
    bool Resultado = true;
    while (hay_siguiente(ite) && Resultado)
    {
        te = siguiente(ite);
        Resultado = l_buscar(l1, te->clave);
    }
    return Resultado; 
}


