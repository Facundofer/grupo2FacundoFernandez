#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "..\..\validaciones\headers\validaciones.h"
#define MAX 100


void l_vaciar(Lista lista) {
    while (!l_es_vacia(lista)) {
        l_eliminar(lista, 1);  
    }
}

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
           printf("Opcion no valida. Por favor, ingrese un numero: ");
           fgets(entrada, MAX, stdin);
           entrada[strcspn(entrada, "\n")] = '\0';
           validar = false;
       }
       
    }
    return resultado;
}


double validar_real(char *entrada){
    char *validando;
    double resultado;
    bool validar = false;
    while (!validar){
       resultado = strtod(entrada, &validando); 
       validar = true;
       if (entrada == validando || *validando != '\0'){
           printf("Opcion no valida. Por favor, ingrese un numero: ");
           fgets(entrada, MAX, stdin);
           entrada[strcspn(entrada, "\n")] = '\0';
           validar = false;
       }
       
    }
    return resultado;
}

double validarReales(){
    double ejercicio;
    char auxiliar[MAX];  
    printf("Ingrese el valor: ");
    fgets(auxiliar, MAX, stdin);
    auxiliar[strcspn(auxiliar, "\n")] = '\0';
    ejercicio = validar_real(auxiliar);
    return ejercicio;
}

bool validarejercicio(int valor){
    bool validacion = false;
    if (valor >= 2 && valor <=6)
    {
        validacion = true;
    }
    return validacion;
}

