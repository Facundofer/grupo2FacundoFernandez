#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "..\libs\colas\headers\colas.h"
#include "..\libs\listas\headers\listas.h"
#include "..\libs\pilas\headers\pilas.h"
#include "..\libs\hash\headers\tabla_hash.h"
#include "..\libs\arboles\headers\arbol-avl.h"
#include "..\libs\validaciones\headers\validaciones.h"
#include "tp_thash.h"
#define STR_MAX 100
#define NUMERO_PRIMO_5 997
int NUMERO_PRIMO;


//funcion hash
int hash_function(int clave){
    int pos = clave % NUMERO_PRIMO;
    return pos;
}

int funcion_hash(int a){
    int poss= (a % NUMERO_PRIMO_5);
    return poss;
}

//-------------------------------------- Ejercicio 4 ------------------------------------------------------------------

typedef struct alumno{
    int legajo;
    char apellido[STR_MAX];
    char nombre[STR_MAX];
    char domicilio[STR_MAX];
    int telefono;
    bool de_baja;
}alumno;

//funcion de carga - eliminacion - modificacion

void crear_archivo(){
    FILE *f;
    f = fopen("legajo_alumnos.dat", "w+b");
    printf("ARCHIVO CREADO CON EXITO! \n");
    fclose(f);
}

