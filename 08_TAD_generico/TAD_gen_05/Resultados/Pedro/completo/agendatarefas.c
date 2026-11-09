#include <stdio.h>
#include <stdlib.h>
#include "tarefaimprime.h"
#include <string.h>
#include "tarefamultiplica.h"
#include "tarefasoma.h"

#include "agendatarefas.h"

typedef struct
{
    int prioridade;
    void *tarefa;
    void (*executa)(void *);
    void (*destroi)(void *);
} tItem;

struct agendatarefas
{
    int numelem;
    tItem **item;
    int qtdatual;
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
    a->item = (tItem **)calloc(numElem, sizeof(tItem *));
    a->qtdatual = 0;
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
        tar->item[i]->destroi(tar->item[i]->tarefa);
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
    tItem *it = (tItem *)calloc(1, sizeof(tItem));
    tar->item[tar->qtdatual] = it;
    tar->item[tar->qtdatual]->prioridade = prioridade;
    tar->item[tar->qtdatual]->tarefa = tarefa;
    tar->item[tar->qtdatual]->executa = executa;
    tar->item[tar->qtdatual]->destroi = destroi;

    tar->qtdatual++;
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
        tItem *chave = tar->item[i];
        int j = i - 1;
        while (j >= 0 && tar->item[j]->prioridade < chave->prioridade)
        {
            tar->item[j + 1] = tar->item[j];
            j--;
        }
        tar->item[j + 1] = chave;
    }

    for (int i = 0; i < tar->numelem; i++)
    {
        tar->item[i]->executa(tar->item[i]->tarefa);
    }
}