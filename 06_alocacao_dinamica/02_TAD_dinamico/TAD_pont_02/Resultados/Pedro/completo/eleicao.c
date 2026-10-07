#include <stdio.h>
#include <stdlib.h>
#include "eleitor.h"
#include "candidato.h"
#include "eleicao.h"

/**
 * @brief Inicializa uma eleição com valores padrão (zerando as variáveis que armazenam votos).
 * Ainda nessa função, é lido a quantidade de candidatos e os candidatos são lidos e armazenados
 * A memória necessária para os vetores "presidentes", "governadores" deve ser alocada aqui.
 * Demais ponteiros devem ser inicializado com NULL.
 * @return Eleição inicializada.
 */
tEleicao *InicializaEleicao()
{
    tEleicao *eleicao = calloc(1, sizeof(tEleicao));
    int Tcandidatos = 0;
    eleicao->totalPresidentes = 0;
    eleicao->totalGovernadores = 0;
    scanf("%d", &Tcandidatos);
    eleicao->presidentes = calloc(Tcandidatos, sizeof(tCandidato *));
    eleicao->governadores = calloc(Tcandidatos, sizeof(tCandidato *));
    eleicao->eleitores = NULL;
    for (int i = 0; i < Tcandidatos; i++)
    {
        tCandidato *candidato = CriaCandidato();
        LeCandidato(candidato);
        if (ObtemCargo(candidato) == 'P')
        {
            eleicao->presidentes[eleicao->totalPresidentes] = candidato;
            eleicao->totalPresidentes++;
        }
        else if (ObtemCargo(candidato) == 'G')
        {
            eleicao->governadores[eleicao->totalGovernadores] = candidato;
            eleicao->totalGovernadores++;
        }
    }
    eleicao->totalEleitores = 0;
    eleicao->votosBrancosGovernador = 0;
    eleicao->votosBrancosPresidente = 0;
    eleicao->votosNulosGovernador = 0;
    eleicao->votosNulosPresidente = 0;
    return eleicao;
}

void ApagaEleicao(tEleicao *eleicao)
{
    for (int i = 0; i < eleicao->totalGovernadores; i++)
    {
        ApagaCandidato(eleicao->governadores[i]);
    }
    for (int i = 0; i < eleicao->totalPresidentes; i++)
    {
        ApagaCandidato(eleicao->presidentes[i]);
    }
    for (int i = 0; i < eleicao->totalEleitores; i++)
    {
        ApagaEleitor(eleicao->eleitores[i]);
    }
    free(eleicao->governadores);
    free(eleicao->presidentes);
    free(eleicao->eleitores);
    free(eleicao);
}

/**
 * @brief Realiza uma eleição.
 * Nessa função, é lido a quantidade de eleitores e os eleitores são lidos e armazenados.
 * @param eleicao Eleição a ser realizada.
 */
void RealizaEleicao(tEleicao *eleicao)
{
 scanf("%d", &eleicao->totalEleitores);
    eleicao->eleitores = calloc(eleicao->totalEleitores, sizeof(tEleitor *));

    for (int i = 0; i < eleicao->totalEleitores; i++)
    {
        tEleitor *eleitor = CriaEleitor();
        LeEleitor(eleitor);
        eleicao->eleitores[i] = eleitor;

        // eleitor votou duas vezes -> anula a eleição
        for (int k = 0; k < i; k++)
        {
            if (EhMesmoEleitor(eleitor, eleicao->eleitores[k]))
            {
                printf("ELEICAO ANULADA\n");
                ApagaEleicao(eleicao);
                exit(0);
            }
        }

        int votoP = ObtemVotoPresidente(eleitor);
        int votoG = ObtemVotoGovernador(eleitor);

        // Presidente
        if (votoP == 0)
            eleicao->votosBrancosPresidente++;
        else
        {
            int achou = 0;
            for (int j = 0; j < eleicao->totalPresidentes && !achou; j++)
            {
                if (VerificaIdCandidato(eleicao->presidentes[j], votoP))
                {
                    IncrementaVotoCandidato(eleicao->presidentes[j]);
                    achou = 1;
                }
            }
            if (!achou)
                eleicao->votosNulosPresidente++;
        }

        // Governador
        if (votoG == 0)
            eleicao->votosBrancosGovernador++;
        else
        {
            int achou = 0;
            for (int j = 0; j < eleicao->totalGovernadores && !achou; j++)
            {
                if (VerificaIdCandidato(eleicao->governadores[j], votoG))
                {
                    IncrementaVotoCandidato(eleicao->governadores[j]);
                    achou = 1;
                }
            }
            if (!achou)
                eleicao->votosNulosGovernador++;
        }
    }
}

/**
 * @brief Imprime o resultado da eleição na tela a partir da aparucao dos votos.
 * @param eleicao Eleição a ser impressa.
 */
void ImprimeResultadoEleicao(tEleicao *eleicao)
{
int numP = 0, numG = 0, empateP = 0, empateG = 0;

    // Presidente: acha o vencedor e conta quantos têm o mesmo número de votos
    if (eleicao->totalPresidentes > 0)
    {
        for (int i = 1; i < eleicao->totalPresidentes; i++)
            if (ObtemVotos(eleicao->presidentes[i]) > ObtemVotos(eleicao->presidentes[numP]))
                numP = i;
        for (int i = 0; i < eleicao->totalPresidentes; i++)
            if (ObtemVotos(eleicao->presidentes[i]) == ObtemVotos(eleicao->presidentes[numP]))
                empateP++;
    }

    // Governador
    if (eleicao->totalGovernadores > 0)
    {
        for (int i = 1; i < eleicao->totalGovernadores; i++)
            if (ObtemVotos(eleicao->governadores[i]) > ObtemVotos(eleicao->governadores[numG]))
                numG = i;
        for (int i = 0; i < eleicao->totalGovernadores; i++)
            if (ObtemVotos(eleicao->governadores[i]) == ObtemVotos(eleicao->governadores[numG]))
                empateG++;
    }

    printf("- PRESIDENTE ELEITO: ");
    if (eleicao->totalPresidentes == 0)
        printf("SEM DECISAO\n");
    else if (empateP > 1)
        printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
    else if (eleicao->votosNulosPresidente + eleicao->votosBrancosPresidente >
             ObtemVotos(eleicao->presidentes[numP]))
        printf("SEM DECISAO\n");
    else
        ImprimeCandidato(eleicao->presidentes[numP],
            CalculaPercentualVotos(eleicao->presidentes[numP], eleicao->totalEleitores));

    printf("- GOVERNADOR ELEITO: ");
    if (eleicao->totalGovernadores == 0)
        printf("SEM DECISAO\n");
    else if (empateG > 1)
        printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
    else if (eleicao->votosNulosGovernador + eleicao->votosBrancosGovernador >
             ObtemVotos(eleicao->governadores[numG]))
        printf("SEM DECISAO\n");
    else
        ImprimeCandidato(eleicao->governadores[numG],
            CalculaPercentualVotos(eleicao->governadores[numG], eleicao->totalEleitores));

    printf("- NULOS E BRANCOS: %d, %d",
        eleicao->votosNulosGovernador + eleicao->votosNulosPresidente,
        eleicao->votosBrancosGovernador + eleicao->votosBrancosPresidente);

}