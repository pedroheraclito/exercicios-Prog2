#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"
#include "movel.h"

int main()
{
    int tam;
    Fila *fil = FilaConstruct();
    char com[50];
    scanf("%d", &tam);
    for (int i = 0; i < tam; i++)
    {
        scanf(" %s", com);
        if (strcmp(com, "PRODUZIR")==0)
        {
            tMovel *m = FilaPop(fil);
            ImprimeMovel(m);
            DestroiMovel(m);
        }
        else if (strcmp(com, "ENTRADA")==0)
        {

            tMovel *m = LeMovel();
            FilaPush(fil, m);
        }
    }
    FilaDestroy(fil, DestroiMovel);
    return 0;
}