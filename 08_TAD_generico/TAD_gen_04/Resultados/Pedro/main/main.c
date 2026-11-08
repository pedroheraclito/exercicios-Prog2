#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "banco.h"

int main()
{
    char cod;
    int numAgencia;
    tBanco *b = CriaBanco();
    LeBanco(b);
    scanf(" %c", &cod);
    while (1)
    {
        if (cod == 'A')
        {
            tAgencia*a=CriaAgencia();
            LeAgencia(a);
            AdicionaAgencia(b,a);
        }
        else if (cod == 'C')
        {
          tConta *c=CriaConta();
          LeConta(c);
          scanf("%d",&numAgencia);
          InsereContaBanco(b,numAgencia,c);
        }
        else if (cod == 'F')
        {
            break;
        }

        scanf(" %c", &cod);
    }
    ImprimeRelatorioBanco(b);
    DestroiBanco(b);

    return 0;
}