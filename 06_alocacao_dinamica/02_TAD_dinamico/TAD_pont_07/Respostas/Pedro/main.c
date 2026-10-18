#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "math.h"

int main()
{
    tData *data1 = CriaData(); // Criacao e leitura
    LeData(data1);
    tData *data2 = CriaData();
    LeData(data2);
    if (!VerificaDataValida(data1))
    {
        printf("A primeira e/ou segunda data(s) invalida(s)\n");
        LiberaData(data1);
        LiberaData(data2);
        return 0;
    }
    else if (!VerificaDataValida(data2))
    {
        printf("A primeira e/ou segunda data(s) invalida(s)\n");
        LiberaData(data1);
        LiberaData(data2);
        return 0;
    }

    printf("Primeira data: "); // Impressao
    ImprimeDataExtenso(data1);
    printf("Segunda data: ");
    ImprimeDataExtenso(data2);

    if (ComparaData(data1, data2) == 1)
    {
        printf("A segunda data eh mais antiga\n");
    }
    else if (ComparaData(data1, data2) == -1)
    {
        printf("A primeira data eh mais antiga\n");
    }
    else
    {
        printf("As datas sao iguais\n");
    }
    printf("A diferenca em dias entre as datas eh: %.2d dias\n", CalculaDiferencaDias(data1, data2));
    LiberaData(data1);
    LiberaData(data2);

    return 0;
}