int validareleccion(){
    int ejercicio;
    char auxiliar[MAX];  
    printf("Que ejercicio quiere probar del 2 al 6: ");
    fgets(auxiliar, MAX, stdin);
    auxiliar[strcspn(auxiliar, "\n")] = '\0';
    ejercicio = validar_entero(auxiliar);
    while (!validarejercicio(ejercicio))
    {
        printf("Opcion invalida. Debe ingresar un valor del 2 al 6: ");
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
int validartamanolist(){
    int ejercicio;
    char auxiliar[MAX];  
    printf("Ingrese el tamano de la lista: ");
    fgets(auxiliar, MAX, stdin);
    auxiliar[strcspn(auxiliar, "\n")] = '\0';
    ejercicio = validar_entero(auxiliar);
    while (ejercicio <1 || ejercicio >=100)
    {
        printf("Opcion invalida. Debe ingresar un valor del 1 al 100: ");
        fgets(auxiliar, MAX, stdin);
        auxiliar[strcspn(auxiliar, "\n")] = '\0';
        ejercicio = validar_entero(auxiliar);
    }
    return ejercicio;
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


void intercambiar(Cola auxiliar, Cola original){
    Cola cola_aux = c_crear();
    TipoElemento te, aux;
    while(!c_es_vacia(auxiliar)){
        te = c_desencolar(auxiliar);
        aux = te_crear(te->clave);
        c_encolar(original, aux);
    }
}

Cola c_cargar(Cola cola){
    int tamanio, num;
    TipoElemento valor;
    printf("Ingrese el tamanio.\n");
    tamanio = validarentradaentero();
    while(tamanio > 10 || tamanio < 0){
        printf("El tamanio debe ser >= 0 y < 10.\n");
        tamanio = validarentradaentero();
    }
    printf("Ingresando valores.\n");
    for(int i = 0; i < tamanio; i++){
        printf("Ingrese elemento %d\n ", i+1);
        num = validarentradaentero();
        valor = te_crear(num);
        c_encolar(cola, valor);
    }
    return cola;
}

Cola c_cargar_positivos(Cola cola){
    int tamanio, num;
    TipoElemento valor;
    printf("Ingrese el tamanio.\n");
    tamanio = validarentradaentero();
    while(tamanio > 10 || tamanio < 0){
        printf("El tamanio debe ser >= 0 y < 10.\n");
        tamanio = validarentradaentero();
    }
    printf("Ingresando valores.\n");
    for(int i = 0; i < tamanio; i++){
        printf("Ingrese elemento %d\n ", i+1);
        num = validarentradaentero();
        valor = te_crear(num);
        c_encolar(cola, valor);
    }
    return cola;
}


void vaciarcola(Cola cola){
    TipoElemento te;
    while (!c_es_vacia(cola))
    {
        te = c_desencolar(cola);
    }
    return;
}


//Nuevas validaciones

int validareleccion_arboles(){
    int ejercicio;
    char auxiliar[MAX];  
    printf("Que ejercicio quiere probar del 2 al 10: ");
    fgets(auxiliar, MAX, stdin);
    auxiliar[strcspn(auxiliar, "\n")] = '\0';
    ejercicio = validar_entero(auxiliar);
    while (!validarejercicio_arboles(ejercicio))
    {
        printf("Opcion invalida. Debe ingresar un valor del 2 al 10: ");
        fgets(auxiliar, MAX, stdin);
        auxiliar[strcspn(auxiliar, "\n")] = '\0';
        ejercicio = validar_entero(auxiliar);
    }
    return ejercicio;
}


bool validarejercicio_arboles(int valor){
    bool validacion = false;
    if (valor >= 2 && valor <=10)
    {
        validacion = true;
    }
    return validacion;
}

int validarentradaentero_arboles(const char *mensaje) {
    int valor;
    char auxiliar[MAX];
    bool valido = false;

    while (!valido) {
        printf("%s", mensaje);  // muestra el mensaje que vos le pases
        fgets(auxiliar, MAX, stdin);
        auxiliar[strcspn(auxiliar, "\n")] = '\0';
        valor = validar_entero(auxiliar);

        if (esEntero(valor)) {
            valido = true;
        } else {
            printf("Opción no válida. ");
        }
    }

    return valor;
}

double validar_entero_arboles(char *entrada){
    char *validando;
    double resultado;
    bool validar = false;
    while (!validar){
       resultado = strtod(entrada, &validando); 
       validar = true;
        if (strcmp(entrada, ".") == 0) {
        return -99999; // o cualquier valor especial que represente "nulo"
        } else if((entrada == validando || *validando != '\0' || !esEntero(resultado))){
           printf("Opcion no valida. Por favor, ingrese un numero: ");
           fgets(entrada, MAX, stdin);
           entrada[strcspn(entrada, "\n")] = '\0';
           validar = false;
           }
    }
    return resultado;
}

void Cargar_Subarbol(ArbolBinario A, NodoArbol N, int sa){
    TipoElemento X;
    NodoArbol N1;
    int n;
    bool b;
    if (!a_es_lleno(A))
    {
        b = ingresoEntero(&n);
        if (b)
        {
            X = te_crear(n);
            if (sa == -1) N1 = a_conectar_hi(A, N, X);
            else if(sa == 1) N1 = a_conectar_hd(A, N, X);
            else N1 = a_establecer_raiz(A, X);

            Cargar_Subarbol(A, N1, -1);
            Cargar_Subarbol(A, N1, 1);
        }    
    }else{
        printf("Arbol lleno, no puede seguir cargando claves.\n");
        return;
    }   
}

void cargar_arbol_binario(ArbolBinario A){
    Cargar_Subarbol(A, NULL, 0);
}


bool ingresoEntero(int *n){
    char s[10];
    bool resultado = true;
    *n = 0;
    printf("Ingrese una clave numerica o '.' para nulo: ");
    fgets(s, 10, stdin);
    s[strcspn(s, "\n")] = '\0';
    if(s[0] == '.'){
        resultado = false;
    } else {
        *n = validar_entero_arboles(s);
        if (*n == -99999)
        {
            resultado = false;
            return resultado;
        }
        
    }
    return resultado;
}
void Cargar_Subarbol_Natural(ArbolBinario A, NodoArbol N, int sa){
    TipoElemento X;
    NodoArbol N1;
    int n;
    bool b;
    if (!a_es_lleno(A))
    {
        b = ingresoNatural(&n);
        if (b)
        {
            X = te_crear(n);
            if (sa == -1) N1 = a_conectar_hi(A, N, X);
            else if(sa == 1) N1 = a_conectar_hd(A, N, X);
            else N1 = a_establecer_raiz(A, X);

            Cargar_Subarbol_Natural(A, N1, -1);
            Cargar_Subarbol_Natural(A, N1, 1);
        }    
    }else{
        printf("Arbol lleno, no puede seguir cargando claves.\n");
        return;
    }   
}
void cargar_arbol_binario_Natural(ArbolBinario A){
    Cargar_Subarbol_Natural(A, NULL, 0);
}
bool ingresoNatural(int *n){
    char s[10];
    bool resultado = true;
    *n = 0;
    printf("Ingrese una clave numerica o '.' para nulo: ");
    fgets(s, 10, stdin);
    s[strcspn(s, "\n")] = '\0';
    if(s[0] == '.'){
        resultado = false;
    } else {
        *n = validar_entero_arboles(s);
        if (*n == -99999)
        {
            resultado = false;
            return resultado;
        }
        while(*n < 0 && *n != -99999){
            printf("No se permiten negativos. Vuelva a intentarlo.");
            fgets(s, 10, stdin);
            s[strcspn(s, "\n")] = '\0';
            *n = validar_entero_arboles(s);
            if (*n == -99999)
            {
                resultado = false;
                return resultado;
            }
        }
        
    }
    return resultado;
}

void pre_orden(NodoArbol N){
    TipoElemento x;
    if (a_es_rama_nula(N)){//N == NULL
        printf(".");
    }
    else{
        x = n_recuperar(N);
        printf(" %d", x->clave);
        pre_orden(n_hijoizquierdo(N)); 
        pre_orden(n_hijoderecho(N));
    }
}
void in_orden(NodoArbol N){
    TipoElemento x;
    if (a_es_rama_nula(N)) {//N == NULL
        printf(".");
    }
    else {
        in_orden(n_hijoizquierdo(N));
        x = n_recuperar(N);
        printf(" %d", x->clave);
        in_orden(n_hijoderecho(N));
    }
}

void post_orden(NodoArbol N){
    TipoElemento x;
    if (a_es_rama_nula(N)){ //N == NULL
        printf(".");
    }
    else{
        post_orden(n_hijoizquierdo(N));
        post_orden(n_hijoderecho(N));
        x = n_recuperar(N);
        printf(" %d", x->clave); 
    }
}
