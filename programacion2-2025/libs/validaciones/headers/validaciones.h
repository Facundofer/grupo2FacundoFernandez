#include <stdbool.h>
#include "..\..\pilas\headers\pilas.h"
#include "..\..\..\libs\colas\headers\colas.h"
#include "..\..\..\libs\listas\headers\listas.h"
#include "..\..\..\libs\arboles\headers\arbol-binario.h"
#include "..\..\..\libs\arboles\headers\nodo.h"
void l_vaciar(Lista lista);

double validar_entero(char *entrada);

bool validarejercicio(int valor);

int validareleccion();

bool validarcontinuacion(int valor);

int validarsalida();

bool esEntero(double valor);

double validar_real(char *entrada);

double validarReales();

int validartamanolist();

Pila cargarpila(int elementos);

void P_intercambiar(Pila pila, Pila auxi);

int validartamanopila();

int validarentradaentero();

void vaciarpila(Pila pila);

void intercambiar(Cola auxiliar, Cola original);

Cola c_cargar(Cola cola);

Cola c_cargar_positivos(Cola cola);

void vaciarcola(Cola cola);


//Nuevas

// validaciones nuevas arboles.
double validar_entero_arboles(char *entrada);

int validarentradaentero_arboles(const char *mensaje);

bool validarejercicio_arboles(int valor);

int validareleccion_arboles();

void cargar_arbol_binario_Natural(ArbolBinario A);

bool ingresoNatural(int *n);

void Cargar_Subarbol_Natural(ArbolBinario A, NodoArbol N, int sa);

void Cargar_Subarbol(ArbolBinario A, NodoArbol N, int sa);

void cargar_arbol_binario(ArbolBinario A);

bool ingresoEntero(int *n);

void pre_orden(NodoArbol N);

void in_orden(NodoArbol N);

void post_orden(NodoArbol N);

void recorrer_arbol_2a(NodoArbol nodo, Lista L);

void recorrer_arbol_2b(NodoArbol nodo, Lista L);

void recorrer_arbol_2c(NodoArbol nodo, Lista L);

void recuperar_padre(NodoArbol nodo, int clave, TipoElemento padre);
