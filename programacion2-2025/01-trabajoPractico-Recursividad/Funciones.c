#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "tp_1_recursividad.h"

// Ejercicio 1:

bool palindromorecursivo(char *str,int inicio, int fin){
    bool resultado;
    // si el inicio(extremo izquierda) de la cadena no es igual al final(extremo derecha)
    if(str[inicio] != str[fin]){
        resultado = false;
    }
    // sino si el final es mayor o igual a 0 (quiere decir que la cadena tiene caracteres todavia)
    // y ademas el inicio es igual al final, resultado sera verdadero y se llamara con inicio + 1 y el final - 1
    else if(fin >= 0 && str[inicio] == str[fin]){
        resultado = true;
        palindromorecursivo(str,inicio + 1,fin -1);
    }
    return resultado;
}
bool palindromo(char *cadena){
    int longitud = strlen(cadena) -1;
    bool resultado;
    resultado = palindromorecursivo(cadena,0,longitud);
    return resultado;
}

// Ejercicio 2:


int productorecursivo(int num1, int num2, int *acum){
    if(num2 == 0){
        return 1;
    }
    else{
        *acum = *acum + num1;
        productorecursivo(num1,num2-1,acum);
    }
}
int producto(int m,int n){
    int resultado;
    int acumulador = 0;
    int *acum;
    acum = &acumulador;
    productorecursivo(m,n,acum);
    return acumulador;
}

// Ejercicio 3:
int terminoSeridFibonacci(int k) {
    if (k <= 1) {
        return k;
    } else {
        return terminoSeridFibonacci(k - 1) + terminoSeridFibonacci(k - 2);
    }
}



// Ejercicio 4:


float decimales(int m, int n, int final, int resul_dec){
    if(final < 0){
        return resul_dec;
    }
    if(m >= n){
        resul_dec+=1;
        return decimales((m - n), n, final, resul_dec);
    }
    if(m < n){
        return decimales(m*10, n, final-1, resul_dec*10);
    }
}

float division(int m, int n){
    float resultado, dec;
    if(m < n){
        dec = decimales(m, n, 5, 0);
        resultado += (dec * 0.000001);
        return resultado;
    }
    resultado = division((m - n), n) + 1;   
}

// Ejercicio 5:

void agregarSeparadorMilesRecursivo(const char* numero, char* resultado, int longitud) {
    //caso base la longitud llegó al inicio del vector de caracteres
    if (longitud <= 3) {
        //apilo en el resultado la cantidad de caracteres almacenada en longitud (parámetro que entró en la ultima llamada)
        strncat(resultado, numero, longitud);
        //resultado ->[4,5,6]
        return;
    }
    //inicio de la recursión
    agregarSeparadorMilesRecursivo(numero, resultado, longitud-3);
    //apilo el punto al inicio del vector de caracters
    strcat(resultado,".");
    //resultado ->[.,4,5,6]
    //apilo 3 caracteres basandome en la longitud (parametro que entró en la llamada de recursión anterior)
    strncat(resultado,numero+strlen(numero)-3,3);
    //[1,2,3,.,4,5,6]
    return;
}

char* agregarSeparadorMiles(char numero[]) {
       // Verificar si el número es negativo
    int es_negativo = (numero[0] == '-');
    // Calcular la longitud del número
    int longitud = strlen(numero);
    // Si es negativo, eliminar el signo '-' y ajustar la longitud
    if (es_negativo) {
        memmove( (char*)numero, (char*)numero + 1, longitud); 
        longitud--; 
    }
    //creo un vector dinámico en el que almacenar el resultado
    char* resultado =malloc((longitud + (longitud / 3) + 1) * sizeof(char));
    resultado[0]='\0';
    //inicio de la recursión
    agregarSeparadorMilesRecursivo(numero, resultado, longitud);
       if (es_negativo) {
    memmove((char*)resultado + 1, (char*)resultado, longitud + 1);
    resultado[0] = '-'; 
    }
    return resultado;
}


// Ejercicio 6:

void agregarEspacios(int espacios, char* chinos) {
    if (espacios <= 0) {
        return;
    }
    strcat(chinos, " ");
    agregarEspacios(espacios - 1, chinos);
}

void reunionMafiacorp(int Nivel_reunion, char* chinos) {
    char chino[] = "(-.-)";
    char chinoizq[] = "(-.";
    char chinoder[] = ".-)";

    if (Nivel_reunion == 1) {
        strcat(chinos, chino);
        return;
    }

    strcat(chinos, chinoizq);
    reunionMafiacorp(Nivel_reunion - 1, chinos);
    strcat(chinos, chinoder);
}

void llamarrmafia(int Nivel_reunion, int inicio, char* chinos) {
    if (inicio == Nivel_reunion) {
        return;
    }

    int espacios = (Nivel_reunion - (inicio + 1)) * 2;
    agregarEspacios(espacios, chinos);  // <-- Recursión en lugar del for
    reunionMafiacorp(inicio + 1, chinos);
    strcat(chinos, "\n");
    llamarrmafia(Nivel_reunion, inicio + 1, chinos);
}

char* reunionMafia(int Nivel_reunion) {
    int largo_total = (Nivel_reunion * 6 * Nivel_reunion);
    char* chinos = malloc(largo_total * sizeof(char));
    chinos[0] = '\0';
    llamarrmafia(Nivel_reunion, 0, chinos);
    return chinos;
}
// Ejercicio 7:

