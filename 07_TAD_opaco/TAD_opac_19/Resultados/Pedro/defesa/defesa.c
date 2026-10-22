#include <stdio.h>
#include <stdlib.h>
#include "defesa.h"
#include <math.h>

/**
 * @brief Estrutura que representa uma defesa.
 *
 * A estrutura tDefesa contém o tipo da defesa, as coordenadas do centro, o tamanho e o poder de defesa.
 *
 */
struct defesa
{
    char nome[256];
    float x;
    float y;
    char tipo;
    float tamanhoproj;
    float poderneutro;
    int qtdmisseis;
};

/**
 * @brief Lê a entrada do usuário e cria uma nova defesa.
 *
 * @return tDefesa Ponteiro para a defesa criada.
 */
tDefesa LeDefesa()
{
    struct defesa *defesa = calloc(1, sizeof(struct defesa));
    if (defesa == NULL)
    {
        printf("ERRO na defesa");
        exit(1);
    }
    scanf(" %s %f %f %c %f %f %d", defesa->nome, &defesa->x, &defesa->y, &defesa->tipo, &defesa->tamanhoproj,
          &defesa->poderneutro, &defesa->qtdmisseis);

    return defesa;
}

/**
 * @brief Imprime as informações da defesa.
 *
 * @param defesa Ponteiro para a defesa que será impressa.
 */
void ImprimeDefesa(tDefesa defesa)
{
    printf("D-%s: %d\n", defesa->nome, defesa->qtdmisseis);
}

/**
 * @brief Libera a memória alocada para a defesa.
 *
 * @param defesa Ponteiro para a defesa que terá a memória liberada.
 */
void LiberaDefesa(tDefesa defesa)
{
    free(defesa);
}

/**
 * @brief Verifica se um ponto está dentro da área de defesa.
 *
 * @param defesa Ponteiro para a defesa que será verificada.
 * @param x Coordenada x do ponto.
 * @param y Coordenada y do ponto.
 * @return int 1 se o ponto está dentro da área de defesa, 0 caso contrário.
 */
int VerificaSeDentroArea(tDefesa defesa, float x, float y)
{
    if (defesa->tipo == 'C')
    {
        if (sqrt((defesa->x - x) * (defesa->x - x) + (defesa->y - y) * (defesa->y - y)) < defesa->tamanhoproj)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if (defesa->tipo == 'Q')
    {
        float meiolado = defesa->tamanhoproj / sqrt(2);
        if (defesa->x + meiolado < x || defesa->x - meiolado > x || defesa->y + meiolado < y || defesa->y - meiolado > y)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
}

/**
 * @brief Usa a defesa, diminuindo seu poder de defesa.
 *
 * @param defesa Ponteiro para a defesa que será usada.
 */
void UsaDefesa(tDefesa defesa){
    defesa->qtdmisseis--;
}

/**
 * @brief Obtém o poder de defesa da defesa.
 *
 * @param defesa Ponteiro para a defesa que terá o poder de defesa obtido.
 * @return float Poder de defesa da defesa.
 */
float GetDefesaPoder(tDefesa defesa){
    return defesa->poderneutro;
}

/**
 * @brief Verifica se a defesa pode defender.
 *
 * @param defesa Ponteiro para a defesa que será verificada.
 * @return int 1 se a defesa pode defender, 0 caso contrário.
 */
int PodeDefender(tDefesa defesa){
    if (defesa->qtdmisseis>0)
    {
       return 1;
    }
    return 0;
}