#ifndef MATRIX_UTILS_H
#define MATRIX_UTILS_H

#define MAX_MATRIZ_SIZE 10

typedef struct Matriz{
    int linhas;
    int colunas;
    int data[MAX_MATRIZ_SIZE][MAX_MATRIZ_SIZE];
} tMatriz;

/**
 * @brief Cria uma matriz com o número de linhas e colunas especificado.
 * @param linhas O número de linhas na matriz.
 * @param colunas O número de colunas na matriz.
 * @return A matriz criada.
 */
tMatriz criaMatriz(int linhas, int colunas);

/**
 * @brief Lê uma matriz da entrada padrão.
 * @param Matriz A matriz a ser lida.
 * @return A matriz lida.
 */
tMatriz leMatriz(tMatriz Matriz);

/**
 * @brief Imprime uma matriz na saída padrão.
 * @param Matriz A matriz a ser impressa.
 */
void escreveMatriz(tMatriz Matriz);

/**
 * @brief Verifica se é possível somar duas matrizes.
 * @param Matriz1 A primeira matriz.
 * @param Matriz2 A segunda matriz.
 * @return 1 se for possível somar as matrizes, 0 caso contrário.
 */
int possivelSomarMatriz(tMatriz Matriz1, tMatriz Matriz2);

/**
 * @brief Verifica se é possível subtrair duas matrizes.
 * @param Matriz1 A primeira matriz.
 * @param Matriz2 A segunda matriz.
 * @return 1 se for possível subtrair as matrizes, 0 caso contrário.
 */
int possivelSubtrairMatriz(tMatriz Matriz1, tMatriz Matriz2);

/**
 * @brief Verifica se é possível multiplicar duas matrizes.
 * @param Matriz1 A primeira matriz.
 * @param Matriz2 A segunda matriz.
 * @return 1 se for possível multiplicar as matrizes, 0 caso contrário.
 */
int possivelMultiplicarMatriz(tMatriz Matriz1, tMatriz Matriz2);

/**
 * @brief Soma duas matrizes.
 * @param Matriz1 A primeira matriz.
 * @param Matriz2 A segunda matriz.
 * @return O resultado da soma.
 */
tMatriz somaMatriz(tMatriz Matriz1, tMatriz Matriz2);

/**
 * @brief Subtrai duas matrizes.
 * @param Matriz1 A primeira matriz.
 * @param Matriz2 A segunda matriz.
 * @return O resultado da subtração.
 */
tMatriz subtraiMatriz(tMatriz Matriz1, tMatriz Matriz2);

/**
 * @brief Multiplica duas matrizes.
 * @param Matriz1 A primeira matriz.
 * @param Matriz2 A segunda matriz.
 * @return O resultado da multiplicação.
 */
tMatriz multiplicaMatriz(tMatriz Matriz1, tMatriz Matriz2);

/**
 * @brief Transpõe uma matriz.
 * @param Matriz A matriz a ser transposta.
 * @return A matriz transposta.
 */
tMatriz transporMatriz(tMatriz Matriz);

/**
 * @brief Multiplica uma matriz por um escalar.
 * @param Matriz A matriz a ser multiplicada.
 * @param escalar O escalar pelo qual a matriz será multiplicada.
 * @return O resultado da multiplicação.
 */
tMatriz multiplicaEscalarMatriz(tMatriz Matriz, int escalar);

#endif