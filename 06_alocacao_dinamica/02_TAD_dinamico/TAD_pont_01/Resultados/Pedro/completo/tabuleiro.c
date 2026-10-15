#include <stdio.h>
#include "tabuleiro.h"
#include <stdlib.h>

/**
 * Aloca e retorna uma estrutura do tipo tTabuleiro.
 * Se a alocação falhar, o programa é encerrado.
 *
 * @return a estrutura do tipo tTabuleiro alocada.
 */
tTabuleiro *CriaTabuleiro()
{
    tTabuleiro *tab;
    tab = (tTabuleiro *)calloc(1, sizeof(tTabuleiro));
    tab->peca1 = 'X';
    tab->peca2 = '0';
    tab->pecaVazio = '-';
    tab->posicoes = (char **)calloc(TAM_TABULEIRO, sizeof(char *));
    for (int i = 0; i < TAM_TABULEIRO; i++)
    {
        tab->posicoes[i]= (char *)calloc(TAM_TABULEIRO, sizeof(char));
    }
    for (int i = 0; i < TAM_TABULEIRO; i++)
    {
        for (int j = 0; j < TAM_TABULEIRO; j++)
        {
            tab->posicoes[i][j] = tab->pecaVazio;
        }
    }

    return tab;
}

/**
 * Libera a memória de uma estrutura do tipo tTabuleiro.
 *
 * @param tabuleiro a estrutura do tipo tTabuleiro a ser liberada.
 */
void DestroiTabuleiro(tTabuleiro *tabuleiro)
{
    for (int i = 0; i < TAM_TABULEIRO; i++)
    {
        free(tabuleiro->posicoes[i]);
    }
    free(tabuleiro->posicoes);
    free(tabuleiro);
}

/**
 * Marca uma posição do tabuleiro com a peça do jogador.
 *
 * @param tabuleiro o tabuleiro atual.
 * @param peca a peça do jogador (1 ou 2).
 * @param x a coordenada X da posição.
 * @param y a coordenada Y da posição.
 */
void MarcaPosicaoTabuleiro(tTabuleiro *tabuleiro, int peca, int x, int y)
{
    if (PECA_1 == peca)
    {
        tabuleiro->posicoes[y][x] = tabuleiro->peca1;
    }
    else if (PECA_2 == peca)
    {
        tabuleiro->posicoes[y][x] = tabuleiro->peca2;
    }
}

/**
 * Verifica se há alguma posição livre no tabuleiro.
 *
 * @param tabuleiro o tabuleiro atual.
 *
 * @return 1 se há alguma posição livre, 0 caso contrário.
 */
int TemPosicaoLivreTabuleiro(tTabuleiro *tabuleiro)
{
    for (int i = 0; i < TAM_TABULEIRO; i++)
    {
        for (int j = 0; j < TAM_TABULEIRO; j++)
        {
            if (tabuleiro->posicoes[i][j] == tabuleiro->pecaVazio)
            {
                return 1;
            }
        }
    }
    return 0;
}

/**
 * Verifica se a posição do tabuleiro está marcada com a peça do jogador.
 *
 * @param tabuleiro - o tabuleiro atual.
 * @param x a coordenada X da posição.
 * @param y a coordenada Y da posição.
 * @param peca a peça do jogador (1 ou 2).
 *
 * @return 1 se a posição está marcada com a peça do jogador, 0 caso contrário.
 */
int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro *tabuleiro, int x, int y, int peca)
{
    if (PECA_1 == peca)
    {
        if (tabuleiro->posicoes[y][x] == tabuleiro->peca1)
        {
            return 1;
        }
        return 0;
    }
    else if (PECA_2 == peca)
    {
        if (tabuleiro->posicoes[y][x] == tabuleiro->peca2)
        {
            return 1;
        }
        return 0;
    }
    return 0;
}

/**
 * Verifica se a posição do tabuleiro está livre.
 *
 * @param tabuleiro o tabuleiro atual.
 * @param x a coordenada X da posição.
 * @param y a coordenada Y da posição.
 *
 * @return 1 se a posição está livre, 0 caso contrário.
 */
int EstaLivrePosicaoTabuleiro(tTabuleiro *tabuleiro, int x, int y)
{
    if (tabuleiro->posicoes[y][x] == tabuleiro->pecaVazio)
    {
        return 1;
    }
    return 0;
}

/**
 * Verifica se a posição do tabuleiro é válida.
 *
 * @param x a coordenada X da posição.
 * @param y a coordenada Y da posição.
 *
 * @return 1 se a posição é válida, 0 caso contrário.
 */
int EhPosicaoValidaTabuleiro(int x, int y)
{
    if (x >= 0 && x < 3 && y >= 0 && y < 3)
    {
        return 1;
    }
    return 0;
}

/**
 * Imprime o tabuleiro.
 *
 * @param tabuleiro o tabuleiro atual.
 */
void ImprimeTabuleiro(tTabuleiro *tabuleiro)
{
    for (int i = 0; i < TAM_TABULEIRO; i++)
    {
        printf("\t");
        for (int j = 0; j < TAM_TABULEIRO; j++)
        {
          printf("%c",tabuleiro->posicoes[i][j]);  
        }
        printf ("\n");
    }
}