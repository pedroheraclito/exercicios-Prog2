#include <stdio.h>
#include <stdlib.h>
#include "tadgen.h"

struct generic
{
    int numElem;
    Type tipo;
    void *numeros;
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
    tGeneric *gen = (tGeneric *)calloc(1, sizeof(tGeneric));
    gen->numElem = numElem;
    gen->tipo = type;
    if (gen->tipo == INT)
    {

        gen->numeros = calloc(numElem, sizeof(int));
        int*vet = (int *)gen->numeros;
        for (int i = 0; i < gen->numElem; i++)
        {
            scanf("%d ", &vet[i]);
        }
    }
    else if (gen->tipo == FLOAT)
    {
        gen->numeros = calloc(numElem, sizeof(float));
        float *vet = (float *)gen->numeros;
        for (int i = 0; i < gen->numElem; i++)
        {
            scanf("%f ", &vet[i]);
        }
    }

    return gen;
}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param gen - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiGenerico(tGeneric *gen)
{
    
    if (gen == NULL)
        exit(1);
    free(gen->numeros);
    free(gen);
}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param gen - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LeGenerico(tGeneric *gen)
{
    if (gen->tipo == INT)
    {
        int *vet = (int *)gen->numeros;
        for (int i = 0; i < gen->numElem; i++)
            scanf("%d", &vet[i]);
    }
    else if (gen->tipo == FLOAT)
    {
        float *vet = (float *)gen->numeros;
        for (int i = 0; i < gen->numElem; i++)
            scanf("%f", &vet[i]);
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
    if (gen->tipo == INT)
    {
        int *vet=(int*)gen->numeros;
        for (int i = 0; i < gen->numElem; i++)
        {
            printf("%d ",vet[i]);
        }
    }
    else if (gen->tipo == FLOAT)
    {
        float *vet=(float*)gen->numeros;
        for (int i = 0; i < gen->numElem; i++)
        {
            printf("%.2f ", vet[i]);
        }
    }
    printf("\n");
}