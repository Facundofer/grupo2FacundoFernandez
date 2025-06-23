#include <stdbool.h>
#include "..\..\pilas\headers\pilas.h"
#include "..\..\..\libs\colas\headers\colas.h"
#include "..\..\..\libs\listas\headers\listas.h"
#include "..\..\..\libs\arboles\headers\arbol-binario.h"
#include "..\..\..\libs\arboles\headers\nodo.h"
#include "..\..\..\libs\hash\headers\tabla_hash.h"
#include "..\..\..\libs\arboles\headers\arbol-avl.h"
#include "..\..\..\libs\conjuntos\headers\conjuntos.h"

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


// validaciones nuevas hash
//agregado
void cargar_arbolavl_tablahash_aleatorios(ArbolAVL AVL, TablaHash TH, int cant_numeros, int min, int max);

void buscar_elemento(NodoArbol nodo, int clave, bool *busqueda);

int funcion_hash(int a);

int hash_function(int clave);

void dar_de_alta(TablaHash tab, int cant_alumnos);

void crear_archivo();

void modificar_alumno(TablaHash tab, int legajo);

void dar_de_baja(TablaHash tab, int legajo);

void mostrar_archivo();

void cargar_arbolavl_tablahash_aleatorios(ArbolAVL AVL, TablaHash TH, int cant_numeros, int min, int max);

void buscar_elemento(NodoArbol nodo, int clave, bool *busqueda);

void th_ej5_comparacion(int q_claves, int q_repeticiones, int rango_desde, int rango_hasta);

void crear_archivo_paciente();

void dar_de_alta_paciente(TablaHash tab, int cantidad);

void modificar_paciente(TablaHash tab, int dni, int fecha);

Lista consultar_vacunados_fecha(TablaHash tab, int clave);

void l_mostrar_con_valor(Lista L);

void dar_de_baja_paciente(TablaHash tab, int dni, int fecha);

bool validarcadena(char cadena[]);

bool tiene6digitos(char *cadena);

bool tiene8digitos_DNI(int numero);

bool es_vacio(const char *str);

int primo_mas_cercano(int numero);

struct paciente buscar_por_dni(const char* nombre_archivo, int dni_buscado);

struct alumno buscar_por_legajo(const char* nombre_archivo, int legajo_buscar);
void mostrar_archivo_pacientes();

//Validaciones conjuntos
int validar_tamanio();
void cargar_conjunto(Conjunto cto);
void cargar_numeros_naturales(Conjunto cto);
void carga_random_conjunto(Conjunto cto, int tamanio);
bool c_ej2_pertenencia(Conjunto A, int clave);
void coleccion_conjuntos(Lista l_conjuntos);
void mostrar_con_valor(Lista l_conjuntos);
void vaciar_conjunto(Conjunto cto);
bool pertenencia_auxiliar(Conjunto A, Conjunto B);