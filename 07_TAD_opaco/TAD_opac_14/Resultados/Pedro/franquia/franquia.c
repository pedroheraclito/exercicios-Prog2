#include <stdio.h>
#include <stdlib.h>
#include "franquia.h"
#include <string.h>

/**
 * @brief Estrutura que representa uma franquia.
 *
 * A estrutura franquia contém informações sobre o nome da franquia, sua conferência e seu desempenho em casa e fora.
 *
 */
struct franquia
{
    char *nome;
    char *conf;
    int vitC;
    int derC;
    int vitF;
    int derF;
};

#define MAX_NOME 32

/**
 * @brief Lê uma franquia da entrada padrao e retorna um ponteiro para ela.
 *
 * @return tFranquia Retorna um ponteiro para a franquia lida.
 */
tFranquia LeFranquia()
{
    struct franquia *f = calloc(1, sizeof(struct franquia));

    f->vitC = 0;
    f->derC = 0;
    f->vitF = 0;
    f->derF = 0;
    f->conf = calloc(MAX_NOME, sizeof(char));
    f->nome = calloc(MAX_NOME, sizeof(char));
    scanf(" %s %s", f->nome, f->conf);

    return f;
}

/**
 * @brief Libera a memória alocada para uma franquia.
 *
 * @param f Ponteiro para a franquia a ser liberada.
 */
void LiberaFranquia(tFranquia f)
{
    free(f->conf);
    free(f->nome);
    free(f);
}

/**
 * @brief Imprime as informações de uma franquia.
 *
 * @param f Ponteiro para a franquia a ser impressa.
 */
void ImprimeFranquia(tFranquia f)
{
    float apro;
    if ((f->vitC + f->vitF)>0)
    {
        apro = (float)(f->vitC + f->vitF) / (f->derC + f->derF + f->vitC + f->vitF);
        apro = apro * 100;
    }else{
         apro=0;
    }

    printf("%s ", f->nome);
    if (strcmp(f->conf, "LESTE"))
    {
        printf("[CO]");
    }
    else
    {
        printf("[CL]");
    }
    printf(" %d %d %.2f %d %d\n", f->vitC + f->vitF, f->derC + f->derF, apro, f->vitC, f->vitF);
}

/**
 * @brief Retorna o nome da franquia.
 *
 * @param f Ponteiro para a franquia.
 * @return char* Retorna o nome da franquia.
 */
char *GetNomeFranquia(tFranquia f)
{
    return f->nome;
}

/**
 * @brief Retorna a conferência da franquia.
 *
 * @param f Ponteiro para a franquia.
 * @return char* Retorna a conferência da franquia.
 */
char *GetConferenciaFranquia(tFranquia f)
{
    return f->conf;
}

/**
 * @brief Adiciona uma vitória em casa para a franquia.
 *
 * @param f Ponteiro para a franquia.
 */
void AdicionaVitoriaCasaFranquia(tFranquia f)
{
    f->vitC++;
}

/**
 * @brief Adiciona uma vitória fora de casa para a franquia.
 *
 * @param f Ponteiro para a franquia.
 */
void AdicionaVitoriaForaFranquia(tFranquia f)
{
    f->vitF++;
}

/**
 * @brief Adiciona uma derrota em casa para a franquia.
 *
 * @param f Ponteiro para a franquia.
 */
void AdicionaDerrotaCasaFranquia(tFranquia f)
{
    f->derC++;
}

/**
 * @brief Adiciona uma derrota fora de casa para a franquia.
 *
 * @param f Ponteiro para a franquia.
 */
void AdicionaDerrotaForaFranquia(tFranquia f)
{
    f->derF++;
}

/**
 * @brief Retorna o número de vitórias em casa da franquia.
 *
 * @param f Ponteiro para a franquia.
 * @return int Retorna o número de vitórias em casa da franquia.
 */
int GetVitoriaCasaFranquia(tFranquia f)
{
    return f->vitC;
}

/**
 * @brief Retorna o número de vitórias fora de casa da franquia.
 *
 * @param f Ponteiro para a franquia.
 * @return int Retorna o número de vitórias fora de casa da franquia.
 */
int GetVitoriaForaFranquia(tFranquia f)
{
    return f->vitF;
}

/**
 * @brief Retorna o número de derrotas em casa da franquia.
 *
 * @param f Ponteiro para a franquia.
 * @return int Retorna o número de derrotas em casa da franquia.
 */
int GetDerrotaCasaFranquia(tFranquia f)
{
    return f->derC;
}

/**
 * @brief Retorna o número de derrotas fora de casa da franquia.
 *
 * @param f Ponteiro para a franquia.
 * @return int Retorna o número de derrotas fora de casa da franquia.
 */
int GetDerrotaForaFranquia(tFranquia f)
{
    return f->derF;
}