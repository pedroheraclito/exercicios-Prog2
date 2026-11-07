#include <stdio.h>
#include <stdlib.h>
#include "pacote.h"
#include <string.h>
#include "gerenciadorpacotes.h"

int main()
{
    tGerenciador *ger = CriaGerenciador();
    int cod;
    printf("\n");
    printf("Escolha uma opcao:\n");
    printf("	(1) Cadastrar um novo pacote\n");
    printf("	(2) Imprimir um pacote especifico\n");
    printf("	(3) Imprimir todos os pacotes e sair\n");
    scanf("%d", &cod);

    while (1)
    {
        if (cod == 1)
        {
            printf("Digite o tipo (0-char, 1-int) e o numero de elementos do pacote/mensagem: \n");
            Type t = INT;
            int tipo, num;
            scanf("%d %d", &tipo, &num);
            if (tipo == INT)
            {
                t = INT;
            }
            else if (tipo == CHAR)
            {
                t = CHAR;
            }

            tPacote *pac = CriaPacote(t, num);
            LePacote(pac);
            AdicionaPacoteNoGerenciador(ger, pac);
        }
        else if (cod == 2)
        {
            int idx;
            scanf("%d", &idx);
            ImprimirPacoteNoIndice(ger, idx);
        }
        else if (cod == 3)
        {
            ImprimirTodosPacotes(ger);
            break;
        }
        if (cod != 1 && cod != 2 && cod != 3)
        {
            printf("Escolha uma opcao valida para o menu!\n");
        }
        printf("Escolha uma opcao:\n");
        printf("	(1) Cadastrar um novo pacote\n");
        printf("	(2) Imprimir um pacote especifico\n");
        printf("	(3) Imprimir todos os pacotes e sair\n");
        if (scanf("%d", &cod) != 1)
            break;
    }
    DestroiGerenciador(ger);

    return 0;
}