#include <stdio.h>
#include <stdlib.h>
#include "vendedor.h"
#include <string.h>
#include "loja.h"

int main()
{
    int qtdlojas, atual = 0;
    int cod;

    int id;
    float aluguel;
    float valor;
    char nome[50];
    int tipo, tipo2;
    float salario;
    float prct_comissao;
    scanf("%d", &qtdlojas);
    tLoja *lojas[qtdlojas];
    scanf("%d", &cod);
    while (1)
    {
        if (cod == 1)
        {
            scanf("%d %f", &id, &aluguel);
            lojas[atual] = AbreLoja(id, aluguel);
            atual++;
        }
        else if (cod == 2)
        {
            scanf(" %s %f %f", nome, &salario, &prct_comissao);
            scanf("%d", &tipo);
            tVendedor *vendedor = RegistraVendedor(nome, salario, prct_comissao);
            ContrataVendedor(lojas[tipo-1], vendedor);
        }
        else if (cod == 3)
        {
            scanf(" %d %s %f", &tipo2, nome, &valor);
            RegistraVenda(lojas[tipo2-1], nome, valor);
        }
        else if (cod == 4)
        {
            for (int i = 0; i < qtdlojas; i++)
            {
                CalculaLucro(lojas[i]);
                ImprimeRelatorioLoja(lojas[i]);
            }
        }
        else if (cod == 0)
        {
            break;
        }

        scanf("%d", &cod);
    }
    for (int i = 0; i < qtdlojas; i++)
    {
        ApagaLoja(lojas[i]);
    }

    return 0;
}