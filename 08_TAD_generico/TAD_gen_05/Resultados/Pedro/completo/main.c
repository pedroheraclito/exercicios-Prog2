#include <stdio.h>
#include <stdlib.h>
#include "tarefaimprime.h"
#include <string.h>
#include "tarefamultiplica.h"
#include "tarefasoma.h"

#include "agendatarefas.h"

int main()
{
    int numelem;
    scanf("%d", &numelem);
    int prioridade;
    char cod;
    printf("Digite o numero de tarefas: ");
    tAgendaTarefas *agenda = CriaAgendaDeTarefas(numelem);
    for (int i = 0; i < numelem; i++)
    {
        scanf("%d %c ", &prioridade, &cod);

        if (cod == 'I')
        {
            char msg[50];
            scanf(" %[^\n]", msg);
            tImpr *imp = CriaTarefaImprimir(msg);
            CadastraTarefaNaAgenda(agenda, prioridade, imp, ExecutaTarefaImprimir, DestroiTarefaImprimir);
        }
        else if (cod == 'S')
        {
            float n1, n2;
            scanf("%f %f", &n1, &n2);
            tSoma *soma = CriaTarefaSoma(n1, n2);
            CadastraTarefaNaAgenda(agenda, prioridade, soma, ExecutaTarefaSoma, DestroiTarefaSoma);
        }
        else if (cod == 'M')
        {
            float n1, n2;
            scanf("%f %f", &n1, &n2);
            tMult *mult = CriaTarefaMultiplicar(n1, n2);
            CadastraTarefaNaAgenda(agenda, prioridade, mult, ExecutaTarefaMultiplicar, DestroiTarefaMultiplicar);
        }
        else
        {
            printf("\nDigite um tipo de tarefa suportado (I/S/M))\n");
             scanf("%*[^\n]"); 
              i--; 
        }
    }
    ExecutarTarefasDaAgenda(agenda);
    DestroiAgendaDeTarefas(agenda);

    return 0;
}