//FUNCION DAR DE ALTA----------------------------------------------------------------------------------------------------------------------------------------------------------------------
void dar_de_alta(TablaHash tab, int cant_alumnos){
    TipoElemento te;
    int i = 0;
    char *entrada = malloc(sizeof(char)*20);
    int *posicion, num_registro = 0; 
    struct alumno *alum_1 = malloc(sizeof(struct alumno));
    struct alumno alum_aux;
    FILE *f;
    //R+B Apertura de un archivo binario para actualizar permitiendo lectura y escritura. Si no existe genera un error.
    if((f = fopen("legajo_alumnos.dat", "r+b")) == NULL){
        printf("No se pudo abrir el archivo.\n");
    }
    while(i < cant_alumnos){
        //Obtener la posicion en la que se encuentra el registro a guardar----
        fseek(f, 0, SEEK_END);
        long tamanio_archivo = ftell(f);
        num_registro = tamanio_archivo / sizeof(struct alumno);
        posicion = malloc(sizeof(int));
        *posicion = tamanio_archivo;

        //Inicio de la carga---------------------------------------------------
        //LEGAJO
        printf("Ingrese el legajo del alumno: "); //solo numeros
        fgets(entrada, STR_MAX, stdin);
        entrada[strcspn(entrada, "\n")] = '\0';         
        alum_1->legajo = validar_entero(entrada);
        while (!tiene6digitos(entrada) || alum_1->legajo < 0)
        {
            printf("ERROR ingrese un legajo valido.\n");
            printf("Ingrese el legajo del alumno: "); //solo numeros
            fgets(entrada, STR_MAX, stdin);
            entrada[strcspn(entrada, "\n")] = '\0';
            alum_1->legajo = validar_entero(entrada);
        }
        
        //Buscamos si el legajo ya existe en el archivo
        alum_aux = buscar_por_legajo("legajo_alumnos.dat", alum_1->legajo);
        while(alum_aux.legajo != -1){
            printf("EL LEGAJO YA EXISTE!!!.\n");
            printf("Ingrese el legajo del alumno: "); //solo numeros
            fgets(entrada, STR_MAX, stdin);
            entrada[strcspn(entrada, "\n")] = '\0';         
            alum_1->legajo = validar_entero(entrada);
            while (!tiene6digitos(entrada) || alum_1->legajo < 0)
            {
                printf("ERROR ingrese un legajo valido.\n");
                printf("Ingrese el legajo del alumno: "); //solo numeros
                fgets(entrada, STR_MAX, stdin);
                entrada[strcspn(entrada, "\n")] = '\0';
                alum_1->legajo = validar_entero(entrada);
            }
            //vuelvo a probar
            alum_aux = buscar_por_legajo("legajo_alumnos.dat", alum_1->legajo);
        }
        //APELLIDO
        printf("Ingrese el apellido del alumno.\n");
        fgets(entrada, STR_MAX, stdin);
        entrada[strcspn(entrada, "\n")] = '\0';
        while (!validarcadena(entrada) || es_vacio(entrada))
        {
            printf("ERROR!!! Ingrese el apellido del alumno (solo letras).\n");
            fgets(entrada, STR_MAX, stdin);
            entrada[strcspn(entrada, "\n")] = '\0';
            
        }
        strcpy(alum_1->apellido, entrada);

        //NOMBRE
        printf("Ingrese el nombre del alumno.\n"); 
        fgets(entrada, STR_MAX, stdin);
        entrada[strcspn(entrada, "\n")] = '\0';
        while (!validarcadena(entrada) || es_vacio(entrada))
        {
            printf("ERROR!!! Ingrese el nombre del alumno (solo letras).\n");
            fgets(entrada, STR_MAX, stdin);
            entrada[strcspn(entrada, "\n")] = '\0';
            
        }
        strcpy(alum_1->nombre, entrada);

        //DOMICILIO
        printf("Ingrese el domicilio del alumno.\n"); 
        fgets(entrada, STR_MAX, stdin);
        entrada[strcspn(entrada, "\n")] = '\0';
        strcpy(alum_1->domicilio, entrada);

        //TELEFONO
        printf("Ingrese el telefono del alumno.\n"); //solo numeros
        fgets(entrada, STR_MAX, stdin);
        entrada[strcspn(entrada, "\n")] = '\0';
        alum_1->telefono = validar_entero(entrada);

        //ESTADO
        printf("Alumno dado de alta.\n");
        alum_1->de_baja = false;

        //Carga en la tabla-------------------------------------------------
        te = te_crear_con_valor(alum_1->legajo, posicion);
        if(th_insertar(tab, te) == false){
            printf("No se pudo cargar la tabla.\n");
        }

        //Actualizo tamanio - escribo el archivo---------------------------
        fseek(f, sizeof(struct alumno)*num_registro, SEEK_SET);
        fwrite(alum_1, sizeof(struct alumno), 1, f);

        //Corte-------------------------------------------------------------
        printf("¡Registro cargado!\n");
        i += 1;

    }
    fclose(f);
}
//FUNCION MODIFICAR--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void modificar_alumno(TablaHash tab, int legajo){
    char *entrada = malloc(sizeof(char)*20);
    int corte = 0;
    TipoElemento te = th_recuperar(tab, legajo);
    if(te == NULL){
        printf("EL LEGAJO NO SE ENCUENTRA EN EL ARCHIVO.\n");
    }else{
        FILE *f;
        struct alumno *alum_1 = malloc(sizeof(struct alumno));
        if((f = fopen("legajo_alumnos.dat", "r+b")) == NULL){
            printf("No se pudo abrir el archivo.\n");
        }
        //En el archivo me posiciono en el alumno a buscar
        fseek(f, sizeof(struct alumno)*(*((int*)te->valor)), SEEK_SET);
        fread(alum_1, sizeof(struct alumno), 1, f);

        printf("Legajo: %d,%s,%s \n", alum_1->legajo, alum_1->apellido, alum_1->nombre);
        printf("¿Modificar apellido?\n");
        corte = validarsalida();
        if(corte != -1){
            //APELLIDO
            printf("Ingrese el nuevo apellido.\n");
            fgets(entrada, STR_MAX, stdin);
            entrada[strcspn(entrada, "\n")] = '\0';
            while (!validarcadena(entrada) || es_vacio(entrada))
            {
                printf("Ingrese el nuevo apellido (solo letras).\n");
                fgets(entrada, STR_MAX, stdin);
                entrada[strcspn(entrada, "\n")] = '\0';
                
            }
            strcpy(alum_1->apellido, entrada);
        }
        //------------------------------------------------------------------------------
        printf("¿Modificar nombre?\n");
        corte = validarsalida();
        if(corte != -1){
            //NOMBRE
            printf("Ingrese el nuevo nombre.\n");
            fgets(entrada, STR_MAX, stdin);
            entrada[strcspn(entrada, "\n")] = '\0';
            while (!validarcadena(entrada) || es_vacio(entrada))
            {
                printf("Ingrese el nuevo nombre (solo letras).\n");
                fgets(entrada, STR_MAX, stdin);
                entrada[strcspn(entrada, "\n")] = '\0';
                
            }
            strcpy(alum_1->nombre, entrada);
        }
        //------------------------------------------------------------------------------
        printf("¿Modificar domicilio?\n");
        corte = validarsalida();
        if(corte != -1){
            //DOMICILIO
            printf("Ingrese el nuevo domicilio.\n");
            fgets(entrada, STR_MAX, stdin);
            entrada[strcspn(entrada, "\n")] = '\0';
            strcpy(alum_1->domicilio, entrada);
        }
        //------------------------------------------------------------------------------
        printf("¿Modificar telefono?\n");
        corte = validarsalida();
        if(corte != -1){
            //TELEFONO
            printf("Ingrese el nuevo telefono.\n");
            fgets(entrada, STR_MAX, stdin);
            entrada[strcspn(entrada, "\n")] = '\0';
            alum_1->telefono = validar_entero(entrada);
        }
        fseek(f, sizeof(struct alumno)*(*((int*)te->valor)), SEEK_SET);
        fwrite(alum_1, sizeof(struct alumno), 1, f);
        fclose(f);
        printf("ARCHIVO MODIFICADO CON EXITO!\n");
    }
}
//FUNCION DAR DE BAJA--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void dar_de_baja(TablaHash tab, int legajo){
    char *entrada = malloc(sizeof(char)*20);
    int corte = 0;
    TipoElemento te = th_recuperar(tab, legajo);
    if(te == NULL){
        printf("EL LEGAJO NO SE ENCUENTRA EN EL ARCHIVO.\n");
    }else{
        FILE *f;
        struct alumno *alum_1 = malloc(sizeof(struct alumno));
        if((f = fopen("legajo_alumnos.dat", "r+b")) == NULL){
            printf("No se pudo abrir el archivo.\n");
        }
        //En el archivo me posiciono en el alumno a buscar
        fseek(f, sizeof(struct alumno)*(*((int*)te->valor)), SEEK_SET);
        fread(alum_1, sizeof(struct alumno), 1, f);
        printf("Dara de baja al alumno %d,%s,%s ¿Continuar?\n", alum_1->legajo, alum_1->apellido, alum_1->nombre);
        corte = validarsalida();
        if(corte != -1){
            alum_1->legajo = 0;
            alum_1->de_baja = true;
            fseek(f, sizeof(struct alumno)*(*((int*)te->valor)), SEEK_SET);
            fwrite(alum_1, sizeof(struct alumno), 1, f);
            th_eliminar(tab, legajo);
            printf("ALUMNO DADO DE BAJA.\n");
        }else{
            printf("El alumno no fue dado de baja.\n");
        }
        fclose(f);
    }
}
//Funcion abm-------------------------------------------------------------------------------------------------------------
void th_ej4_abm(){
    int cantidad;
    int legajo, modificacion, cantidad_aux, diferencia_cantidad;
    char entrada[STR_MAX];
    crear_archivo();
    cantidad = validarentradaentero_arboles("¿Cuantos alumnos va a ingresar?: ");
    while (cantidad < 0)
    {
        printf("No se puede ingresar numeros negativos.\n");
        cantidad = validarentradaentero_arboles("¿Cuantos alumnos va a ingresar?: ");
    }
    if (cantidad == 0)
    {
        printf("Usted cargo 0 alumnos.\n");
        return;
    }
    cantidad_aux = cantidad;
    NUMERO_PRIMO = primo_mas_cercano(cantidad);
    TablaHash tab = th_crear(cantidad, hash_function);
    //DAR DE ALTA--------------------------------------
    dar_de_alta(tab, cantidad);
    printf("ARCHIVO CARGADO: \n");
    mostrar_archivo("legajo_alumnos.dat");
    printf("TABLA: \n");
    th_mostrar(tab);
    //¿MODIFCICAR?--------------------------------------
    printf("\n¿Quiere modificar algun alumno?\n");
    modificacion = validarsalida();
    while(modificacion != -1)
    {
        //LEGAJO
        printf("Ingrese el legajo del alumno: "); //solo numeros
        fgets(entrada, STR_MAX, stdin);
        entrada[strcspn(entrada, "\n")] = '\0';   
        legajo = validar_entero(entrada);    
        while (!tiene6digitos(entrada) || legajo < 0)
        {
            printf("ERROR ingrese un legajo valido.\n");
            printf("Ingrese el legajo del alumno: "); //solo numeros
            fgets(entrada, STR_MAX, stdin);
            entrada[strcspn(entrada, "\n")] = '\0';
            legajo = validar_entero(entrada);
        }
        
        modificar_alumno(tab, legajo); 
        printf("TABLA MODIFICADA: \n");
        th_mostrar(tab);
        mostrar_archivo("legajo_alumnos.dat");
        printf("\n¿Quiere modificar algun otro alumno?\n");
        modificacion = validarsalida();
    }
    printf("\n¿Quiere dar de baja algun alumno?\n");
    //DAR DE BAJA--------------------------------------
    modificacion = validarsalida();
    while (modificacion != -1)
    {   
        cantidad_aux -= 1;
        printf("Ingrese el legajo del alumno: "); //solo numeros
        fgets(entrada, STR_MAX, stdin);
        entrada[strcspn(entrada, "\n")] = '\0';   
        legajo = validar_entero(entrada);   

        while (!tiene6digitos(entrada) || legajo < 0)
        {
            printf("ERROR ingrese un legajo valido.\n");
            printf("Ingrese el legajo del alumno: "); //solo numeros
            fgets(entrada, STR_MAX, stdin);
            entrada[strcspn(entrada, "\n")] = '\0';
            legajo = validar_entero(entrada);
        }
        
        dar_de_baja(tab, legajo);
        printf("TABLA ACTUALIZADA: \n");
        th_mostrar(tab);
        mostrar_archivo("legajo_alumnos.dat");
        printf("\n¿Quiere dar de baja algun otro alumno?\n");
        modificacion = validarsalida();
        
    }
    
    //Si es que hubo bajas
    
    if(cantidad_aux < cantidad){
        printf("\n¿Quiere dar de alta algun otro alumno?\n");
        modificacion = validarsalida();
        diferencia_cantidad = cantidad - cantidad_aux;
        if(modificacion != -1){
            printf("CANTIDAD DE ESPACIOS DISPONIBLES %d\n", (diferencia_cantidad));
            cantidad = validarentradaentero_arboles("¿Cuantos alumnos va a ingresar?: ");

            while (cantidad < 0 || cantidad > diferencia_cantidad)
            {
                printf("No se puede ingresar numeros negativos o mas de lo disponible.\n");
                cantidad = validarentradaentero_arboles("¿Cuantos alumnos va a ingresar?: ");
            }
        dar_de_alta(tab, cantidad_aux);
        printf("ARCHIVO CON NUEVA(S) ALTA(S): \n");
        mostrar_archivo("legajo_alumnos.dat");
        printf("TABLA CON NUEVA(S) ALTA(S): \n");
        th_mostrar(tab);
        }   
    }   
           
}

