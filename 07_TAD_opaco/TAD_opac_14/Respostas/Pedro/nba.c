#include <stdio.h>
#include <stdlib.h>
#include "franquia.h"
#include <string.h>
#include "partida.h"
#include "nba.h"

#define MAX_FR 10        // Número máximo de franquias
#define MAX_PT 10        // Número máximo de partidas
#define CAD_FRANQUIA 'F' // Caractere para cadastro de franquia
#define CAD_PARTIDA 'P'  // Caractere para cadastro de partida
#define ENCERRAR 'E'     // Caractere para encerrar a NBA

struct nba
{
    tFranquia f[20];
    tPartida p[20];
    int qtdF;
    int qtdP;
};

/**
 * @brief Cria uma nova instância da NBA.
 *
 * @return tNBA Retorna um ponteiro para a nova instância da NBA.
 */
tNBA CriaNBA()
{
    struct nba *nba = calloc(1, sizeof(struct nba));
    nba->qtdF = 0;
    nba->qtdP = 0;
    return nba;
}

/**
 * @brief Roda a NBA, permitindo a interação com o usuário.
 *
 * @param nba Ponteiro para a instância da NBA a ser executada.
 * @return tNBA Retorna um ponteiro para a instância da NBA após a execução.
 */
tNBA RodaNBA(tNBA nba)
{
    char cod;
    scanf(" %c", &cod);
    while (1)
    {
        if (cod == 'F')
        {
            if (nba->qtdF < 20)
            {
                nba->f[nba->qtdF] = LeFranquia();
                nba->qtdF++;
            }
            else
            {
                LiberaFranquia(LeFranquia());
            }
        }
        else if (cod == 'P')
        {
            if (nba->qtdP < 20)
            {

                nba->p[nba->qtdP] = LePartida();

                if (GetVencedorPartida(nba->p[nba->qtdP]) == 1)
                {
                    for (int i = 0; i < nba->qtdF; i++)
                    {
                        if (strcmp(GetNomeFranquia(nba->f[i]), GetTime1Partida(nba->p[nba->qtdP])) == 0)
                        {
                            AdicionaVitoriaCasaFranquia(nba->f[i]);
                        }
                        if (strcmp(GetNomeFranquia(nba->f[i]), GetTime2Partida(nba->p[nba->qtdP])) == 0)
                        {
                            AdicionaDerrotaForaFranquia(nba->f[i]);
                        }
                    }
                }
                else if (GetVencedorPartida(nba->p[nba->qtdP]) == 2)
                {
                    for (int i = 0; i < nba->qtdF; i++)
                    {
                        if (strcmp(GetNomeFranquia(nba->f[i]), GetTime1Partida(nba->p[nba->qtdP])) == 0)
                        {
                            AdicionaDerrotaCasaFranquia(nba->f[i]);
                        }
                        if (strcmp(GetNomeFranquia(nba->f[i]), GetTime2Partida(nba->p[nba->qtdP])) == 0)
                        {
                            AdicionaVitoriaForaFranquia(nba->f[i]);
                        }
                    }
                }

                nba->qtdP++;
            }
            else
            {
                LiberaPartida(LePartida());
            }
        }
        else if (cod == 'E')
        {
            break;
        }
        scanf(" %c", &cod);
    }
    return nba;
}

/**
 * @brief Imprime o relatório final da NBA.
 *
 * @param nba Ponteiro para a instância da NBA a ser impressa.
 */
void ImprimeRelatorioNBA(tNBA nba)
{
    int vitL = 0, vitO = 0, derL = 0, derO = 0;
    for (int i = 0; i < nba->qtdF; i++)
    {
        ImprimeFranquia(nba->f[i]);
    }
    for (int i = 0; i < nba->qtdF; i++)
    {
        if (strcmp(GetConferenciaFranquia(nba->f[i]), "LESTE") == 0)
        {
            derL += GetDerrotaCasaFranquia(nba->f[i]) + GetDerrotaForaFranquia(nba->f[i]);
            vitL += GetVitoriaCasaFranquia(nba->f[i]) + GetVitoriaForaFranquia(nba->f[i]);
        }
        else if (strcmp(GetConferenciaFranquia(nba->f[i]), "OESTE") == 0)
        {
            derO += GetDerrotaCasaFranquia(nba->f[i]) + GetDerrotaForaFranquia(nba->f[i]);
            vitO += GetVitoriaCasaFranquia(nba->f[i]) + GetVitoriaForaFranquia(nba->f[i]);
        }
    }
    float aproxL = ((float)vitL / (vitL + derL));
    float aproxO = ((float)vitO / (vitO + derO));
    if (vitL == 0)
    {
        aproxL = 0;
    }
    if (vitO == 0)
    {
        aproxO = 0;
    }

    printf("LESTE %d %d %.2f\n", vitL, derL, aproxL * 100);
    printf("OESTE %d %d %.2f\n", vitO, derO, aproxO * 100);
}

/**
 * @brief Libera a memória alocada para a instância da NBA.
 *
 * @param nba Ponteiro para a instância da NBA a ser liberada.
 */
void LiberaNBA(tNBA nba)
{
    for (int i = 0; i < nba->qtdF; i++)
    {
        LiberaFranquia(nba->f[i]);
    }
    for (int i = 0; i < nba->qtdP; i++)
    {
        LiberaPartida(nba->p[i]);
    }
    free(nba);
}