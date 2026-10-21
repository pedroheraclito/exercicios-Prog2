#include <stdio.h>
#include <stdlib.h>
#include "empresa.h"

int main()
{
    int qtdempresas;
    scanf("%d ", &qtdempresas);
    tEmpresa *empresa[qtdempresas];
    for (int i = 0; i < qtdempresas; i++)
    {
        empresa[i] = CriaEmpresa();
        LeEmpresa(empresa[i]);
    }
    for (int i = 0; i < qtdempresas; i++)
    {
        ImprimeEmpresa(empresa[i]);
        ApagaEmpresa(empresa[i]);
    }

    return 0;
}