//Mostrar-------------------------------------------------------------------------------------------------------------

void mostrar_archivo(){
    FILE *f;
    struct alumno *alum_1 = malloc(sizeof(struct alumno));
    if((f = fopen("legajo_alumnos.dat", "r+b")) == NULL){
        printf("No se pudo abrir el archivo.\n");
    }
    fread(alum_1, sizeof(struct alumno), 1, f);
    while(!feof(f)){
        //Condicion para no mostrar alumnos dados de baja
        if(alum_1->de_baja != true){
            printf("%06d\n,%s,%s,%s,%d \n", alum_1->legajo, alum_1->apellido, alum_1->nombre, alum_1->domicilio, alum_1->telefono);
        }
        fread(alum_1, sizeof(struct alumno), 1, f);
    }
    fclose(f);
}


// ---------------------------------- Ejercicio 5 --------------------------
void cargar_arbolavl_tablahash_aleatorios(ArbolAVL AVL, TablaHash TH, int cant_numeros, int min, int max){
    int i= 0;
    bool busqueda = false;
    TipoElemento X;
    while (i<cant_numeros){
        X= te_crear(min+ rand() % (max+1 - min));
        buscar_elemento(avl_raiz(AVL), X->clave, &busqueda);
        if ((busqueda == false)){
            th_insertar(TH, X);
            avl_insertar(AVL, X);
            i++;
        }
        busqueda = false;
    }
}

