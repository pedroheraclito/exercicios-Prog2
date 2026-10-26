#include <stdio.h>
#include <stdlib.h>
#include "franquia.h"
#include <string.h>
#include "partida.h"
#include "nba.h"

int main()
{
    tNBA nba = CriaNBA();
    RodaNBA(nba);
    ImprimeRelatorioNBA(nba);
    LiberaNBA(nba);

    return 0;
}