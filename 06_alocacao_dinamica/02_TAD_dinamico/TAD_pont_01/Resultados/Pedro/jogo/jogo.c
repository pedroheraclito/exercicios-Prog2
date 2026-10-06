#include <stdio.h>
#include "jogador.h"
#include <stdlib.h>
#include "jogada.h"
#include "jogo.h"

/**
 * Aloca e retorna uma estrutura do tipo tJogo.
 * Se a alocação falhar, o programa é encerrado.
 *
 * @return a estrutura do tipo tJogo alocada.
 */
tJogo *CriaJogo()
{
    tJogo *jogo = (tJogo *)calloc(1, sizeof(tJogo));
    if (jogo == NULL)
    {
        printf("trol\n");
        exit(1);
    }
    jogo->tabuleiro = CriaTabuleiro();
    jogo->jogador1 = CriaJogador(1);
    jogo->jogador2 = CriaJogador(2);

    return jogo;
}

/**
 * Inicia o jogo, definindo o tabuleiro e os jogadores.
 *
 * @param jogo o jogo a ser iniciado.
 */
void ComecaJogo(tJogo *jogo)
{
    jogo = CriaJogo();
    while (1)
    {

        JogaJogador(jogo->jogador1, jogo->tabuleiro);
        ImprimeTabuleiro(jogo->tabuleiro);
        if (VenceuJogador(jogo->jogador1, jogo->tabuleiro) == 1)
        {
            printf("JOGADOR 1 Venceu!\n");
            break;
        }
        else if (AcabouJogo(jogo))
        {
            printf("Sem vencedor!\n");
            break;
        }

        JogaJogador(jogo->jogador2, jogo->tabuleiro);
        ImprimeTabuleiro(jogo->tabuleiro);
        if (VenceuJogador(jogo->jogador2, jogo->tabuleiro))
        {
            printf("JOGADOR 2 Venceu!\n");
            break;
        }
        else if (AcabouJogo(jogo))
        {
            printf("Sem vencedor!\n");
            break;
        }
    }
    DestroiJogo(jogo);
}

/**
 * Verifica se o jogo acabou (se não há mais posições livres no tabuleiro).
 *
 * @param jogo o jogo atual.
 *
 * @return 1 se o jogo acabou, 0 caso contrário.
 */
int AcabouJogo(tJogo *jogo)
{
    if (TemPosicaoLivreTabuleiro(jogo->tabuleiro))
    {
        return 0;
    }
    return 1;
}

/**
 * Verifica se o usuário deseja jogar novamente.
 *
 * @return 1 se o usuário deseja jogar novamente, 0 caso contrário.
 */
int ContinuaJogo()
{
    char c;
    printf("Jogar novamente? (s,n)\n");
    while (scanf(" %c", &c) == 1)
    {
        if (c == 's')
        {
            return 1;
        }
        else if (c == 'n')
        {
            return 0;
        }
    }
    return 0;
}

/**
 * Libera a memória de uma estrutura do tipo tJogo.
 *
 * @param jogo a estrutura do tipo tJogo a ser liberada.
 */
void DestroiJogo(tJogo *jogo)
{
    DestroiTabuleiro(jogo->tabuleiro);
    DestroiJogador(jogo->jogador1);
    DestroiJogador(jogo->jogador2);
    free(jogo);
}
