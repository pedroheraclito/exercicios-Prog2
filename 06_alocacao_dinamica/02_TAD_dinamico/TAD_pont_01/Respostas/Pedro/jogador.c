#include <stdio.h>
#include "jogador.h"
#include <stdlib.h>
#include "jogada.h"
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
        if (EhPosicaoValidaTabuleiro(jogada->x, jogada->y))
        {
            if (EstaLivrePosicaoTabuleiro(tabuleiro, jogada->x, jogada->y))
            {
                jogada->sucesso = 1;
                printf("Jogada [%d,%d]!\n", jogada->x, jogada->y);
            }
            else
            {
                printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", jogada->x, jogada->y);
                jogada->sucesso = 0;
            }
        }
        else
        {
            printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n", jogada->x, jogada->y);
            jogada->sucesso = 0;
        }

        if (FoiJogadaBemSucedida(jogada))
        {
            MarcaPosicaoTabuleiro(tabuleiro, jogador->id, jogada->x, jogada->y);
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
    char c = (jogador->id == PECA_1) ? tabuleiro->peca1 : tabuleiro->peca2;
    int i, j;
    int ganhou;

    /* linhas */
    for (i = 0; i < TAM_TABULEIRO; i++)
    {
        ganhou = 1;
        for (j = 0; j < TAM_TABULEIRO; j++)
        {
            if (tabuleiro->posicoes[i][j] != c)
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
            if (tabuleiro->posicoes[i][j] != c)
                ganhou = 0;
        }
        if (ganhou)
            return 1;
    }

    /* diagonal principal */
    ganhou = 1;
    for (i = 0; i < TAM_TABULEIRO; i++)
    {
        if (tabuleiro->posicoes[i][i] != c)
            ganhou = 0;
    }
    if (ganhou)
        return 1;

    /* diagonal secundária */
    ganhou = 1;
    for (i = 0; i < TAM_TABULEIRO; i++)
    {
        if (tabuleiro->posicoes[i][TAM_TABULEIRO - 1 - i] != c)
            ganhou = 0;
    }
    if (ganhou)
        return 1;

    return 0;
}
