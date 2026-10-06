#include <stdio.h>
#include "jogada.h"
#include <stdlib.h>

/**
 * Aloca e retorna uma estrutura do tipo tJogada.
 * Se a alocação falhar, o programa é encerrado.
 *
 * @return a estrutura do tipo tJogada alocada.
 */
tJogada *CriaJogada()
{
    tJogada *jogada;
    jogada = (tJogada *)calloc(1, sizeof(tJogada));
    return jogada;
}

/**
 * Libera a memória de uma estrutura do tipo tJogada.
 *
 * @param jogada a estrutura do tipo tJogada a ser liberada.
 */
void DestroiJogada(tJogada *jogada)
{
    free(jogada);
}

/**
 * Lê uma jogada e armazena em uma estrutura do tipo tJogada.
 *
 * @param jogada a estrutura do tipo tJogada a ser preenchida.
 */
void LeJogada(tJogada *jogada)
{
    printf("Digite uma posicao (x e y):\n");
    if (scanf("%d %d", &jogada->x, &jogada->y) == 2)
    {
        jogada->sucesso = 1;
    }
    else
    {
        jogada->sucesso = 0;
    }
}

/**
 * Retorna a coordenada X da jogada.
 *
 * @param jogada a estrutura do tipo tJogada.
 *
 * @return a coordenada X da jogada.
 */
int ObtemJogadaX(tJogada *jogada)
{
    return jogada->x;
}

/**
 * Retorna a coordenada Y da jogada.
 *
 * @param jogada a estrutura do tipo tJogada.
 *
 * @return a coordenada Y da jogada.
 */
int ObtemJogadaY(tJogada *jogada)
{
    return jogada->y;
}

/**
 * Retorna 1 se a jogada foi bem sucedida e 0 caso contrário.
 *
 * @param jogada a estrutura do tipo tJogada.
 *
 * @return 1 se a jogada foi bem sucedida, 0 caso contrário.
 */
int FoiJogadaBemSucedida(tJogada *jogada)
{
    if (jogada->sucesso)
    {
        return 1;
    }
    return 0;
}
