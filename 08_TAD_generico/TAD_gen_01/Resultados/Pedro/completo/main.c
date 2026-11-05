#include <stdio.h>
#include <stdlib.h>
#include "tadgen.h"

int main(){
    int tipo;
    int numele;
    scanf("%d %d",&tipo,&numele);
    printf("tad_gen_01\n");
    printf("Digite o tipo e numero de elementos: \n");
   tGeneric *gen= CriaGenerico((Type)tipo,numele);
   LeGenerico(gen);
   ImprimeGenerico(gen);
   DestroiGenerico(gen);


    return 0;
}