void buscar_elemento(NodoArbol nodo, int clave, bool *busqueda){
    if (nodo == NULL) {
        return;
    }
    if (nodo->datos->clave == clave) {
        *busqueda = true;
        return;
    }
    buscar_elemento(n_hijoizquierdo(nodo), clave, busqueda);
    buscar_elemento(n_hijoderecho(nodo), clave, busqueda);
}


void th_ej5_comparacion(int q_claves, int q_repeticiones, int rango_desde, int rango_hasta){
    ArbolAVL avl = avl_crear();
    TablaHash tab = th_crear(q_claves, funcion_hash);
    clock_t tiempo_avl, tiempo_th;
    double tiempo_total_avl= 0;
    double tiempo_total_tabla= 0;
    TipoElemento X, X2;
    cargar_arbolavl_tablahash_aleatorios(avl, tab,q_claves, rango_desde, rango_hasta);

    tiempo_avl = clock();
    for (int i = 0; i < q_repeticiones; i++){
        X= te_crear(rango_desde+ rand() % (rango_hasta+1 - rango_desde));
        X2= avl_buscar(avl, X->clave);
    }
    tiempo_avl= clock()- tiempo_avl;
    tiempo_total_avl += ((double)tiempo_avl)/CLOCKS_PER_SEC;

    tiempo_th= clock();
    for (int i = 0; i < q_repeticiones; i++){
        X= te_crear(rango_desde+ rand() % (rango_hasta+1 - rango_desde));
        X2= th_recuperar(tab, X->clave);
    }
    tiempo_th= clock()- tiempo_th;
    tiempo_total_tabla+= ((double)tiempo_th)/CLOCKS_PER_SEC;

    printf("Tiempo total de la busqueda de las claves en el Arbol AVL: %.10f segundos.\n", tiempo_total_avl);
    printf("Tiempo total de la busqueda de las claves en la Tabla Hash: %.10f segundos.\n", tiempo_total_tabla);

}


