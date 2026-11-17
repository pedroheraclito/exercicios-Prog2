#include <stdio.h>
#include <stdlib.h>
#include "histograma.h"

/**
 * @brief Estrutura para representar um Histograma.
 */
struct tHistograma
{
    int *numpixels;
    int nintervalos;
    int tamintervalo;
};

/**
 * @brief Função para calcular o histograma de uma imagem.
 * @param img Ponteiro para a imagem.
 * @param nIntervalos Número de intervalos no histograma.
 * @return Ponteiro para o histograma calculado.
 */
Histograma *CalcularHistograma(Imagem *img, int nIntervalos)
{
    Histograma *h = (Histograma *)malloc(sizeof(Histograma));
    h->tamintervalo = (256 + nIntervalos - 1) / nIntervalos;
    h->nintervalos = nIntervalos;
    h->numpixels = (int *)calloc(nIntervalos, sizeof(int));

    int altura = ObterAltura(img);
    int largura = ObterLargura(img);
    Tipo tipo = ObterTipoImagem(img);
    void *dados = ObterDadosImagem(img);

    for (int i = 0; i < altura; i++)
    {
        for (int j = 0; j < largura; j++)
        {
            int idx_pixel = i * largura + j;
            int valor;

            if (tipo == INT)
                valor = ((int *)dados)[idx_pixel];
            else
                valor = (int)(((float *)dados)[idx_pixel]*255); // trunca o float

            int idx = valor / h->tamintervalo;

            // proteção contra valores fora de 0..255
            if (idx < 0)
                idx = 0;
            if (idx >= nIntervalos)
                idx = nIntervalos - 1;

            h->numpixels[idx]++;
        }
    }
     return h;   
}

/**
 * @brief Função para imprimir um histograma na tela.
 * @param histograma Ponteiro para o histograma a ser exibido.
 */
void MostrarHistograma(Histograma *histograma)
{
    if (histograma == NULL)
        return;

    for (int i = 0; i < histograma->nintervalos; i++)
    {
        int inicio = i * histograma->tamintervalo;
        int fim = inicio + histograma->tamintervalo ;



        printf("[%d, %d): %d\n", inicio, fim, histograma->numpixels[i]);
    }
}

/**
 * @brief Função para destruir um histograma.
 * @param histograma Ponteiro para o histograma a ser destruído.
 */
void DestruirHistograma(Histograma *histograma)
{
    free(histograma->numpixels);
    free(histograma);
}