#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"
#include "sistema.h"

int main()
{
    tSistema *sys = CriaSistema();
    LeSistema(sys);
    ImprimeFaturamentoSistema(sys);
    DestroiSistema(sys);

    return 0;
}