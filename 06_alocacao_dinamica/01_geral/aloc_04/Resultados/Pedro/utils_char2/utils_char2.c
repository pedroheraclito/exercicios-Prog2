#include <stdio.h>
#include "utils_char2.h"
#include <stdlib.h>

/**
 * Cria um vetor de caracteres que consegue armazenar uma string de tamanho igual a "TAM_PADRAO", alocado dinamicamente.
 * Neste caso, a string deve ser inicializada com todas as suas "TAM_PADRAO" posições com "_", e a última posição deve conter '\0'.
 * Se houver erro na alocação, imprime uma mensagem de erro e encerra o programa.
 *
 * @return Ponteiro para o vetor criado.
 */
char *CriaVetorTamPadrao()
{
    char *vet;
    vet = (char *)calloc(TAM_PADRAO, sizeof(char));
    for (int i = 0; i < TAM_PADRAO; i++)
    {
        if (i != TAM_PADRAO - 1)
        {
            vet[i] = '_';
        }
        else
        {
            vet[i] = '\0';
        }
    }

    return vet;
}

/**
 * Aumenta o tamanho de um vetor alocado dinamicamente
 * O vetor deve ser aumentado para conseguir alocar mais "TAM_PADRAO" caracteres (o vetor só pode ter tamanhos múltiplos de "TAM_PADRAO")
 * Preencha as novas posições com "_", e lembre-se que a última deve conter '\0'.
 *
 * @param tamanhoantigo Tamanho do vetor a ser modificado
 * @return Ponteiro para o novo vetor.
 */
char *AumentaTamanhoVetor(char *vetor, int tamanhoantigo)
{
    vetor = realloc(vetor, (TAM_PADRAO + tamanhoantigo) * sizeof(char));
    for (int i = tamanhoantigo; i < TAM_PADRAO + tamanhoantigo; i++)
    {
        if (i != (TAM_PADRAO + tamanhoantigo) - 1)
        {
            vetor[i] = '_';
        }
        else
        {
            vetor[i] = '\0';
        }
    }
    return vetor;
}

/**
 * Lê uma string do tamanho especificado até um enter ser apertado.
 * Caso seja necessário alterar o tamanho do vetor, o tamanho deve ser atualizado para que o programa
 * saiba o novo tamanho do vetor.
 *
 * @param vetor Ponteiro para o vetor a ser lido.
 * @param tamanho* Ponteiro para uma variável do tipo inteiro que armazena o tamanho atual do vetor.
 * @return Um ponteiro para o vetor lido.
 */
char *LeVetor(char *vetor, int *tamanho)
{
    int i = 0;
    char c;
    while (scanf("%c", &c) == 1 && c != '\n')
    {
        if (i != *tamanho - 1)
        {
            vetor = AumentaTamanhoVetor(vetor, *tamanho);
            *tamanho += TAM_PADRAO;
        }
        vetor[i] = c;
        i++;
    }

    return vetor;
}

/**
 * Imprime a string
 *
 * @param vetor Ponteiro para o vetor a ser imprimido.
 */
void ImprimeString(char *vetor)
{
    printf("%s_\n", vetor);
}

/**
 * Libera a memória alocada para um vetor de caracteres.
 *
 * @param vetor Ponteiro para o vetor a ser liberado.
 */
void LiberaVetor(char *vetor)
{
    free(vetor);
}