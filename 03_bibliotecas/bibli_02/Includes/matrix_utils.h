#ifndef matrix_UTILS_H
#define matrix_UTILS_H

/**
 * @brief Lê os valores da matriz especificada a partir da entrada padrão.
 * @param linhas Número de linhas da matriz.
 * @param colunas Número de colunas da matriz.
 * @param matriz Matriz a ser preenchida.
 */
void leMatriz(int linhas, int colunas, int matriz[linhas][colunas]);

/**
 * @brief Imprime a matriz especificada na saída padrão.
 * @param linhas Número de linhas da matriz.
 * @param colunas Número de colunas da matriz.
 * @param matriz Matriz a ser impressa. Após a impressão da matriz, deve ser impressa uma quebra de linha.
 */
void escreveMatriz(int linhas, int colunas, int matriz[linhas][colunas]);

/**
 * @brief Verifica se é possível somar duas matrizes.
 * @param linhas1 Número de linhas da primeira matriz.
 * @param colunas1 Número de colunas da primeira matriz.
 * @param linhas2 Número de linhas da segunda matriz.
 * @param colunas2 Número de colunas da segunda matriz.
 * @return 1 se for possível somar as matrizes, 0 caso contrário.
 */
int possivelSomarMatriz(int linhas1, int colunas1, int linhas2, int colunas2);

/**
 * @brief Verifica se é possível subtrair duas matrizes.
 * @param linhas1 Número de linhas da primeira matriz.
 * @param colunas1 Número de colunas da primeira matriz.
 * @param linhas2 Número de linhas da segunda matriz.
 * @param colunas2 Número de colunas da segunda matriz.
 * @return 1 se for possível subtrair as matrizes, 0 caso contrário.
 */
int possivelSubtrairMatriz(int linhas1, int colunas1, int linhas2, int colunas2);

/**
 * @brief Verifica se é possível multiplicar duas matrizes.
 * @param colunas1 Número de colunas da primeira matriz.
 * @param linhas2 Número de linhas da segunda matriz.
 * @return 1 se for possível multiplicar as matrizes, 0 caso contrário.
 */
int possivelMultiplicarMatriz(int colunas1, int linhas2);

/**
 * @brief Soma duas matrizes e armazena o resultado em resultado. Não é feito teste de possibilidade de soma.
 * @param linhas1 Número de linhas da primeira matriz.
 * @param colunas1 Número de colunas da primeira matriz.
 * @param matriz1 Primeira matriz.
 * @param linhas2 Número de linhas da segunda matriz.
 * @param colunas2 Número de colunas da segunda matriz.
 * @param matriz2 Segunda matriz.
 * @param resultado Matriz que armazenará o resultado da soma.
 */
void somaMatriz(int linhas1, int colunas1, int matriz1[linhas1][colunas1], int linhas2, int colunas2, int matriz2[linhas2][colunas2], int resultado[linhas1][colunas1]);

/**
 * @brief Subtrai duas matrizes e armazena o resultado em resultado. Não é feito teste de verificação de subtração.
 * @param linhas1 Número de linhas da primeira matriz.
 * @param colunas1 Número de colunas da primeira matriz.
 * @param matriz1 Primeira matriz.
 * @param linhas2 Número de linhas da segunda matriz.
 * @param colunas2 Número de colunas da segunda matriz.
 * @param matriz2 Segunda matriz.
 * @param resultado Matriz que armazenará o resultado da subtração.
 */
void subtraiMatriz(int linhas1, int colunas1, int matriz1[linhas1][colunas1], int linhas2, int colunas2, int matriz2[linhas2][colunas2], int resultado[linhas1][colunas1]);

/**
 * @brief Multiplica duas matrizes e armazena o resultado em resultado. Não é feito teste de verificação para a multiplicação. 
 *  A matriz resultado deve ser inicializada com 0 dentro desta função.
 * @param linhas1 Número de linhas da primeira matriz.
 * @param colunas1 Número de colunas da primeira matriz.
 * @param matriz1 Primeira matriz.
 * @param linhas2 Número de linhas da segunda matriz.
 * @param colunas2 Número de colunas da segunda matriz.
 * @param matriz2 Segunda matriz.
 * @param resultado Matriz que armazenará o resultado da multiplicação.
 */
void multiplicaMatriz(int linhas1, int colunas1, int matriz1[linhas1][colunas1], int linhas2, int colunas2, int matriz2[linhas2][colunas2], int resultado[linhas1][colunas2]);

/**
 * @brief Transpõe a matriz especificada. O resultado da transposta deve ser armazenado em result.
 * @param linhas Número de linhas da matriz.
 * @param colunas Número de colunas da matriz.
 * @param matriz Matriz a ser transposta.
 * @param resultado Matriz que armazenará o resultado da transposição.
 */
void tranporMatriz(int linhas, int colunas, int matriz[linhas][colunas], int resultado[colunas][linhas]);

/**
 * @brief Multiplica a matriz especificada por um escalar, mantendo o resultado na própria matriz.
 * @param linhas Número de linhas da matriz.
 * @param colunas Número de colunas da matriz.
 * @param matriz Matriz a ser multiplicada.
 * @param escalar Escalar a ser multiplicado.
 */
void multiplicaEscalarMatriz(int linhas, int colunas, int matriz[linhas][colunas], int escalar);


#endif