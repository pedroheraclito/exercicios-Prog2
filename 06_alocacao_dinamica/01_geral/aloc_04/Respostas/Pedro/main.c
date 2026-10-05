#include <stdio.h>
#include "utils_char2.h"
#include <stdlib.h>

int main()
{
    char *vetor = CriaVetorTamPadrao();
    int tamanho;
    tamanho = TAM_PADRAO;
    vetor = LeVetor(vetor, &tamanho);
    ImprimeString(vetor);
    LiberaVetor(vetor);
    

    return 0;
}