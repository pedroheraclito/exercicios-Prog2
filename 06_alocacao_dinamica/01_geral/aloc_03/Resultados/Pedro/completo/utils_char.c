#include <stdio.h>
#include "utils_char.h"
#include <string.h>
#include <stdlib.h>

/**
 * Cria um vetor de caracteres de tamanho especificado, alocado dinamicamente.
 * Neste caso, a string deve ser inicializada com todas as suas posições com "_"
 * Se houver erro na alocação, imprime uma mensagem de erro e encerra o programa.
 *
 * @param tamanho Tamanho do vetor a ser criado.
 * @return Ponteiro para o vetor criado.
 */
char *CriaVetor(int tamanho)
{
    char *vet = (char *)calloc(tamanho, sizeof(char));

    for (int i = 0; i < tamanho; i++)
    {
        vet[i] = '_';
    }

    return vet;
}

/**
 * Lê uma string do tamanho especificado.
 *
 * @param vetor Ponteiro para o vetor a ser lido.
 * @param tamanho Tamanho do vetor a ser lido.
 */
void LeVetor(char *vetor, int tamanho)
{
    char c;
    for (int i = 0; i < tamanho; i++)
    {
        scanf("%c", &c);
        if (c == '\n')
        {
            break;
        }
        vetor[i]=c;
    }
}

/**
 * Imprime a string
 *
 * @param vetor Ponteiro para o vetor a ser lido.
 * @param tamanho Tamanho do vetor a ser lido.
 * @return Média dos valores do vetor.
 */
void ImprimeString(char *vetor, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        printf("%c", vetor[i]);
    }

    printf("\n");
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