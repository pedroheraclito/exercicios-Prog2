#include <stdio.h>
#include "utils_char.h"
#include <string.h>
#include <stdlib.h>

int main()
{
    char *vet;
    int tamanho;
    scanf("%d ", &tamanho);
    vet = CriaVetor(tamanho);
    ImprimeString(vet, tamanho);
    LeVetor(vet, tamanho);
    ImprimeString(vet, tamanho);
    LiberaVetor(vet);

    return 0;
}