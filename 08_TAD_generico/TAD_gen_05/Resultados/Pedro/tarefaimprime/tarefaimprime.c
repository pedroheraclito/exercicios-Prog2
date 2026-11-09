#include <stdio.h>
#include <stdlib.h>
#include "tarefaimprime.h"
#include <string.h>

struct impr{
    char msg[100];
};

/**
 * @brief Cria uma tarefa do tipo impressão em tela
 * 
 * @param msg - A mensagem que deve ser impressa em tela
 *
 * @return Um ponteiro para a tarefa criada
 */
tImpr* CriaTarefaImprimir(char *msg){
    tImpr *impr=(tImpr*)calloc(1,sizeof(tImpr));
    strcpy(impr->msg,msg);


    return impr;
}

/**
 * @brief Função que executa uma tarefa de impressão em tela
 *
 * @param imp - Ponteiro para a tarefa a ser executada
 *
 */
void ExecutaTarefaImprimir(void *imp){
    tImpr *vet=(tImpr*)imp;
    printf("\n%s\n",vet->msg);
}

/**
 * @brief Função que destrói (libera a memória) uma tarefa de impressão em tela
 *
 * @param imp - Ponteiro para a tarefa a ser destruída
 *
 */
void DestroiTarefaImprimir(void *imp){
    tImpr *vet=(tImpr*)imp;
    free(vet);
}