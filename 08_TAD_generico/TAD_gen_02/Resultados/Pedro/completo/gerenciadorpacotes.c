#include <stdio.h>
#include <stdlib.h>
#include "pacote.h"
#include <string.h>
#include "gerenciadorpacotes.h"
struct gerenciadorpacotes
{
    tPacote **pacotes;
    int qtdpacotes;
};

/**
 * @brief Cria uma TAD que gerencia pacotes. O pacote é um TAD genérico.
 *
 *
 * @return O gerenciador de pacotes
 */
tGerenciador *CriaGerenciador()
{
    tGerenciador *ger = (tGerenciador *)calloc(1, sizeof(tGerenciador));

    ger->pacotes = (tPacote **)calloc(1, sizeof(tPacote *));
    ger->qtdpacotes = 0;

    return ger;
}

/**
 * @brief Adiciona um pacote ao gerenciador de pacotes.
 *
 * @param geren O gerenciador de pacotes que armazenará o pacote
 * @param pac O pacote que queremos adicionar no gerenciador.
 *
 */
void AdicionaPacoteNoGerenciador(tGerenciador *geren, tPacote *pac)
{
    geren->pacotes=realloc(geren->pacotes,(geren->qtdpacotes+1)*sizeof(tPacote**));
    geren->pacotes[geren->qtdpacotes] = pac;
    geren->qtdpacotes++;
}

/**
 * @brief Destrói um gerenciador de pacotes
 *
 * @param geren O gerenciador de pacotes que será destruído (memória liberada)
 *
 */
void DestroiGerenciador(tGerenciador *geren)
{
    for (int i = 0; i < geren->qtdpacotes; i++)
    {
        DestroiPacote(geren->pacotes[i]);
    }
    free(geren->pacotes);
    free(geren);
}

/**
 * @brief Imprime um pacote específico do gerenciador de pacotes.
 *
 * @param geren - O gerenciador de pacotes que terá um pacote impresso
 * @param idx - O índice do pacote a ser impresso (começa em zero!)
 *
 */
void ImprimirPacoteNoIndice(tGerenciador *geren, int idx)
{
    ImprimePacote(geren->pacotes[idx]);
}

/**
 * @brief Imprime todos os pacotes de um gerenciador de pacotes
 *
 * @param geren O gerenciador de pacotes que terá seus pacotes impressos
 *
 */
void ImprimirTodosPacotes(tGerenciador *geren){
    for (int i = 0; i < geren->qtdpacotes; i++)
    {
        ImprimePacote(geren->pacotes[i]);
    }
    
}