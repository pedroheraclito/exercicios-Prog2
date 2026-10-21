#include <stdio.h>
#include <stdlib.h>
#include "usuario.h"
#include <string.h>
#include "conta.h"
#include "banco.h"

int main()
{
    tBanco *banco = CriaBanco();
    char cod;
    scanf(" %c ", &cod);
    while (1)
    {
        if (cod == 'A')
        {
            AbreContaBanco(banco);
        }
        else if (cod == 'T')
        {
            TransferenciaContaBanco(banco);
        }
        else if (cod == 'D')
        {
            DepositoContaBanco(banco);
        }
        else if (cod == 'R')
        {
            ImprimeRelatorioBanco(banco);
        }
        else if (cod == 'S')
        {
            SaqueContaBanco(banco);
        }
        else if (cod == 'F')
        {
            break;
        }
        scanf(" %c ", &cod);
    }
    DestroiBanco(banco);
    return 0;
}