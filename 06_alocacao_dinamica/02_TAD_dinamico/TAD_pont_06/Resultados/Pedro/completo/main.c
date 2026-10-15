#include <stdio.h>
#include <stdlib.h>
#include "matrix_utils.h"

int main()
{
    int rol1, rol2, col1, col2;
    scanf("%d %d", &rol1, &col1);
    tMatrix *mat1 = MatrixCreate(rol1, col1);
    MatrixRead(mat1);
    scanf("%d %d", &rol2, &col2);
    tMatrix *mat2 = MatrixCreate(rol2, col2);
    MatrixRead(mat2);
    printf("1 - Somar matrizes\n");
    printf("2 - Subtrair matrizes\n");
    printf("3 - Multiplicar matrizes\n");
    printf("4 - Multiplicacao de uma matriz por escalar\n");
    printf("5 - Transposta de uma matriz\n");
    printf("6 - Encerrar o programa\n");
    printf("Opcao escolhida: \n");
    int op, escolhida, escalar;
    scanf("%d", &op);
    while (1)
    {
        if (op == 1)
        {

            if (!PossibleMatrixSum(mat1, mat2))
            {
                printf("Erro: as dimensoes da matriz nao correspondem\n");
            }
            else
            {
                tMatrix *aux = MatrixAdd(mat1, mat2);
                MatrixPrint(aux);
                MatrixFree(aux);
            }
        }
        else if (op == 2)
        {
            if (!PossibleMatrixSub(mat1, mat2))
            {
                printf("Erro: as dimensoes da matriz nao correspondem\n");
            }
            else
            {
                tMatrix *aux = MatrixSub(mat1, mat2);
                MatrixPrint(aux);
                MatrixFree(aux);
            }
        }
        else if (op == 3)
        {
            
            if (!PossibleMatrixMultiply(mat1,mat2))
            {
                printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n");
            }
            else
            {
                tMatrix *aux = MatrixMultiply(mat1, mat2);
                MatrixPrint(aux);
                MatrixFree(aux);
            }
            
        }
        else if (op == 4)
        {

            scanf("%d %d", &escalar, &escolhida);
            if (escolhida == 1)
            {
                tMatrix *novo = MatrixMultiplyByScalar(mat1, escalar);
                MatrixFree(mat1);
                mat1=novo;
                MatrixPrint(mat1);
            }
            else if (escolhida == 2)
            {
                tMatrix *novo = MatrixMultiplyByScalar(mat2, escalar);
                 MatrixFree(mat2);
                mat2=novo;
                MatrixPrint(mat2);
            }
        }
        else if (op == 5)
        {
            tMatrix *aux = TransposeMatrix(mat1);
            MatrixPrint(aux);
            MatrixFree(aux);

            tMatrix *aux1 = TransposeMatrix(mat2);
            MatrixPrint(aux1);
            MatrixFree(aux1);
        }
        else if (op == 6)
        {
            break;
        }
        printf("1 - Somar matrizes\n");
        printf("2 - Subtrair matrizes\n");
        printf("3 - Multiplicar matrizes\n");
        printf("4 - Multiplicacao de uma matriz por escalar\n");
        printf("5 - Transposta de uma matriz\n");
        printf("6 - Encerrar o programa\n");
        printf("Opcao escolhida: \n");
        scanf("%d", &op);
    }
    MatrixFree(mat1);
    MatrixFree(mat2);

    return 0;
}