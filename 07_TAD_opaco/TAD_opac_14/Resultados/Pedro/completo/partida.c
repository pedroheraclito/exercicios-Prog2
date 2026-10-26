#include <stdio.h>
#include <stdlib.h>
#include "franquia.h"
#include <string.h>
#include "partida.h"
/**
 * @brief Constante que representa o time da casa.
 *
 */
#define TIME_CASA 1

/**
 * @brief Constante que representa o time visitante.
 *
 */
#define TIME_FORA 2

/**
 * @brief Estrutura que representa uma partida.
 *
 * A estrutura partida contém informações sobre os times que jogaram e o vencedor da partida.
 *
 */
struct partida
{
    char *time1;
    char *time2;
    int pt1;
    int pt2;
};

/**
 * @brief Lê uma partida do teclado.
 *
 * @return tPartida Retorna um ponteiro para a partida lida.
 */
tPartida LePartida()
{
    struct partida *p = calloc(1, sizeof(struct partida));
    p->time1=calloc(MAX_NOME,sizeof(char));
    p->time2=calloc(MAX_NOME,sizeof(char));
    scanf(" %s %*c %s %d %d",p->time1,p->time2,&p->pt1,&p->pt2);

    return p;
}

/**
 * @brief Libera a memória alocada para uma partida.
 *
 * @param p Ponteiro para a partida a ser liberada.
 */
void LiberaPartida(tPartida p){
    free(p->time1);
    free(p->time2);
    free(p);
}

/**
 * @brief Imprime as informações de uma partida.
 *
 * @param p Ponteiro para a partida a ser impressa.
 */
void ImprimePartida(tPartida p){

}

/**
 * @brief Retorna o nome do time da casa.
 *
 * @param p Ponteiro para a partida.
 * @return char* Retorna o nome do time da casa.
 */
char *GetTime1Partida(tPartida p){
    return p->time1;
}

/**
 * @brief Retorna o nome do time visitante.
 *
 * @param p Ponteiro para a partida.
 * @return char* Retorna o nome do time visitante.
 */
char *GetTime2Partida(tPartida p){
    return p->time2;
}

/**
 * @brief Retorna o vencedor da partida.
 *
 * @param p Ponteiro para a partida.
 * @return int Retorna a constante que representa o vencedor da partida (TIME_CASA ou TIME_FORA).
 */
int GetVencedorPartida(tPartida p){
    if (p->pt1>p->pt2)
    {
        return TIME_CASA;
    }else{
        return TIME_FORA;
    }
    
}