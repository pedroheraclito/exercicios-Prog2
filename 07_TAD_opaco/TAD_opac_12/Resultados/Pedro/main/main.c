#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int main()
{
    int elemento;
    Array *a = CriarArray();
    LerArray(a);
    OrdenarArray(a);
    scanf("%d", &elemento);
    if (BuscaBinariaArray(a, elemento) != -1)
    {
        printf("Elemento %d encontrado no índice %d.\n", elemento, BuscaBinariaArray(a, elemento));
    }
    else
    {
        printf("Elemento %d não encontrado no array (-1).\n",elemento);
    }

    DestruirArray(a);
    return 0;
}