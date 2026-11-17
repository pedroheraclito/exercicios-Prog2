#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

typedef void *DataType; // void pointer
struct Vector
{
    void **dado;
    int tam;
};

/**
 * @brief Cria um vetor vazio
 *
 * @return A estrutura Vector inicializada. Caso não seja possível alocar memória, o programa é encerrado.
 */
Vector *VectorConstruct()
{
    Vector *v = (Vector *)calloc(1, sizeof(Vector));
    v->tam = 0;
    v->dado = (void **)calloc(1, sizeof(void *));

    return v;
}

/**
 * @brief Adiciona um elemento no final do vetor
 *
 * @param v Ponteiro para o vetor
 * @param val Valor a ser adicionado
 */
void VectorPushBack(Vector *v, DataType val){
    v->dado=realloc(v->dado,(v->tam+1)*sizeof(void*));
    v->dado[v->tam]=val;
    v->tam++;
}

/**
 * @brief Retorna o i-ésimo elemento do vetor
 *
 * @param v Ponteiro para o vetor
 * @param i Índice do elemento
 * @return DataType Elemento do vetor
 */
DataType VectorGet(Vector *v, int i){
    return v->dado[i];
}

/**
 * @brief Retorna o tamanho do vetor
 *
 * @param v Ponteiro para o vetor
 * @return int Tamanho do vetor
 */
int VectorSize(Vector *v){
    return v->tam;
}

/**
 * @brief Libera a memória alocada para o vetor
 *
 * @param v Ponteiro para o vetor
 * @param destroy Função que libera a memória alocada para cada elemento do vetor
 */
void VectorDestroy(Vector *v, void (*destroy)(DataType)){
    for (int i = 0; i < v->tam; i++)
    {
        destroy(v->dado[i]);
    }
    free(v->dado);
    free(v);
    
}