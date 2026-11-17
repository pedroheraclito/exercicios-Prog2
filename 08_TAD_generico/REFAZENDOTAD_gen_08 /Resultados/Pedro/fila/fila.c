#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"
#include "movel.h"
struct Fila
{
    tMovel **moveis;
    int qtd;
};

/**
 * @brief Cria uma fila vazia
 *
 * @return A estrutura Fila inicializada. Caso não seja possível alocar memória, o programa é encerrado.
 */
Fila *FilaConstruct()
{
    Fila *fil = (Fila *)calloc(1, sizeof(Fila));
    fil->moveis = (tMovel **)calloc(1, sizeof(tMovel *));
    fil->qtd = 0;

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
    for (int i = 0; i < f->qtd; i++)
    {
        destroy(f->moveis[i]);
    }
    free(f->moveis);
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
    return f->qtd;
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
    void *sup = f->moveis[0];
    for (int i = 0; i < f->qtd - 1; i++)
    {
        f->moveis[i] = f->moveis[i+1];
    }
    f->qtd--;
    return sup;
}

/**
 * @brief Adiciona um elemento no final da fila
 *
 * @param f Ponteiro para a fila
 * @param val Valor a ser adicionado
 */
void FilaPush(Fila *f, DataType val){
    f->moveis=realloc(f->moveis,(f->qtd+1)*sizeof(tMovel*));
    f->moveis[f->qtd]=val;
    f->qtd++;
}
