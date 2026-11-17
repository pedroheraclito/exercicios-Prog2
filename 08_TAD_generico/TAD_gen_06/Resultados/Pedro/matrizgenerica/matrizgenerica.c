#include <stdio.h>
#include <stdlib.h>
#include "matrizgenerica.h"
#include <string.h>

struct matrizgenerica
{
    int i;
    int j;
    int numbyteelem;
    void ***dado;
};

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar uma Matriz de qualquer tipo de dados,
 * desde que esse tipo ocupe determinado número de bytes.
 *
 * @param linhas - Numero de linhas da matriz
 * @param colunas - Numero de colunas da matriz
 * @param numByteElem - Número de Bytes que cada elemento da matriz ocupará
 *
 * @return Um ponteiro para a estrutura que armazena uma matriz genérica
 */
tMatrizGenerica *CriaMatrizGenerica(int linhas, int colunas, int numByteElem)
{
    tMatrizGenerica *m = (tMatrizGenerica *)calloc(1, sizeof(tMatrizGenerica));

    m->i = linhas;
    m->j = colunas;
    m->numbyteelem = numByteElem;
    m->dado = (void ***)calloc(linhas, sizeof(void **));
    for (int i = 0; i < linhas; i++)
    {
        m->dado[i] = (void **)calloc(colunas, sizeof(void *));
        for (int j = 0; j < colunas; j++)
        {
            m->dado[i][j] = (void *)calloc(1, numByteElem);
        }
    }

    return m;
}

/**
 * @brief Libera a memória alocada dinamicamente para uma matriz
 *
 * @param mat - Ponteiro para a matriz a ser liberada
 *
 */
void DestroiMatrizGenerica(tMatrizGenerica *mat)
{
    for (int i = 0; i < mat->i; i++)
    {
        for (int j = 0; j < mat->j; j++)
        {
            free(mat->dado[i][j]);
        }
        free(mat->dado[i]);
    }
    free(mat->dado);
    free(mat);
}

/**
 * @brief Obtém o número de linhas da matriz
 *
 * @param mat - Ponteiro para a matriz que queremos saber o número de linhas
 *
 * @return O número de linhas da matriz
 */
int ObtemNumeroLinhasMatrizGenerica(tMatrizGenerica *mat)
{
    return mat->i;
}

/**
 * @brief Obtém o número de colunas da matriz
 *
 * @param mat - Ponteiro para a matriz que queremos saber o número de colunas
 *
 * @return O número de colunas da matriz
 */
int ObtemNumeroColunasMatrizGenerica(tMatrizGenerica *mat)
{
    return mat->j;
}

/**
 * @brief Obtém ponteiro para um elemento qualquer da matriz genérica.
 *
 * @param mat - Ponteiro para a matriz que queremos encontrar o elemento na linha e coluna desejada
 * @param linha - Linha que o elemento está
 * @param coluna - Coluna que o elemento está
 *
 * @return Ponteiro para o elemento da matriz que está na linha e coluna passadas como parâmetro
 */
void *ObtemElementoMatrizGenerica(tMatrizGenerica *mat, int linha, int coluna)
{
    return mat->dado[linha][coluna];
}

/**
 * @brief Atribui um elemento a uma posição de uma matriz.
 *
 * @param mat - Ponteiro para a matriz que queremos atribuir o elemento na linha e coluna desejada
 * @param linha - Linha que o elemento ficará
 * @param coluna - Coluna que o elemento ficará
 * @param *elem - Ponteiro para o elemento que será colocado na matriz (será feita uma cópia)
 *
 * @return Ponteiro para o elemento da matriz que está na linha e coluna passadas como parâmetro
 */
void AtribuiElementoMatrizGenerica(tMatrizGenerica *mat, int linha, int coluna, void *elem)
{
    memcpy(mat->dado[linha][coluna], elem, mat->numbyteelem);
}

