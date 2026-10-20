#include <stdio.h>
#include <stdlib.h>
#include "jogador.h"
#include "jogada.h"

struct Jogador
{
    int id;
};
/**
 * Aloca e retorna uma estrutura do tipo tJogador.
 * Se a alocação falhar, o programa é encerrado.
 *
 *  @param idJogador o ID do jogador (1 ou 2).
 *
 * @return a estrutura do tipo tJogador alocada.
 */
tJogador *CriaJogador(int idJogador)
{
    tJogador *jogador = (tJogador *)calloc(1, sizeof(tJogador));
    jogador->id = idJogador;
    return jogador;
}

/**
 * Libera a memória de uma estrutura do tipo tJogador.
 *
 * @param jogador a estrutura do tipo tJogador a ser liberada.
 */
void DestroiJogador(tJogador *jogador)
{
    free(jogador);
}

/**
 * Lê uma jogada e armazena em uma estrutura do tipo tJogada.
 *
 * @param jogador o jogador atual.
 * @param tabuleiro o tabuleiro atual.
 */
void JogaJogador(tJogador *jogador, tTabuleiro *tabuleiro)
{
    tJogada *jogada = CriaJogada();
    int x, y;
    int cont = 0;
    while (1)
    {

        if (PECA_1 == jogador->id)
        {
            printf("Jogador 1\n");
        }
        else if (PECA_2 == jogador->id)
        {
            printf("Jogador 2\n");
        }
        LeJogada(jogada);
        if (!FoiJogadaBemSucedida(jogada))
        {
            continue;
        }

        x = ObtemJogadaX(jogada);
        y = ObtemJogadaY(jogada);

        if (!EhPosicaoValidaTabuleiro(x, y))
        {
            printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n", x, y);
        }
        else if (!EstaLivrePosicaoTabuleiro(tabuleiro, x, y))
        {
            printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", x, y);
        }
        else
        {
            printf("Jogada [%d,%d]!\n", x, y);
            MarcaPosicaoTabuleiro(tabuleiro, jogador->id, x, y);
            break;
        }
    }
    DestroiJogada(jogada);
}

/**
 * Verifica se o jogador venceu o jogo.
 *
 * @param jogador o jogador atual.
 * @param tabuleiro o tabuleiro atual.
 *
 * @return 1 se o jogador venceu, 0 caso contrário.
 */
int VenceuJogador(tJogador *jogador, tTabuleiro *tabuleiro)
{
    int peca = jogador->id;   /* ajuste para o getter que você tem */
    int i, j;
    int ganhou;

    /* linhas */
    for (i = 0; i < TAM_TABULEIRO; i++)
    {
        ganhou = 1;
        for (j = 0; j < TAM_TABULEIRO; j++)
        {
            /* x = coluna (j), y = linha (i) */
            if (!EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, j, i, peca))
                ganhou = 0;
        }
        if (ganhou)
            return 1;
    }

    /* colunas */
    for (j = 0; j < TAM_TABULEIRO; j++)
    {
        ganhou = 1;
        for (i = 0; i < TAM_TABULEIRO; i++)
        {
            if (!EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, j, i, peca))
                ganhou = 0;
        }
        if (ganhou)
            return 1;
    }

    /* diagonal principal */
    ganhou = 1;
    for (i = 0; i < TAM_TABULEIRO; i++)
    {
        if (!EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, i, i, peca))
            ganhou = 0;
    }
    if (ganhou)
        return 1;

    /* diagonal secundária */
    ganhou = 1;
    for (i = 0; i < TAM_TABULEIRO; i++)
    {
        if (!EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, TAM_TABULEIRO - 1 - i, i, peca))
            ganhou = 0;
    }
    if (ganhou)
        return 1;

    return 0;
}