#include <stdio.h>
#include <stdlib.h>
#include "gerenciadorpacotes.h"

int main()
{

    tGerenciador *g = CriaGerenciador();
    int cod;

    while (1)
    {
        printf("\nEscolha uma opcao:\n");
        printf("	(1) Cadastrar um novo pacote\n");
        printf("	(2) Imprimir um pacote especifico\n");
        printf("	(3) Imprimir todos os pacotes e sair\n");
        printf("Digite o tipo (0-char, 1-int) e o numero de elementos do pacote/mensagem: ");
        scanf("%d", &cod);
        if (cod == 1)
        {
            int tipo, numElem;
            Type type;
            scanf("%d %d", &tipo, &numElem);
            if (tipo == INT)
            {
                type = INT;
                tPacote *p = CriaPacote(type, numElem);
                LePacote(p);
                AdicionaPacoteNoGerenciador(g, p);
            }
            else if (tipo == CHAR)
            {
                type = CHAR;
                tPacote *p = CriaPacote(type, numElem);
                LePacote(p);
                AdicionaPacoteNoGerenciador(g, p);
            }
        }
        else if (cod == 2)
        {
            int idx;
            scanf("%d", &idx);
            ImprimirPacoteNoIndice(g, idx);
        }
        else if (cod == 3)
        {
            ImprimirTodosPacotes(g);
            break;
            
        }
        else
        {
            printf("Escolha uma opcao valida para o menu!\n");
        }
    }
    DestroiGerenciador(g);
    return 0;
}