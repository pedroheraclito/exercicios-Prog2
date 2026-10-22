#include <stdbool.h>
#include "carta.h"
#include <stdio.h>
#include <stdlib.h>
#include "duelo.h"
/**
 * @brief Estrutura de dados que representa um duelo entre duas cartas.
 */
struct duelo
{
    int id;
    int idc1;
    int idc2;
    char atributo;
    bool desempate;
    int diferenca;
};

#define MAGIA 'M' /**< Opção para duelo de magia. */
#define FORCA 'F' /**< Opção para duelo de força. */
#define FOGO 'G'  /**< Opção para duelo de fogo. */

/**
 * @brief Lê um duelo do usuário.
 * @return Retorna um ponteiro para o duelo lido.
 */
tDuelo LeDuelo()
{
    struct duelo *duelo = calloc(1, sizeof(struct duelo));
    scanf("%d", &duelo->id);
    scanf("%d %d %c", &duelo->idc1, &duelo->idc2, &duelo->atributo);
    duelo->desempate = 0;
    duelo->diferenca = false;
    return duelo;
}

/**
 * @brief Libera a memória alocada para um duelo.
 * @param d Ponteiro para o duelo a ser liberado.
 */
void LiberaDuelo(tDuelo d)
{
    free(d);
}

/**
 * @brief Imprime as informações de um duelo.
 * @param d Ponteiro para o duelo a ser impresso.
 */
void ImprimeDuelo(tDuelo d)
{
}

/**
 * @brief Realiza um duelo entre duas cartas.
 * @param d Ponteiro para o duelo.
 * @param c1 Ponteiro para a primeira carta.
 * @param c2 Ponteiro para a segunda carta.
 */
void RealizaDuelo(tDuelo d, tCarta c1, tCarta c2)
{
    int vencedor;
    if (d->atributo == MAGIA)
    {
        vencedor = ComparaMagiaCarta(c1, c2);
        d->diferenca = abs(GetMagiaCarta(c1) - GetMagiaCarta(c2));
    }
    else if (d->atributo == FORCA)
    {
        vencedor = ComparaAtaqueCarta(c1, c2);
        d->diferenca = abs(GetAtaqueCarta(c1) - GetAtaqueCarta(c2));
    }
    else if (d->atributo == FOGO)
    {
        vencedor = ComparaFogoCarta(c1, c2);
        d->diferenca = abs(GetFogoCarta(c1) - GetFogoCarta(c2));
    }
    if (vencedor == -1)
    {
        
        if (ComparaIdCarta(c1, c2) == 1)
        {
            AdicionaVitoriaCarta(c1);
            d->desempate=true;
        }
        else if (ComparaIdCarta(c1, c2) == -1)
        {
            AdicionaVitoriaCarta(c2);
            d->desempate=true;
        }
    }
    else
    {
        if (GetIdCarta(c1)==vencedor)
        {
           AdicionaVitoriaCarta(c1);
        }else{
            AdicionaVitoriaCarta(c2);
        }
        
        
    }
}

/**
 * @brief Retorna o ID da primeira carta do duelo.
 * @param d Ponteiro para o duelo.
 * @return Retorna o ID da primeira carta do duelo.
 */
int GetC1Duelo(tDuelo d)
{
    return d->idc1;
}

/**
 * @brief Retorna o ID da segunda carta do duelo.
 * @param d Ponteiro para o duelo.
 * @return Retorna o ID da segunda carta do duelo.
 */
int GetC2Duelo(tDuelo d)
{
    return d->idc2;
}

/**
 * @brief Retorna se houve desempate no duelo.
 * @param d Ponteiro para o duelo.
 * @return Retorna true se houve desempate e false caso contrário.
 */
bool GetDesempateDuelo(tDuelo d)
{
   return d->desempate;
}

/**
 * @brief Retorna a diferença de pontos entre as cartas no duelo.
 * @param d Ponteiro para o duelo.
 * @return Retorna a diferença de pontos entre as cartas no duelo.
 */
int GetDiferencaDuelo(tDuelo d)
{
    return d->diferenca;
}

/**
 * @brief Retorna o ID do duelo.
 * @param d Ponteiro para o duelo.
 * @return Retorna o ID do duelo.
 */
int GetIdDuelo(tDuelo d)
{
    return d->id;
}