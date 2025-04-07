#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "tp_1_recursividad.h"


#define MAX 100

bool validar_cadena_numerica(char *cadena){
    int longitud = strlen(cadena) - 1;
    bool resultado;
    for(int i = 0; i<longitud; i++){
        if(cadena[i] >= 48 && cadena[i] <= 57){
            resultado = true;
        }
        else{
            resultado = false;
        }
    }
    return resultado;
}

char* validaronda(char* input) {
    if (input == NULL) return NULL;
    
    int len = strlen(input);
    // Eliminar el salto de línea si existe (por fgets)
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
        len--;
    }

    // Validar caracteres
    for (int i = 0; i < len; i++) {
        char c = toupper(input[i]); // Convertir a mayúscula
        if (c != 'L' && c != 'H') {
            return NULL;
        }
    }

    // Normalizar a mayúsculas
    for (int i = 0; i < len; i++) {
        input[i] = toupper(input[i]);
    }

    return input;
}
void main(){
    int valor, numero , numero2, i=0 ;
    char *numeroVec;
    char *Cadena;
    char **CadenaVec;
    int *resultados;
    char aux[MAX];
    bool validar;

    printf("Ingresa un valor de 1 a 10 para eleguir el ejercicio, -1 para salir: ");
    scanf("%d", &valor);
    while (valor != -1){
        switch (valor)
        {
        case 1:
            printf("Ejercicio 1: Saber si es palindromo.\n");
            getchar();
            Cadena = (char *)malloc(MAX*sizeof(char)); 
            printf("Ingrese cadena: ");
            fgets(Cadena, MAX, stdin);
            if (Cadena[strlen(Cadena) - 1] == '\n') {
                Cadena[strlen(Cadena) - 1] = '\0';
            }
            while (strlen(Cadena) == 0) {
                printf("La cadena no puede estar vacia, Ingrese cadena nuevamente: ");
                fgets(Cadena, MAX, stdin);
                
                if (Cadena[strlen(Cadena) - 1] == '\n') {
                    Cadena[strlen(Cadena) - 1] = '\0';
                }
            }
            bool resultado;
            resultado = palindromo(Cadena);
            
            if(resultado == true){
                printf("Es palindromo\n");
            }
            else{
                printf("No es palindromo\n");
            }
            free(Cadena);   
            break;
        case 2:
            getchar();
            printf("Ejercicio 2: Producto de dos numeros.\n");
            printf("Ingrese el Primer valor (entero positivo): ");
            fgets(aux,MAX,stdin);
            aux[strcspn(aux,"\n")] ='\0';
            validar = false;
            while (!validar) {
                numero = strtol(aux, &Cadena, 10);
                validar = true;
                if (aux == Cadena || *Cadena != '\0'){
                    printf("Ingrese una valor válido: ");
                    fgets(aux, MAX, stdin);
                    aux[strcspn(aux, "\n")] = '\0';
                    validar = false;
                    fflush(stdin);
                }
            }
            
            printf("Ingrese el Segundo valor (entero positivo): ");
            fgets(aux,MAX,stdin);
            aux[strcspn(aux,"\n")] ='\0';
            validar = false;
            while (!validar) { 
                numero2 = strtol(aux, &Cadena, 10);
                validar = true;
                if (aux == Cadena || *Cadena != '\0'){
                    printf("Ingrese una valor válido: ");
                    fgets(aux, MAX, stdin);
                    aux[strcspn(aux, "\n")] = '\0';
                    validar = false;
                    fflush(stdin);
                }
            }
        
            valor = producto(numero, numero2);
            printf("El producto entre %d y %d es: %d\n", numero, numero2, valor);
            break;
        case 3:
            getchar();
            printf("Ejercicio 3: Serie figonacci.\n");
            printf("Ingrese valor para calcular la serie: ");
            fgets(aux,MAX,stdin);
            aux[strcspn(aux,"\n")] ='\0';
            validar = false;
            while (!validar) { 
                numero = strtol(aux, &Cadena, 10);
                validar = true;
                if (aux == Cadena || *Cadena != '\0'){
                    printf("Ingrese una valor válido: ");
                    fgets(aux, MAX, stdin);
                    aux[strcspn(aux, "\n")] = '\0';
                    validar = false;
                    fflush(stdin);
                }
            }
            valor = terminoSeridFibonacci(numero + 1 );
            printf("el resultado de calcular el kenesimo de fibonacci con %d es %d\n", numero, valor);
            break;
        case 4:
            getchar();
            printf("Ejercicio 4: Cociente de dos valores.\n");
            printf("Ingrese el divisor: ");
            fgets(aux,MAX,stdin);
            aux[strcspn(aux,"\n")] ='\0';
            validar = false;
            while (!validar) { 
                numero = strtol(aux, &Cadena, 10);
                validar = true;
                if (aux == Cadena || *Cadena != '\0'){
                    printf("Ingrese una valor válido: ");
                    fgets(aux, MAX, stdin);
                    aux[strcspn(aux, "\n")] = '\0';
                    validar = false;
                    fflush(stdin);
                }
            }
            printf("Ingrese el dividendo: ");
            fgets(aux,MAX,stdin);
            aux[strcspn(aux,"\n")] ='\0';
            validar = false;
            while (!validar) { 
                numero2 = strtol(aux, &Cadena, 10);
                validar = true;
                if (aux == Cadena || *Cadena != '\0'){
                    printf("Ingrese una valor válido: ");
                    fgets(aux, MAX, stdin);
                    aux[strcspn(aux, "\n")] = '\0';
                    validar = false;
                    fflush(stdin);
                }
            }
            
            valor = division(numero, numero2);
            printf("El cocientre entre %d y %d es: %d\n", numero, numero2, valor);
            break;
        case 5:
            getchar();
            printf("Ejercicio 5: Ponga los puntos de los miles a un String\n");

            numeroVec = malloc(100 * sizeof(char));
            Cadena = NULL;
        
            // Validar entrada
            bool validar = false;
            do {
                printf("Ingresar cadena numérica: ");
                fgets(numeroVec, 100, stdin);
                numeroVec[strcspn(numeroVec, "\n")] = '\0'; // Eliminar salto de línea
        
                validar = validar_cadena_numerica(numeroVec);
                if (!validar) {
                    printf("Error: Solo se permiten caracteres numéricos.\n");
                }
            } while (!validar);
        
            Cadena = agregarSeparadorMiles(numeroVec);
            printf("Resultado: %s\n", Cadena);
        
            // Liberar memoria
            free(numeroVec);
            free(Cadena);
            break;
        case 6:
            getchar();
            Cadena = malloc(100 * sizeof(char));
            printf("Ejercicio 6: a Mafia china.\n");
            printf("Ingrese valor para ver la mafia: ");
            fgets(aux,MAX,stdin);
            aux[strcspn(aux,"\n")] ='\0';
            validar = false;
            while (!validar) { 
                numero = strtol(aux, &Cadena, 10);
                validar = true;
                if (aux == Cadena || *Cadena != '\0'){
                    printf("Ingrese una valor válido: ");
                    fgets(aux, MAX, stdin);
                    aux[strcspn(aux, "\n")] = '\0';
                    validar = false;
                    fflush(stdin);
                }
            }
            Cadena = reunionMafia(numero);
            printf("%s", Cadena);
            free(Cadena);
            break;
        case 7:
            getchar();
            printf("Ejercicio 7: Onda digital.\n");
            numeroVec = malloc(100 * sizeof(char));
            Cadena = malloc(100 * sizeof(char));  
            printf("Ingrese la Onda (L,l,H,h):\n");
            fgets(numeroVec, 100, stdin);
            while (validaronda(numeroVec) == NULL) {
                printf("Cadena inválida. Solo se permiten caracteres L, l, H, h sin espacios.\n");
                printf("Ingrese la Onda (L,l,H,h):\n");
                fgets(numeroVec, 100, stdin);
            }
            ondaDigital(numeroVec);
            strcpy(Cadena, ondaDigital(numeroVec));
            printf("%s\n", Cadena);
            free(numeroVec);
            free(Cadena);
            break;
        case 8:
            getchar();
            CadenaVec = malloc(MAX*(sizeof(char*)));
            for (int i = 0; i < MAX; i++) {
                CadenaVec[i] = NULL;
            }
            printf("Ingrese el tamanio del conjunto: ");
            fgets(aux,MAX,stdin);
            aux[strcspn(aux,"\n")] ='\0';
            validar = false;
            while (!validar) { 
                numero = strtol(aux, &Cadena, 10);
                validar = true;
                if (aux == Cadena || *Cadena != '\0'){
                    printf("Ingrese una valor válido: ");
                    fgets(aux, MAX, stdin);
                    aux[strcspn(aux, "\n")] = '\0';
                    validar = false;
                    fflush(stdin);
                }
            }
            printf("Ingrese el valor a sumar: ");
            fgets(aux,MAX,stdin);
            aux[strcspn(aux,"\n")] ='\0';
            validar = false;
            while (!validar) { 
                numero2 = strtol(aux, &Cadena, 10);
                validar = true;
                if (aux == Cadena || *Cadena != '\0'){
                    printf("Ingrese una valor válido: ");
                    fgets(aux, MAX, stdin);
                    aux[strcspn(aux, "\n")] = '\0';
                    validar = false;
                    fflush(stdin);
                }
            }
            for (int i = 0; i < numero; i++) {
                printf("Ingrese el valor %d del conjunto: ", i+1);
                fgets(aux, MAX, stdin);
                aux[strcspn(aux, "\n")] = '\0';
                validar = false;
                while (!validar){
                    validar = true;
                    if(atoi(aux) == 0){
                        printf("Ingrese una valor válido: ");
                        fgets(aux, MAX, stdin);
                        aux[strcspn(aux, "\n")] = '\0';
                        validar = false;
                    }
                }
                resultados[i] = atoi(aux);
            }
            subconjuntosQueSumanN(resultados, numero, numero2, CadenaVec);
            printf("Subconjuntos que suman %d:\n", numero2);
            for (int i = 0; CadenaVec[i] != NULL; i++) {
                printf("%s\n", CadenaVec[i]);
                free(CadenaVec[i]);
            }
            break;
        case 9:
        getchar();
        printf("Ejercicio 9: Divisible por 7.\n");
        printf("Ingrese el Valor a verificar: ");
        fgets(aux,MAX,stdin);
        aux[strcspn(aux,"\n")] ='\0';
        validar = false;
        while (!validar) { 
            numero = strtol(aux, &Cadena, 10);
            validar = true;
            if (aux == Cadena || *Cadena != '\0'){
                printf("Ingrese una valor válido: ");
                fgets(aux, MAX, stdin);
                aux[strcspn(aux, "\n")] = '\0';
                validar = false;
                fflush(stdin);
            }
        }
            validar = divisiblePor7(numero);
            if(validar == true){
                printf("Es divisible\n");
            }
            else{
                printf("No es divisible\n");
            }
            break; 
        case 10:
            getchar();
            resultados = malloc(100 * sizeof(int));
            printf("Ejercicio 10: Número explosivo.\n");
            printf("Ingrese el Valor Explosvo: ");
            fgets(aux,MAX,stdin);
            aux[strcspn(aux,"\n")] ='\0';
            validar = false;
            while (!validar) { 
                numero = strtol(aux, &Cadena, 10);
                validar = true;
                if (aux == Cadena || *Cadena != '\0' || numero < 0){
                    printf("Ingrese una valor válido: ");
                    fgets(aux, MAX, stdin);
                    aux[strcspn(aux, "\n")] = '\0';
                    validar = false;
                    fflush(stdin);
                }
            }
            printf("Ingrese la Bomba: ");
            fgets(aux,MAX,stdin);
            aux[strcspn(aux,"\n")] ='\0';
            validar = false;
            while (!validar) { 
                numero2 = strtol(aux, &Cadena, 10);
                validar = true;
                if (aux == Cadena || *Cadena != '\0' || numero2 < 0){
                    printf("Ingrese una valor válido: ");
                    fgets(aux, MAX, stdin);
                    aux[strcspn(aux, "\n")] = '\0';
                    validar = false;
                    fflush(stdin);
                }
            }
            resultados = explosion (numero, numero2);
            while (resultados[i] != -1)
            {
                printf("%d", resultados[i]);
                i++;
            }
            printf("\n");
            
            break; 
        
        default:
            break;
        }
        printf("Ingresa un valor de 1 a 10 para eleguir el ejercicio, -1 para salir: ");
        scanf("%d", &valor);  
    }
    printf("Gracias por su tiempo.");

}