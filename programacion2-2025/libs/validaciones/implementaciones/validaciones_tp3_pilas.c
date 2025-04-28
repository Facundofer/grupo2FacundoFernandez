#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "..\..\tipoElemento\headers\tipo_elemento.h"
#include "..\..\pilas\headers\pilas.h"
#include "..\..\validaciones\headers\validaciones_TP3_pilas.h"
#define MAX 100


bool esEntero(double valor) {
    return valor == (double)(long)valor;
}

double validar_entero(char *entrada){
    char *validando;
    double resultado;
    bool validar = false;
    while (!validar){
       resultado = strtod(entrada, &validando); 
       validar = true;
       if (entrada == validando || *validando != '\0' || !esEntero(resultado)){
           printf("Opcion no valida. Por favor, ingrese un numero: \n");
           fgets(entrada, MAX, stdin);
           entrada[strcspn(entrada, "\n")] = '\0';
           validar = false;
       }
       
    }
    return resultado;
}

Pila cargarpila(int elementos){
    TipoElemento TE;
    Pila pila;
    pila = p_crear();
    int i = 1;
    int valor;
    char auxiliar[MAX];
    printf("Ingrese los valores para cargar la pila.\n");
    while (i <= elementos)
    {
        printf("Ingrese elemento %d: ", i);
        fgets(auxiliar, MAX, stdin);
        auxiliar[strcspn(auxiliar, "\n")] = '\0';
        valor = validar_entero(auxiliar);
        TE = te_crear(valor);
        p_apilar(pila, TE);
        i++;
    }
    return pila;
}


void P_intercambiar(Pila pila, Pila auxi){
    TipoElemento teP;
    TipoElemento auxiP;
    bool boleano = true;
    while (!p_es_vacia(pila))
    {
        teP = p_desapilar(pila);
        auxiP = te_crear(teP->clave);
        boleano = p_apilar (auxi, auxiP);
        if (!boleano)
        {
            printf("ERROR CARGAR ELEMENTO.\n");
            return;
        }
    }
}

bool validarejercicio(int valor){
    bool validacion = false;
    if (valor >= 2 && valor <=8)
    {
        validacion = true;
    }
    return validacion;
}

int validareleccion(){
    int ejercicio;
    char auxiliar[MAX];  
    printf("Que ejercicio quiere probar del 2 al 8: ");
    fgets(auxiliar, MAX, stdin);
    auxiliar[strcspn(auxiliar, "\n")] = '\0';
    ejercicio = validar_entero(auxiliar);
    while (!validarejercicio(ejercicio))
    {
        printf("Opcion invalida. Debe ingresar un valor del 2 al 8: ");
        fgets(auxiliar, MAX, stdin);
        auxiliar[strcspn(auxiliar, "\n")] = '\0';
        ejercicio = validar_entero(auxiliar);
    }
    return ejercicio;
}

bool validarcontinuacion(int valor) {
    return (valor == 0 || valor == -1);
}

int validarsalida() {
    char auxiliar[MAX];
    int ejercicio;
    
    do {
        printf("Ingrese 0 para continuar o -1 para salir: ");
        fgets(auxiliar, MAX, stdin);
        auxiliar[strcspn(auxiliar, "\n")] = '\0';
        
        ejercicio = validar_entero(auxiliar);
        
        if (!validarcontinuacion(ejercicio)) {
            printf("Opcion invalida. ");
        }
    } while (!validarcontinuacion(ejercicio));
    
    return ejercicio;
}

int validartamanopila(){
    int ejercicio;
    char auxiliar[MAX];  
    printf("Ingrese el tamano de la lista: ");
    fgets(auxiliar, MAX, stdin);
    auxiliar[strcspn(auxiliar, "\n")] = '\0';
    ejercicio = validar_entero(auxiliar);
    while (ejercicio < 0 || ejercicio >= 10)
    {
        printf("Opcion invalida. Debe ingresar un valor del 0 al 10: ");
        fgets(auxiliar, MAX, stdin);
        auxiliar[strcspn(auxiliar, "\n")] = '\0';
        ejercicio = validar_entero(auxiliar);
    }
    return ejercicio;
}

int validarentradaentero(){
    int ejercicio;
    char auxiliar[MAX];  
    printf("Ingrese un valor entero: ");
    fgets(auxiliar, MAX, stdin);
    auxiliar[strcspn(auxiliar, "\n")] = '\0';
    ejercicio = validar_entero(auxiliar);
    return ejercicio;
}

void vaciarpila(Pila pila){
    TipoElemento te;
    while (!p_es_vacia(pila))
    {
        te = p_desapilar(pila);
    }
    return;
}

