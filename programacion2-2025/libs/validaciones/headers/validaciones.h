#include <stdbool.h>
#include "..\..\pilas\headers\pilas.h"
#include "..\..\..\libs\colas\headers\colas.h"
#include "..\..\..\libs\listas\headers\listas.h"

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