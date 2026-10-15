#include <stdio.h>
#include <stdlib.h>
#include "eleitor.h"
#include "candidato.h"
#include "eleicao.h"

int main()
{
    tEleicao *eleicao = InicializaEleicao();
    RealizaEleicao(eleicao);
    ImprimeResultadoEleicao(eleicao);
    ApagaEleicao(eleicao);

    return 0;
}