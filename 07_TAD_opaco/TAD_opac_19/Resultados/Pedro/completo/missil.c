#include <stdio.h>
#include <stdlib.h>
#include "missil.h"

struct missil{
    float x; 
    float y;
    float power;
    char nome[MAX_TAM];
};
/**
 * @brief Lê a entrada do usuário e cria um novo míssil.
 * 
 * @return tMissil Ponteiro para o míssil criado.
 */
tMissil LeMissil(){
    struct missil *missil=calloc(1,sizeof(struct missil));
    if (missil==NULL)
    {
        printf("ERRO");
        exit(1);
    }
    scanf(" %s %f %f %f",missil->nome,&missil->x,&missil->y,&missil->power);

    return missil;
}

/**
 * @brief Imprime as informações do míssil.
 * 
 * @param missil Ponteiro para o míssil que será impresso.
 */
void ImprimeMissil(tMissil missil){
    printf("M-%s: %.2f\n",missil->nome,missil->power);
}

/**
 * @brief Libera a memória alocada para o míssil.
 * 
 * @param missil Ponteiro para o míssil que terá a memória liberada.
 */
void LiberaMissil(tMissil missil){
    free(missil);
}

/**
 * @brief Obtém a coordenada y do míssil.
 * 
 * @param missil Ponteiro para o míssil que terá a coordenada y obtida.
 * @return float Coordenada y do míssil.
 */
float GetMissilY(tMissil missil){
    return missil->y;
}

/**
 * @brief Obtém a coordenada x do míssil.
 * 
 * @param missil Ponteiro para o míssil que terá a coordenada x obtida.
 * @return float Coordenada x do míssil.
 */
float GetMissilX(tMissil missil){
    return missil->x;
}

/**
 * @brief Obtém o poder de ataque do míssil.
 * 
 * @param missil Ponteiro para o míssil que terá o poder de ataque obtido.
 * @return float Poder de ataque do míssil.
 */
float GetMissilPoder(tMissil missil){
    return missil->power;
}

/**
 * @brief Reduz o poder de ataque do míssil.
 * 
 * @param missil Ponteiro para o míssil que terá o poder de ataque reduzido.
 * @param valor Valor a ser subtraído do poder de ataque do míssil.
 */
void ReduzPoder(tMissil missil, float valor){
    missil->power=missil->power-valor;
    if (missil->power<0)
    {
        missil->power=0;
    }
    
}