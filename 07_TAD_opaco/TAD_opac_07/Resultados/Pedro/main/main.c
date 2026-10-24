#include <stdio.h>
#include <stdlib.h>
#include "data.h"

int main()
{
    tData *data1 = CriaData();
    tData *data2 = CriaData();
    LeData(data1);
    LeData(data2);
    if (VerificaDataValida(data1) && VerificaDataValida(data2))
    {
        printf("Primeira data: ");
        ImprimeDataExtenso(data1);
        printf("Segunda data: ");
        ImprimeDataExtenso(data2);
        if (ComparaData(data1, data2) == -1)
        {
            printf("A primeira data eh mais antiga\n");
        }
        else if (ComparaData(data1, data2) == 1)
        {
            printf("A segunda data eh mais antiga\n");
        }
        else
        {
            printf("As datas sao iguais\n");
        }
        printf("A diferenca em dias entre as datas eh: %.2d dias\n", CalculaDiferencaDias(data1, data2));
    }else{
        printf("A primeira e/ou segunda data(s) invalida(s)\n");
    }
    LiberaData(data1);
    LiberaData(data2);

    return 0;
}