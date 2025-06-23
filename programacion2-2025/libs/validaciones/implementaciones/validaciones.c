#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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


//-------------------------------------Nuevas validaciones ARBOLES---------------------------------------------

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
            printf("Opcion no valida. ");
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

//-------------------------------Nuevas validaciones HASH---------------------------------------------------

bool validarcadena(char cadena[]){
    int i, cantidad_letras;
    bool validado;
    i=0;
    validado= true;
    cantidad_letras= strlen(cadena);
    while ((validado==true) && (i<cantidad_letras)){
        if ((cadena[i]>=65 && cadena[i]<=90) || (cadena[i]>=97 && cadena[i]<=122)){
            validado=true;
            i++;
        }
        else{
            validado=false;
        }
    }

    return validado;
}

bool tiene6digitos(char *cadena) {
    return strlen(cadena) == 6;
}

bool tiene8digitos_DNI(int numero) {
    char cadena[20];  // Tamanio suficientemente grande para contener el numero convertido en cadena
    sprintf(cadena, "%d", numero);  // Convertir el numero en cadena

    int longitud = 0;
    while (cadena[longitud] != '\0') {
        longitud++;  // Calcular la longitud de la cadena
    }

    if (longitud == 8){
        return true;
    }
    else{
        return false;
    } 
}

bool es_vacio(const char *str) {
    if (str == NULL) return true;
    for (; *str; str++) if (!isspace(*str)) return false;
    return true;
}


bool es_primo(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}
// Funcion principal que encuentra el primo mas cercano
int primo_mas_cercano(int numero) {
    if (numero <= 1) return 2; // El primer primo es 2
    
    // Si el numero es primo, lo devolvemos directamente
    if (es_primo(numero)) {
        return numero;
    }
    
    int primo_menor = numero - 1;
    int primo_mayor = numero + 1;
    
    // Buscamos el primo menor mas cercano
    while (primo_menor >= 2) {
        if (es_primo(primo_menor)) {
            break;
        }
        primo_menor--;
    }
    
    // Buscamos el primo mayor mas cercano
    while (true) {
        if (es_primo(primo_mayor)) {
            break;
        }
        primo_mayor++;
    }
    // Determinamos cual esta mas cerca
    if (abs(numero - primo_menor) <= abs(primo_mayor - numero)) {
        return primo_menor;
    } else {
        return primo_mayor;
    }
}

//validaciones conjuntos------------------------------------------------------------------------------------------------------------------

int validar_tamanio(){
    int tamanio = validarentradaentero_arboles("Ingrese el tamanio del conjunto: ");    
    while(tamanio < 0 || tamanio >= 10){
        printf("El tamanio debe ser menor a 10.\n");
        tamanio = validarentradaentero_arboles("Ingrese el tamanio del conjunto: ");
    }
    return tamanio;
}

void cargar_conjunto(Conjunto cto){
    int clave;
    TipoElemento te;
    int salida;
    printf("¿Quiere cargar elementos al conjunto?\n");
    salida = validarsalida();
    while(!cto_es_lleno(cto) && salida != -1){
        clave = validarentradaentero_arboles("Ingrese la clave a agregar: ");
        te = te_crear(clave);
        if(cto_agregar(cto, te)){
            printf("Clave agregada con exito!\n");
        }else{
            printf("La clave ya existe dentro del conjunto. Vuelva a intentarlo.\n");
        }
        salida = validarsalida();
    }
    if(cto_es_lleno(cto)){
        printf("El conjunto ya esta lleno.\n");
        return;
    }
    return;
}

void cargar_numeros_naturales(Conjunto cto){
    int clave;
    TipoElemento te;
    int salida;
    printf("¿Quiere cargar elementos al conjunto?\n");
    salida = validarsalida();
    while(!cto_es_lleno(cto) && salida != -1){
        clave = validarentradaentero_arboles("Ingrese la clave a agregar: ");
        while(clave < 0){
            printf("SOLO SE PERMITEN NUMEROS POSITIVOS.\n");
            clave = validarentradaentero_arboles("Ingrese la clave a agregar: ");
        }
        te = te_crear(clave);
        if(cto_agregar(cto, te)){
            printf("Clave agregada con exito!\n");
        }else{
            printf("La clave ya existe dentro del conjunto. Vuelva a intentarlo.\n");
        }
        salida = validarsalida();
    }
    if(cto_es_lleno(cto)){
        printf("El conjunto ya esta lleno.\n");
        return;
    }
    return;
}

/*void carga_random_conjunto(Conjunto cto, int tamanio){
    TipoElemento te;
    int i = 1;
    while(i <= tamanio){
        te = te_crear(0+ rand() % (100+1 - 0)); //ver si da negativos
        if(cto_agregar(cto, te)){
            i++;
        }
    }
}*/

void coleccion_conjuntos(Lista l_conjuntos){
    int salida = 0;
    while(salida != -1){
        Conjunto A = cto_crear();
        cargar_conjunto(A);
        l_agregar(l_conjuntos, te_crear_con_valor(0, A));
        printf("¿Quiere agregar otro conjunto a la coleccion?\n");
        salida = validarsalida();
    }
    return;
}

void mostrar_con_valor(Lista l_conjuntos){
    Iterador ite = iterador(l_conjuntos);
    TipoElemento te;
    Conjunto aux;
    while(hay_siguiente(ite)){
        te = siguiente(ite);
        aux = (Conjunto) te->valor;
        cto_mostrar(aux);
        printf("\n\n");
    }
    return;
}

void vaciar_conjunto(Conjunto cto){
    if(cto_es_vacio(cto)){
        return;
    }
    TipoElemento te;
    int tamanio = cto_cantidad_elementos(cto);
    for(int i = tamanio; i >= 1; i--){
        te = cto_recuperar(cto, i);
        cto_borrar(cto, te->clave);
    }
    return;
}

bool pertenencia_auxiliar(Conjunto A, Conjunto B){
    int tamano = cto_cantidad_elementos(A);
    TipoElemento te;
    if(cto_es_vacio(A)){
        return true;
    }else if(!cto_es_vacio(A) && cto_es_vacio(B)){
        return false;
    }else{
        for (int i = 1; i <= tamano; i++)
        {
            te = cto_recuperar(A, i);
            if (!cto_pertenece(B, te->clave))
            {
                return false;
            }  
        }     
    }
    
    return true;
}