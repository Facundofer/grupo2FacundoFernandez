#include <stdio.h>
#include <stdlib.h>
#include "..\libs\listas\headers\listas.h"

Lista factoresprimos(int valor){
    TipoElemento te;
    Lista lista1;
    bool blagregar = true;
    int divisor = 2;
    lista1 = l_crear();
    while (valor > 1)
    {
        while (valor % divisor == 0){
                te = te_crear(divisor);
                l_agregar(lista1, te);
                valor = valor / divisor;
        }
        divisor += 1;
    }
    if (!blagregar)
    {
        lista1 = l_crear();
    }
    return lista1;
}