char *ondaDigitalrec(char *OndaDigital, int longitud,int cont,char *OndaResultado) {
    char barra[]="|";
    char guionb[]="_";
    char guiona[]="¯";
    if (longitud == cont){
        return OndaResultado;
    }
    if (OndaDigital[cont]=='H'||OndaDigital[cont]=='h'){
        if(OndaDigital[cont-1]=='L'||OndaDigital[cont-1]=='l'){
        strcat(OndaResultado, barra);
        strcat(OndaResultado, guiona);
        ondaDigitalrec(OndaDigital, longitud,cont+1,OndaResultado); 
        }else{
        strcat(OndaResultado, guiona);
        ondaDigitalrec(OndaDigital, longitud,cont+1,OndaResultado); 
        }

    }
    else if (OndaDigital[cont]== 'L'|| OndaDigital[cont]=='l'){
        if(OndaDigital[cont-1]=='h'||OndaDigital[cont-1]=='H'){
        strcat(OndaResultado, barra);
        strcat(OndaResultado, guionb);
        ondaDigitalrec(OndaDigital, longitud,cont+1,OndaResultado);  
        }else{    
        strcat(OndaResultado, guionb);
        ondaDigitalrec(OndaDigital, longitud,cont+1,OndaResultado);   
        }
    }
    else{
        return NULL;
    }
    
}

char *ondaDigital(char* cadena){
    int longitud=strlen(cadena);
    char *OndaResultado=malloc(sizeof(char)*100);
    OndaResultado[0]='\0';
    return ondaDigitalrec(cadena,longitud,0,OndaResultado);    
}


// Ejercicio 8:


// Función auxiliar recursiva para construir la cadena del subconjunto
void agregarElementosRecursivo(int *subconjunto, int pos, int tamSubconjunto, char *buffer) {
    if (pos >= tamSubconjunto) {
        return;
    }

    char numStr[10];
    sprintf(numStr, "%d", subconjunto[pos]);
    strcat(buffer, numStr);

    if (pos < tamSubconjunto - 1) {
        strcat(buffer, ", ");
    }

    agregarElementosRecursivo(subconjunto, pos + 1, tamSubconjunto, buffer);
}
void agregarSubconjunto(int *subconjunto, int tamSubconjunto, char **output, int *index) {
    if (tamSubconjunto == 0) {
        output[*index] = strdup("{}");
        (*index)++;
       // *(index + 1) = '\0';
        return;
    }

    char buffer[100] = "{";
    agregarElementosRecursivo(subconjunto, 0, tamSubconjunto, buffer);
    strcat(buffer, "}");
    output[*index] = strdup(buffer);
    (*index)++;
}

// Función recursiva principal para buscar subconjuntos que sumen `n`
void buscarSubconjuntos(int conjunto[], int tamano, int n, int *subconjunto, int tamSubconjunto, int pos, int sumaActual, char **output, int *index) {
    if (sumaActual == n && tamSubconjunto > 0) {
        agregarSubconjunto(subconjunto, tamSubconjunto, output, index);
        return;
    }

    if (pos >= tamano || sumaActual > n) {
        return;
    }

    // Incluir el elemento actual (backtracking)
    subconjunto[tamSubconjunto] = conjunto[pos];
    buscarSubconjuntos(conjunto, tamano, n, subconjunto, tamSubconjunto + 1, pos + 1, sumaActual + conjunto[pos], output, index);

    // Excluir el elemento actual
    buscarSubconjuntos(conjunto, tamano, n, subconjunto, tamSubconjunto, pos + 1, sumaActual, output, index);
}

// Función principal (interfaz)
void subconjuntosQueSumanN(int conjunto[], int tamano, int n, char **output) {
    int *subconjunto = malloc(tamano * sizeof(int));
    int index = 0;
    buscarSubconjuntos(conjunto, tamano, n, subconjunto, 0, 0, 0, output, &index);
    free(subconjunto);
}

// Ejercicio 9:

bool divisiblePor7(int num) {

    //módulo del numero para verificar si es negativo
    num = abs(num);

    // Caso base: el número es 0 o menor que 70
    
    if (num == 0 || num < 70) {
        return (num == 0 || num % 7 == 0) ? true : false;
    }

    // Extraemos la última cifra (derecha) y el resto del número (izquierda)
    int ultima_cifra = num % 10;
    int resto = num / 10;

    // Multiplicamos la última cifra por 2
    ultima_cifra *= 2;

    // Restamos el resultado del resto del número
    int nuevo_numero = resto - ultima_cifra;

    // Llamada recursiva con el nuevo número
    return divisiblePor7(nuevo_numero);

} 

// Ejercicio 10:

void explosion_recursiva(int N, int B, int *resultados, int *indice) {
    // caso base y de corte: si N es menor o igual a la bomba entonces se agrega ese valor al vector y deja de explotar
    if (N <= B) {
        resultados[*indice] = N;
        (*indice)++;
    }
    // sino cetea n1 y n2 con sus valores y llama con los dos, si n1 o n2 es menor que la bomba cuando entra a la llamada
    // va a entrar al caso base y a agregarse al vector sumando en 1 el indice
    else {
        int n1 = N / B;
        int n2 = N - (N / B);
        
        explosion_recursiva(n1, B, resultados, indice);
        explosion_recursiva(n2, B, resultados, indice);
    }
}

int* explosion(int N, int B) {
    int *resultados = malloc(100 * sizeof(int));
    int indice = 0;
    
    explosion_recursiva(N, B, resultados, &indice);
    *(resultados + indice) = -1;
    return resultados;
}