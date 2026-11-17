#include <stdio.h>
#include <stdlib.h>
#include "tadgen.h"
struct generic
{
    Type type;
    int numElem;
    void *dado;
};

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar tanto inteiros quanto floats
 *
 * @param type - Tipo do vetor genérico. Segue o Enum definido acima.
 * @param numElem A quantidade de elementos que serão armazenados no vetor
 *
 * @return O vetor genérico
 */
tGeneric *CriaGenerico(Type type, int numElem)
{
    tGeneric *g = (tGeneric *)calloc(1, sizeof(tGeneric));
    g->numElem = numElem;
    g->type = type;
    if (type == INT)
    {
        g->dado = (int *)calloc(numElem, sizeof(int));
    }
    else if (type == FLOAT)
    {
        g->dado = (float *)calloc(numElem, sizeof(float));
    }

    return g;
}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param gen - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiGenerico(tGeneric *gen)
{
    free(gen->dado);
    free(gen);
}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param gen - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LeGenerico(tGeneric *gen)
{
    if (gen->type == INT)
    {
        int *a = (int *)gen->dado;
        for (int i = 0; i < gen->numElem; i++)
        {
            scanf("%d", &a[i]);
        }
    }
    else if (gen->type == FLOAT)
    {
        float *a = (float *)gen->dado;
        for (int i = 0; i < gen->numElem; i++)
        {
            scanf("%f", &a[i]);
        }
    }
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param gen - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimeGenerico(tGeneric *gen)
{
    printf("\nDigite o vetor:\n");
    if (gen->type == INT)
    {
        int *a = (int *)gen->dado;
        for (int i = 0; i < gen->numElem; i++)
        {
            printf("%d ", a[i]);
        }
    }
    else if (gen->type == FLOAT)
    {
        float *a = (float *)gen->dado;
        for (int i = 0; i < gen->numElem; i++)
        {
            printf("%.2f ", a[i]);
        }
    }
}