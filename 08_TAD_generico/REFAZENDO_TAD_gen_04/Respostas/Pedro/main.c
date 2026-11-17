#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "banco.h"

int main()
{
    tBanco *b = CriaBanco();
    int numAgencia=0;
    LeBanco(b);
    char cod;
    while (1)
    {
        scanf(" %c", &cod);
        if (cod == 'C')
        {
            tConta *c=CriaConta();
            LeConta(c);
            scanf("%d",&numAgencia);
            InsereContaBanco(b,numAgencia,c);
        }
        else if (cod == 'A')
        {
          tAgencia *a=CriaAgencia();
          LeAgencia(a);
          AdicionaAgencia(b,a);
        }
        else if (cod == 'F')
        {
            break;
        }
    }
    ImprimeRelatorioBanco(b);
    DestroiBanco(b);
    return 0;
}