//---------------------------------------------------- Ejercicio 6 -----------------------------------------------------------------


struct paciente{
    int dni;
    char apellido[20];
    char nombre[30];
};

void crear_archivo_paciente(){
    FILE *f;
    f = fopen("pacientes_vacunados.dat", "w+b");
    printf("ARCHIVO CREADO CON EXITO! \n");
    fclose(f);
}
//FUNCION DAR DE ALTA PACIENTE--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void dar_de_alta_paciente(TablaHash tab, int cantidad){
    TipoElemento te, te_hash;
    Lista L, L_nueva;
    int dia_v, mes_v, anio_v, clave, modificacion = -1;
    int corte = 0;
    int i = 0;
    char fecha[15];
    char entrada[20];
    int *posicion, num_registro = 0; 
    struct paciente *pac_1, pac_aux;
    FILE *f;
    //R+B Apertura de un archivo binario para actualizar permitiendo lectura y escritura. Si no existe genera un error.
    if((f = fopen("pacientes_vacunados.dat", "r+b")) == NULL){
        printf("No se pudo abrir el archivo.\n");
    }
    while(i < cantidad){
        pac_1 = malloc(sizeof(struct paciente));
        //Obtener la posicion en la que se encuentra el registro a guardar----
        fseek(f, 0, SEEK_END);
        long tamanio_archivo = ftell(f);
        num_registro = tamanio_archivo / sizeof(struct paciente);
        posicion = malloc(sizeof(int));
        *posicion = tamanio_archivo;

        //Inicio de la carga---------------------------------------------------
        //DNI
        printf("Ingrese el DNI del paciente.\n"); //solo numeros
        fgets(entrada, STR_MAX, stdin);
        entrada[strcspn(entrada, "\n")] = '\0';
        pac_1->dni = validar_entero(entrada);
        while (!tiene8digitos_DNI(pac_1->dni))
        {
            printf("Ingrese el DNI del paciente con 8 digitos.\n"); //solo numeros
            fgets(entrada, STR_MAX, stdin);
            entrada[strcspn(entrada, "\n")] = '\0';
            pac_1->dni = validar_entero(entrada);
        }
        pac_aux = buscar_por_dni("pacientes_vacunados.dat", pac_1->dni);
        //CASO QUE EL DNI YA SE ENCUENTRA EN EL REGISTRO
        while (pac_aux.dni != 0 && modificacion != 0){
            printf("El paciente ya se encuentra en el archivo. ¿Quiere cargar una 2da vacuna?");
            modificacion = validarsalida();
            if (modificacion == -1)
            {
                printf("Debe ingresar otro DNI.\n");
                printf("Ingrese el DNI del paciente con 8 digitos.\n"); //solo numeros
                fgets(entrada, STR_MAX, stdin);
                entrada[strcspn(entrada, "\n")] = '\0';
                pac_1->dni = validar_entero(entrada);
                while (!tiene8digitos_DNI(pac_1->dni))
                {
                    printf("Ingrese el DNI del paciente con 8 digitos.\n"); //solo numeros
                    fgets(entrada, STR_MAX, stdin);
                    entrada[strcspn(entrada, "\n")] = '\0';
                    pac_1->dni = validar_entero(entrada);
                }
                pac_aux = buscar_por_dni("pacientes_vacunados.dat", pac_1->dni);
            }else{
            
                strcpy(pac_1->nombre, pac_aux.nombre);
                strcpy(pac_1->apellido, pac_aux.apellido);
            }
              
        }
        if(pac_aux.dni == 0 &&  modificacion == -1){
            //CASO EN QUE EL DNI NO SE ENCUENTRA EN EL ARCHIVO
            //APELLIDO
            printf("Ingrese el apellido del paciente.\n");
            fgets(entrada, STR_MAX, stdin);
            entrada[strcspn(entrada, "\n")] = '\0';
            while (!validarcadena(entrada) || es_vacio(entrada))
            {
                printf("Ingrese el apellido del paciente (solo letras).\n");
                fgets(entrada, STR_MAX, stdin);
                entrada[strcspn(entrada, "\n")] = '\0';
            }

            strcpy(pac_1->apellido, entrada);
            //NOMBRE
            printf("Ingrese el nombre del paciente.\n"); 
            fgets(entrada, STR_MAX, stdin);
            entrada[strcspn(entrada, "\n")] = '\0';
            while (!validarcadena(entrada) || es_vacio(entrada))
            {
                printf("Ingrese el nombre del paciente (solo letras).\n");
                fgets(entrada, STR_MAX, stdin);
                entrada[strcspn(entrada, "\n")] = '\0';
            }
            strcpy(pac_1->nombre, entrada);
        }

        //DIA
        printf("Ingrese el dia de vacunacion (1-31): ");
        fgets(entrada, STR_MAX, stdin);
        entrada[strcspn(entrada, "\n")] = '\0';
        dia_v = validar_entero(entrada);
        while (dia_v < 1 || dia_v > 31) {
            printf("Dia invalido. Ingrese un dia entre 1 y 31: ");
            fgets(entrada, STR_MAX, stdin);
            entrada[strcspn(entrada, "\n")] = '\0';
            dia_v = validar_entero(entrada);
        }
        //MES
        printf("Ingrese el mes de vacunacion (1-12): ");
        fgets(entrada, STR_MAX, stdin);
        entrada[strcspn(entrada, "\n")] = '\0';
        mes_v = validar_entero(entrada);
        while (mes_v < 1 || mes_v > 12) {
            printf("Mes invalido. Ingrese un mes entre 1 y 12: ");
            fgets(entrada, STR_MAX, stdin);
            entrada[strcspn(entrada, "\n")] = '\0';
            mes_v = validar_entero(entrada);
        }
        //ANIO
        printf("Ingrese el anio de vacunacion (ej: 2024): ");
        fgets(entrada, STR_MAX, stdin);
        entrada[strcspn(entrada, "\n")] = '\0';
        anio_v = validar_entero(entrada);
        while (anio_v < 1900 || anio_v > 2100) {
            printf("Anio invalido. Ingrese un anio entre 1900 y 2100: ");
            fgets(entrada, STR_MAX, stdin);
            entrada[strcspn(entrada, "\n")] = '\0';
            anio_v = validar_entero(entrada);
        }
        
        sprintf(fecha, "%02d%02d%04d", dia_v, mes_v, anio_v);
        clave = atoi(fecha);
        //Carga en la tabla-------------------------------------------------
        te_hash = th_recuperar(tab, clave);
        if(te_hash != NULL){
            L = (Lista) te_hash->valor;
            te = te_crear_con_valor(pac_1->dni, pac_1);
            if(l_buscar(L, te->clave) == NULL){
                l_agregar(L, te);
                //Actualizo tamanio - escribo el archivo---------------------------
                fseek(f, sizeof(struct paciente)*num_registro, SEEK_SET); 
                fwrite(pac_1, sizeof(struct paciente), 1, f);
            }else{
                printf("EL PACIENTE YA SE ENCUENTRA EN LA LISTA.\n");
            }
        }else{
            L_nueva = l_crear();
            te = te_crear_con_valor(pac_1->dni, pac_1);
            l_agregar(L_nueva, te);
            te_hash = te_crear_con_valor(clave, L_nueva);
            if(th_insertar(tab, te_hash) == false){
                printf("No se pudo cargar la tabla.\n");
            }else{
                printf("¡Nueva fecha ingresada!.\n");
            }
            //Actualizo tamanio - escribo el archivo---------------------------
            fseek(f, sizeof(struct paciente)*num_registro, SEEK_SET);
            fwrite(pac_1, sizeof(struct paciente), 1, f);
        }
        

        //Corte-------------------------------------------------------------
        printf("\n¡Registro cargado!\n");
        i += 1;
    }
    fclose(f);
}
int th_ej6_covid(){
    int dia_v, mes_v, anio_v, clave, corte = 0;
    int cantidad = 0;
    char fecha[15];
    char entrada[STR_MAX];
    Lista l;
    TablaHash tab;
    crear_archivo_paciente();
    cantidad = validarentradaentero_arboles("¿Cuantos pacientes va a ingresar?: ");
    while (cantidad < 0)
    {
        printf("No se puede ingresar una cantidad negativa de pacientes. Reintentelo.\n");
        cantidad = validarentradaentero_arboles("¿Cuantos pacientes va a ingresar?: ");
    }
    if(cantidad == 0){
        printf("Usted cargo 0 pacientes.\n");
        return 0;
    }
    NUMERO_PRIMO = primo_mas_cercano(cantidad);
    tab = th_crear(cantidad + 1, hash_function);
    dar_de_alta_paciente(tab, cantidad);
    printf("¿Que fecha desea consultar?\n");
    while(corte != -1){
        //DIA
        printf("Ingrese el dia de vacunacion (1-31): ");
        fgets(entrada, STR_MAX, stdin);
        entrada[strcspn(entrada, "\n")] = '\0';
        dia_v  = validar_entero(entrada);
        while (dia_v < 1 || dia_v > 31) {
            
            printf("Dia invalido. Ingrese un dia entre 1 y 31: ");
            fgets(entrada, STR_MAX, stdin);
            entrada[strcspn(entrada, "\n")] = '\0';
            dia_v  = validar_entero(entrada);
        }
        //MES
        printf("Ingrese el mes de vacunacion (1-12): ");
        fgets(entrada, STR_MAX, stdin);
        entrada[strcspn(entrada, "\n")] = '\0';
        mes_v = validar_entero(entrada);
        while (mes_v < 1 || mes_v > 12) {
            
            printf("Mes invalido. Ingrese un mes entre 1 y 12: ");
            fgets(entrada, STR_MAX, stdin);
            entrada[strcspn(entrada, "\n")] = '\0';
            mes_v = validar_entero(entrada);
        }
        //ANIO
        printf("Ingrese el anio de vacunacion (ej: 2024): ");
        fgets(entrada, STR_MAX, stdin);
        entrada[strcspn(entrada, "\n")] = '\0';
        anio_v = validar_entero(entrada);
        while (anio_v < 1900 || anio_v > 2100) {
            
            printf("Anio invalido. Ingrese un anio entre 1900 y 2100: ");
            fgets(entrada, STR_MAX, stdin);
            entrada[strcspn(entrada, "\n")] = '\0';
            anio_v = validar_entero(entrada);
        }
        printf("Pacientes vacunados en la fecha: \n");
        sprintf(fecha, "%02d%02d%04d", dia_v, mes_v, anio_v);
        clave = atoi(fecha);
        l = l_crear();
        l = consultar_vacunados_fecha(tab, clave);
        l_mostrar_con_valor(l);
        printf("¿Quiere consultar otra fecha?\n");
        corte = validarsalida();
    }
    return 0;
}


