#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "movel.h"
#include <string.h>
#include "fila.h"

int main()
{

    int qtd;
    char comando[20];
    scanf("%d", &qtd);
    Fila *fil = FilaConstruct();
    for (int i = 0; i < qtd; i++)
    {
        scanf(" %s", comando);
        if (strcmp("ENTRADA", comando) == 0)
        {
            tMovel *mov = LeMovel();
            FilaPush(fil, mov);
        }
        else if (strcmp("PRODUZIR", comando) == 0)
        {
            tMovel *m = FilaPop(fil);
            ImprimeMovel(m);
            DestroiMovel(m);
        }
    }
    FilaDestroy(fil, DestroiMovel);

    return 0;
}