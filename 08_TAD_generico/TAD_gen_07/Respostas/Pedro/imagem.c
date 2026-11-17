#include <stdio.h>
#include <stdlib.h>
#include "imagem.h"

/**
 * @brief Estrutura para representar uma imagem.
 */
struct tImagem
{
    Tipo tipo;
    int altura;
    int largura;
    void *dado;
};

/**
 * @brief Função para obter a altura de uma imagem.
 * @param img Ponteiro para a imagem.
 * @return Altura da imagem.
 */
int ObterAltura(Imagem *img)
{
    return img->altura;
}

/**
 * @brief Função para obter a largura de uma imagem.
 * @param img Ponteiro para a imagem.
 * @return Largura da imagem.
 */
int ObterLargura(Imagem *img)
{
    return img->largura;
}

/**
 * @brief Função para obter o tipo de dados de uma imagem.
 * @param img Ponteiro para a imagem.
 * @return Tipo de dados da imagem.
 */
Tipo ObterTipoImagem(Imagem *img)
{
    return img->tipo;
}

/**
 * @brief Função para obter os dados de uma imagem.
 * Note que a imagem é uma matriz, mas os dados podem ser armazenados de forma linear (vetor).
 * @param img Ponteiro para a imagem.
 * @return Ponteiro para os dados da imagem.
 */
void *ObterDadosImagem(Imagem *img)
{
    return img->dado;
}

/**
 * @brief Função para criar uma imagem.
 * @param altura Altura da imagem.
 * @param largura Largura da imagem.
 * @param tipo Tipo de dados da imagem.
 * @return Ponteiro para a imagem criada. Caso não seja possível criar a imagem, o programa é encerrado.
 */
Imagem *CriarImagem(int altura, int largura, Tipo tipo)
{
    Imagem *img = (Imagem *)calloc(1, sizeof(Imagem));
    img->tipo = tipo;
    img->altura = altura;
    img->largura = largura;
    if (tipo == INT)
    {
       img->dado = (int *)calloc(largura*altura, sizeof(int));
    }
    else if (tipo == FLOAT)
    {
       img->dado = (float *)calloc(largura*altura, sizeof(float));
    }
    
    

    return img;
}

/**
 * @brief Função para ler uma imagem, primeiro lendo a altura, largura e tipo de dados (tudo na mesma linha seperado por espaço). Em seguida, lê os dados da imagem.
 * @return Ponteiro para a imagem lida. (Crie a imagem com a função CriarImagem).
 */
Imagem *LerImagem()
{
    Tipo tipo;
    int tip;
    int altura;
    int largura;
    scanf("%d %d %d", &altura, &largura, &tip);
    if (tip == INT)
    {
        tipo = INT;
    }
    else if (tip == FLOAT)
    {
        tipo = FLOAT;
    }

    Imagem *img = CriarImagem(altura, largura, tipo);
    for (int i = 0; i < altura * largura; i++)
    {
        if (tip == INT)
        {
            int *imgint = (int *)img->dado;
            scanf("%d", &imgint[i]);
        }
        else if (tip == FLOAT)
        {
            float *imgfloat = (float *)img->dado;
            scanf("%f", &imgfloat[i]);
        }
    }
    return img;
}

/**
 * @brief Função para imprimir uma imagem.
 * @param img Ponteiro para a imagem.
 */
void ImprimirImagem(Imagem *img){
        for (int i = 0; i < img->altura; i++)
    {
        for (int j = 0; j < img->largura; j++)
        {
            int idx = i * img->largura + j;
            if (img->tipo == INT)
                printf("%d", ((int *)img->dado)[idx]);
            else
                printf("%.2f", ((float *)img->dado)[idx]);

            if (j < img->largura - 1)
                printf(" ");
        }
        printf("\n");
    }
}

/**
 * @brief Função para destruir uma imagem.
 * @param img Ponteiro para a imagem.
 */
void DestruirImagem(Imagem *img){
    free(img->dado);
    free(img);
}