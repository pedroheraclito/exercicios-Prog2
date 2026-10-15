#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "math.h"

int main()
{
    tData *data=CriaData();
    LeData(data);
    int valor=VerificaDataValida(data);
    printf("%d",valor);

        return 0;
}