Lista consultar_vacunados_fecha(TablaHash tab, int clave){
    Lista L;
    TipoElemento X;
    X= th_recuperar(tab, clave);
    if (X==NULL){
        return (l_crear());
    }
    else{
        L= (Lista) X->valor;
        return L;
    }
}

void l_mostrar_con_valor(Lista L){
    if (l_es_vacia(L)){
        printf("LISTA VACIA!!!\n");
        return;
    }
    struct paciente *persona_vacunada = malloc(sizeof(struct paciente));
    TipoElemento X;
    Iterador ITE;
    ITE= iterador(L);


    while (hay_siguiente(ITE)==true){
        X= siguiente(ITE);
        persona_vacunada= X->valor; 

        printf("DNI: %i \n", X->clave);
        printf("Nombre y apellido: %s %s.\n", persona_vacunada->nombre, persona_vacunada->apellido);
    }

    printf("\n");
}

struct paciente buscar_por_dni(const char* nombre_archivo, int dni_buscado) {
    FILE *archivo;
    struct paciente pac;
    struct paciente resultado = {0}; // Inicializa con valores cero/por defecto
    
    archivo = fopen(nombre_archivo, "rb");
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return resultado;
    }

    // Leer registro por registro
    while (fread(&pac, sizeof(struct paciente), 1, archivo) == 1) {
        if (pac.dni == dni_buscado) {
            resultado = pac; // Guarda el paciente encontrado
            break;
        }
    }

    fclose(archivo);
    return resultado;
}

struct alumno buscar_por_legajo(const char* nombre_archivo, int legajo_buscar) {
    FILE *archivo;
    struct alumno alum;
    struct alumno resultado = {-1}; // Inicializa con valores menos 1/por defecto
    
    archivo = fopen(nombre_archivo, "rb");
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return resultado;
    }

    // Leer registro por registro
    while (fread(&alum, sizeof(struct alumno), 1, archivo) == 1) {
        if (alum.legajo == legajo_buscar) {
            resultado = alum; // Guarda el alumno encontrado
            break;
        }
    }

    fclose(archivo);
    return resultado;
}


void mostrar_archivo_pacientes(){
    FILE *f;
    struct paciente *pac_1 = malloc(sizeof(struct alumno));
    if((f = fopen("pacientes_vacunados.dat", "r+b")) == NULL){
        printf("No se pudo abrir el archivo.\n");
    }
    fread(pac_1, sizeof(struct paciente), 1, f);
    while(!feof(f)){
        printf("%d\n,%s,%s \n", pac_1->dni, pac_1->apellido, pac_1->nombre);
        fread(pac_1, sizeof(struct paciente), 1, f);
    }
    fclose(f);
}