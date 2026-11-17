#include <stdio.h>
#include <stdlib.h>
#include "tarefaimprime.h"
#include <string.h>
#include "agendatarefas.h"

typedef struct
{
    int prioridade;
    void *tarefa;
    void (*executa)(void *);
    void (*destroi)(void *);
} item;

struct agendatarefas
{
    int numelem;
    item **item;
    int qtdatutal;
};

/**
 * @brief Cria uma variável para um tipo genérico que representa uma Agenda de Tarefas
 *
 * @param numElem A quantidade de tarefas que serão armazenadas no agendador
 *
 * @return Um ponteiro para a agenda de tarefas
 */
tAgendaTarefas *CriaAgendaDeTarefas(int numElem)
{
    tAgendaTarefas *a = (tAgendaTarefas *)calloc(1, sizeof(tAgendaTarefas));
    a->numelem = numElem;
    a->item = (item **)calloc(numElem, sizeof(item *));
    a->qtdatutal = 0;

    return a;
}

/**
 * @brief Destroi a agenda de tarefas (libera a memória)
 *
 * @param tar - A agenda que terá seu conteúdo liberado/destruído
 */
void DestroiAgendaDeTarefas(tAgendaTarefas *tar)
{
    for (int i = 0; i < tar->numelem; i++)
    {
        free(tar->item[i]);
    }
    free(tar->item);
    free(tar);
}

/**
 * @brief Cadastra uma tarefa em um agendador de tarefas
 *
 * @param tar - Pointeiro para a agenda de tarefas
 * @param prioridade - Prioridade de execução da nova tarefa
 * @param tarefa - Ponteiro para nova tarefa a ser executada
 * @param executa - Ponteiro para função (callback) que será chamada quando for a hora de executar a tarefa
 * @param destroi - Ponteiro para função (callback) que será chamada quando for a hora de destruir a tarefa (liberar a memória)
 *
 */
void CadastraTarefaNaAgenda(tAgendaTarefas *tar, int prioridade, void *tarefa, void (*executa)(void *), void (*destroi)(void *))
{
    item *it = (item *)calloc(1, sizeof(item));
    tar->item[tar->qtdatutal] = it;
    tar->item[tar->qtdatutal]->executa = executa;
    tar->item[tar->qtdatutal]->prioridade = prioridade;
    tar->item[tar->qtdatutal]->destroi = destroi;
    tar->item[tar->qtdatutal]->tarefa = tarefa;
    tar->qtdatutal++;
}

/**
 * @brief Executa as tarefas que estão salvas na agenda de tarefas passada como parâmetro.
 *
 * @param tar Agenda de tarefas
 *
 */
void ExecutarTarefasDaAgenda(tAgendaTarefas *tar)
{
    for (int i = 0; i < tar->numelem; i++)
    {
        for (int j = 0; j < tar->numelem - 1; j++)
        {
            if (tar->item[j]->prioridade < tar->item[j + 1]->prioridade)
            {
                item *sup = tar->item[j];
                tar->item[j] = tar->item[j + 1];
                tar->item[j + 1] = sup;
            }
        }
    }

    for (int i = 0; i < tar->numelem; i++)
    {
        tar->item[i]->executa(tar->item[i]->tarefa);
        tar->item[i]->destroi(tar->item[i]->tarefa);
    }
}