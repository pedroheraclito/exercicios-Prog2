#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "movel.h"
#include <string.h>
#include "fila.h"

struct Fila
{
    void **data;
    int tamanho;
};

/**
 * @brief Cria uma fila vazia
 *
 * @return A estrutura Fila inicializada. Caso não seja possível alocar memória, o programa é encerrado.
 */
Fila *FilaConstruct()
{
    Fila *fil = (Fila *)calloc(1, sizeof(Fila));

    fil->data = NULL;
    fil->tamanho = 0;

    return fil;
}

/**
 * @brief Desaloca a memória alocada para a fila
 *
 * @param f Ponteiro para a fila
 * @param destroy Função que desaloca a memória alocada para cada elemento da fila
 */
void FilaDestroy(Fila *f, void (*destroy)(DataType))
{
    for (int i = 0; i < f->tamanho; i++)
    {
        destroy(f->data[i]);
    }
    free(f->data);
    free(f);
}

/**
 * @brief Retorna o tamanho da fila
 *
 * @param f Ponteiro para a fila
 * @return int Tamanho da fila
 */
int FilaSize(Fila *f)
{
    return f->tamanho;
}

/**
 * @brief Remove o primeiro elemento da fila
 * OBS: Note que a fila é uma estrutura FIFO (First In, First Out), ou seja, o primeiro elemento a ser adicionado é o primeiro a ser removido.
 * Portanto, apesar da fila estar implementada com um vector, ele não é adequado para implementar uma fila, pois a remoção de um elemento do início do vetor é uma operação custosa.
 * @param f Ponteiro para a fila
 * @return DataType Elemento removido
 */
DataType FilaPop(Fila *f)
{
    void *sup=f->data[0];
    for (int i = 0; i < f->tamanho-1; i++)
    {
       f->data[i]=f->data[i+1];
    }
    f->tamanho--;
    return sup;
}

/**
 * @brief Adiciona um elemento no final da fila
 *
 * @param f Ponteiro para a fila
 * @param val Valor a ser adicionado
 */
void FilaPush(Fila *f, DataType val)
{
    f->data = realloc(f->data, (1 + f->tamanho) * sizeof(void *));
    f->data[f->tamanho] = val;
    f->tamanho++;
}