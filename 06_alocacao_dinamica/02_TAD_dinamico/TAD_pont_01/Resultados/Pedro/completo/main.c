#include <stdio.h>
#include "jogador.h"
#include <stdlib.h>
#include "jogada.h"
#include "jogo.h"

int main()
{

    tJogo *jogo;
    jogo = CriaJogo();
    ComecaJogo(jogo);
    DestroiJogo(jogo);
    while (ContinuaJogo())
    {
        jogo = CriaJogo();
        ComecaJogo(jogo);
        DestroiJogo(jogo);
    }

    return 0;
}