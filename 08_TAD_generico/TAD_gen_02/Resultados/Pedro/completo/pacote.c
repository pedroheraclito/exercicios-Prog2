#include <stdio.h>
#include <stdlib.h>
#include "pacote.h"
#include <string.h>

struct pacote
{
    int numelem;
    void *dado;
    Type type;
    int somaver;
};

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar um pacote a ser transmitido
 *
 * @param type - Tipo do vetor genérico. Segue o Enum definido acima.
 * @param numElem A quantidade de elementos que serão armazenados no vetor
 *
 * @return O vetor genérico
 */
tPacote *CriaPacote(Type type, int numElem)
{
    tPacote *p = (tPacote *)calloc(1, sizeof(tPacote));

    p->numelem = numElem;
    p->type = type;
    p->somaver = 0;
    p->dado = NULL;
    if (type == INT)
    {
        p->dado = calloc(numElem, sizeof(int));
    }
    if (type == CHAR)
    {
        p->dado = calloc(numElem, sizeof(char));
    }

    return p;
}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param pac - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiPacote(tPacote *pac)
{

    free(pac->dado);
    free(pac);
}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param pac - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LePacote(tPacote *pac)
{

    if (pac->type == INT)
    {
        int *vet = (int *)pac->dado;
        for (int i = 0; i < pac->numelem; i++)
        {
            scanf("%d", &vet[i]);
        }
    }
    else if (pac->type == CHAR)
    {
        char *vet = (char *)pac->dado;
        for (int i = 0; i < pac->numelem; i++)
        {

            if (i == 0)
                scanf(" %c", &vet[i]); // pula o \n anterior
            else
                scanf("%c", &vet[i]);
        }
    }
}

/**
 * @brief Imprime na tela um pacote que possui um id específico com seu valor calculado
 *
 * @param pac - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimePacote(tPacote *pac)
{
    CalculaSomaVerificacaoPacote(pac);
    if (pac->type == INT)
    {
        printf("%d ", pac->somaver);
        int *vet = (int *)pac->dado;
        for (int i = 0; i < pac->numelem; i++)
        {
            printf("%d ", vet[i]);
        }
    }
    else if (pac->type == CHAR)
    {
        printf("%d ", pac->somaver);
        char *vet = (char *)pac->dado;
        for (int i = 0; i < pac->numelem; i++)
        {
            printf("%c", vet[i]);
        }
    }
}

/**
 * @brief Calcula a soma de verificacao de um pacote e a armazena internamente
 *
 * @param pac - O vetor genérico que terá sua soma de verificacao calculada
 */
void CalculaSomaVerificacaoPacote(tPacote *pac)
{
    pac->somaver = 0;
    if (pac->type == INT)
    {
        int *vet = (int *)pac->dado;
        for (int i = 0; i < pac->numelem; i++)
        {
            pac->somaver += vet[i];
        }
    }
    else if (pac->type == CHAR)
    {
        char *vet = (char *)pac->dado;
        for (int i = 0; i < pac->numelem; i++)
        {
            pac->somaver += vet[i];
        }
    }
}