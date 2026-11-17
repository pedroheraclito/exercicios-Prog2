#include <stdio.h>
#include "agendatarefas.h"
#include <stdlib.h>
#include "tarefaimprime.h"
#include <string.h>
#include "tarefamultiplica.h"
#include "tarefasoma.h"
int main()
{
    int numElem;
    scanf("%d", &numElem);
    printf("Digite o numero de tarefas: \n");
    tAgendaTarefas *a = CriaAgendaDeTarefas(numElem);
    for (int i = 0; i < numElem; i++)
    {
        int prioridade;
        char tipo;
        scanf("%d %c", &prioridade, &tipo);

        if (tipo == 'I')
        {
            char msg[50];
            scanf(" %[^\n] ", msg);
            tImpr *imp = CriaTarefaImprimir(msg);
            CadastraTarefaNaAgenda(a, prioridade, imp, ExecutaTarefaImprimir, DestroiTarefaImprimir);
        }
        else if (tipo == 'M')
        {
            float n1, n2;
            scanf(" %f %f ", &n1, &n2);
            tMult *m = CriaTarefaMultiplicar(n1, n2);
            CadastraTarefaNaAgenda(a, prioridade, m, ExecutaTarefaMultiplicar, DestroiTarefaMultiplicar);
        }
        else if (tipo == 'S')
        {
            float n1, n2;
            scanf(" %f %f ", &n1, &n2);
            tSoma *s = CriaTarefaSoma(n1, n2);
            CadastraTarefaNaAgenda(a, prioridade, s, ExecutaTarefaSoma, DestroiTarefaSoma);
        }
        else
        {
            i--;
            printf("Digite um tipo de tarefa suportado (I/S/M))\n");

            scanf(" %*[^\n] ");
        }
    }
    ExecutarTarefasDaAgenda(a);
    DestroiAgendaDeTarefas(a);

    return 0;
}