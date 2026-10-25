#include <stdio.h>
#include <stdlib.h>
#include "jogo.h"
#include "computador.h"

int main()
{
    tComputador *cmp = CriaComputador();
    GerenciaJogo(cmp);
    ImprimeRelatorio(cmp);
    DestroiComputador(cmp);

    return 0;
}