/**
 * @brief Imprime os elementos usando um callback para imprimir o tipo de dados da matriz.
 * A matriz é impressa linha a linha: após cada elemento (inclusive o último da linha) é impresso um espaço
 * e, ao final de cada linha, uma quebra de linha ('\n'). O callback deve imprimir apenas o elemento,
 * sem espaços ou quebras de linha.
 *
 * @param mat - Ponteiro para a matriz que queremos atribuir o elemento na linha e coluna desejada
 * @param imprime_elemento - Ponteiro para a função (callback) que tem a capacidade de imprimir os dados de um elemento desta matriz
 */

void ImprimirMatrizGenerica(tMatrizGenerica *mat, void(imprime_elemento(void *)))
{
    for (int i1 = 0; i1 < mat->i; i1++)
    {
        for (int i = 0; i < mat->j; i++)
        {
            imprime_elemento(mat->dado[i1][i]);
            printf(" ");
        }
        printf("\n");
    }
}

/**
 * @brief Encontra a transposta de uma matriz passada como parâmetro
 *
 * @param mat - A matriz que queremos encontrar a transposta
 *
 * @return Ponteiro para uma nova matriz, igual à transposta da matriz mat
 */
tMatrizGenerica *MatrizTransposta(tMatrizGenerica *mat)
{
    tMatrizGenerica *transposta = CriaMatrizGenerica(mat->j, mat->i, mat->numbyteelem);
    for (int i = 0; i < mat->i; i++)
    {
        for (int j = 0; j < mat->j; j++)
        {
            memcpy(transposta->dado[j][i], mat->dado[i][j], mat->numbyteelem);
        }
    }
    return transposta;
}

/**
 * @brief Calcula e retorna a multiplicação entre duas matrizes
 *
 * @param mat1 - A primeira matriz da multiplicação
 * @param mat2 - A segunda matriz da multiplicação
 * @param numByteTarget - Número de bytes do elemento resultante
 * @param multi_elem - Ponteiro para função (callback) que realiza a multiplicação entre dois elementos do tipo de dados contido na matriz
 * @param soma_elem - Ponteiro para função (callback) que realiza a soma entre dois elementos do tipo de dados contido na matriz
 *
 * @return Ponteiro para uma nova matriz, igual a multiplicação entre mat1 e mat2.
 */
tMatrizGenerica *MultiplicaMatrizes(tMatrizGenerica *mat1, tMatrizGenerica *mat2, int numByteTarget, void *(*multi_elem)(void *, void *), void *(*soma_elem)(void *, void *))
{

    tMatrizGenerica *res = CriaMatrizGenerica(mat1->i, mat2->j, numByteTarget);

    for (int i = 0; i < mat1->i; i++)
    {
        for (int k = 0; k < mat2->j; k++)
        {
            void *acc = multi_elem(mat1->dado[i][0], mat2->dado[0][k]);

            for (int j = 1; j < mat1->j; j++)
            {
                void *prod = multi_elem(mat1->dado[i][j], mat2->dado[j][k]);
                void *novo = soma_elem(acc, prod);
                free(acc);
                free(prod);
                acc = novo;
            }
            free(res->dado[i][k]);
            res->dado[i][k] = acc;
        }
    }

    return res;
}

/**
 * @brief Converte o tipo da matriz
 *
 * @param mat - A matriz que queremos converter para o novo tipo
 * @param novoNumByteElem - Número de bytes do novo tipo da matriz
 * @param converte_elem - Ponteiro para função que tem a capacidade de converter o elemento do tipo original para o novo tipo
 *
 * @return Ponteiro para uma nova matriz, no novo formato
 */
tMatrizGenerica *ConverteTipoMatriz(tMatrizGenerica *mat2, int novoNumByteElem, void *(*converte_elem)(void *))
{
    tMatrizGenerica *res = CriaMatrizGenerica(mat2->i, mat2->j, novoNumByteElem);

    for (int i = 0; i < mat2->i; i++)
    {
        for (int j = 0; j < mat2->j; j++)
        {
            free(res->dado[i][j]);
            res->dado[i][j] = converte_elem(mat2->dado[i][j]);
        }
    }

    return res;
}