#include <stdio.h>
#include <stdlib.h>
#include "pacote.h"

struct pacote
{
    Type type;
    int numElem;
    void *dado;
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
    p->numElem = numElem;
    p->type = type;
    p->somaver = 0;
    if (p->type == INT)
    {
        p->dado = (int *)calloc(numElem, sizeof(int));
    }
    else if (p->type == CHAR)
    {
        p->dado = (char *)calloc(numElem, sizeof(char));
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
        int *a = (int *)pac->dado;
        for (int i = 0; i < pac->numElem; i++)
        {
            scanf("%d ", &a[i]);
        }
    }
    else if (pac->type == CHAR)
    {
        char *a = (char *)pac->dado;
        for (int i = 0; i < pac->numElem; i++)
        {
            if (i == 0)
                scanf(" %c", &a[i]); // pula o \n anterior
            else
                scanf("%c", &a[i]);
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
    printf("%d ", pac->somaver);
    if (pac->type == INT)
    {
        int *a = (int *)pac->dado;
        for (int i = 0; i < pac->numElem; i++)
        {
            printf("%d ", a[i]);
        }
    }
    else if (pac->type == CHAR)
    {
        char *a = (char *)pac->dado;
        for (int i = 0; i < pac->numElem; i++)
        {
            printf("%c", a[i]);
        }
    }
    printf("\n");
}

/**
 * @brief Calcula a soma de verificacao de um pacote e a armazena internamente
 *
 * @param pac - O vetor genérico que terá sua soma de verificacao calculada
 */
void CalculaSomaVerificacaoPacote(tPacote *pac)
{
    int soma = 0;
    if (pac->type == INT)
    {
        int *a = (int *)pac->dado;
        for (int i = 0; i < pac->numElem; i++)
        {
            soma += a[i];
        }
    }
    else if (pac->type == CHAR)
    {
        char *a = (char *)pac->dado;
        for (int i = 0; i < pac->numElem; i++)
        {
            soma += a[i];
        }
    }
    pac->somaver = soma;
}
