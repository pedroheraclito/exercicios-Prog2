#include <stdio.h>
#include <stdlib.h>
#include "array.h"

struct Array
{
    int *vetor;
    int qtdnum;
};
/**
 * @brief Inicializa um novo array, apontando data para NULL e tamanho para 0.
 * @return Ponteiro para a estrutura Array criada ou encerra caso não seja possível alocar memória.
 */
Array *CriarArray()
{
    Array *a = calloc(1, sizeof(Array));
    a->vetor = calloc(100, sizeof(int));
    a->qtdnum = 0;

    return a;
}

/**
 * @brief Libera a memória alocada para o array.
 * @param array Ponteiro para a estrutura Array a ser destruída.
 */
void DestruirArray(Array *array)
{
    free(array->vetor);
    free(array);
}

/**
 * @brief Lê os elementos do array a partir da entrada padrão e aloca memória para eles.
 * @details A leitura é feita até encontrar um ponto final (.) na entrada.
 * @param array Ponteiro para a estrutura Array a ser preenchida.
 */
void LerArray(Array *array)
{
    char c;
    scanf("%d%c", &array->vetor[array->qtdnum], &c);
    array->qtdnum++;
    while (c != '.')
    {

        scanf("%d%c", &array->vetor[array->qtdnum], &c);
        array->qtdnum++;
    }
}

/**
 * @brief Ordena os elementos do array em ordem crescente.
 * @param array Ponteiro para a estrutura Array a ser ordenada.
 */
void OrdenarArray(Array *array)
{
    for (int i = 0; i < array->qtdnum; i++)
    {
        for (int j = i + 1; j < array->qtdnum; j++)
        {
            if (array->vetor[i] > array->vetor[j])
            {
                int temp = array->vetor[i];
                array->vetor[i] = array->vetor[j];
                array->vetor[j] = temp;
            }
        }
    }
}

/**
 * @brief Realiza uma busca binária no array pelo elemento especificado.
 * @param array Ponteiro para a estrutura Array a ser buscada.
 * @param elementoBuscado Elemento a ser buscado no array.
 * @return Índice do elemento buscado no array, ou -1 caso não seja encontrado.
 */
int BuscaBinariaArray(Array *array, int elementoBuscado)
{
    for (int i = 0; i < array->qtdnum; i++)
    {
        if (array->vetor[i] == elementoBuscado)
        {
            return i;
        }
    }

    return -1;
}
