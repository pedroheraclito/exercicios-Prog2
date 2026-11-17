#include <stdio.h>
#include <stdlib.h>
#include "tadgen.h"

int main()
{
    int tipo;
    Type type;
    printf("tad_gen_01\n");
    printf("Digite o tipo e numero de elementos: \n");
    int numElem;
    scanf("%d %d", &tipo, &numElem);
    if (tipo==INT)
    {
       type=INT;
    }else if (tipo==FLOAT)
    {
        type=FLOAT;
    }
    tGeneric *g = CriaGenerico(type, numElem);
    LeGenerico(g);
    ImprimeGenerico(g);
    DestroiGenerico(g);
    return 0;
}