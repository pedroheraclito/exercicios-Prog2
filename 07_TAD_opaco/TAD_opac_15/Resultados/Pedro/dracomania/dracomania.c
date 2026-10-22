#include <stdbool.h>
#include "carta.h"
#include <stdio.h>
#include <stdlib.h>
#include "duelo.h"
#include "dracomania.h"

struct dracomania
{
    tCarta carta[10];
    tDuelo duelo[10];
    int qtdcartas;
    int qtddeduelos;
    int qtddescartadas;
    int qtddesempates;
    int maiordiferenca;
};

/**
 * @brief Cria uma nova instância do jogo Dracomania.
 * @return Retorna um ponteiro para a estrutura criada.
 */
tDracomania CriaDracomania()
{
    struct dracomania *draco = calloc(1, sizeof(struct dracomania));
    draco->qtdcartas = 0;
    draco->qtddeduelos = 0;
    draco->qtddescartadas = 0;
    draco->qtddesempates = 0;
    draco->maiordiferenca = -1;

    return draco;
}

/**
 * @brief Roda o jogo Dracomania.
 * @param d Ponteiro para a instância do jogo.
 * @return Retorna um ponteiro para a instância do jogo atualizada.
 */
tDracomania RodaDracomania(tDracomania d)
{
    char cod;
    int id1, id2;
    int maior = -1;
    scanf(" %c", &cod);
    while (1)
    {
        if (cod == 'C')
        {
            d->carta[d->qtdcartas] = LeCarta();

            if (EhCartaValida(d->carta[d->qtdcartas]))
            {

                int pos = -1;
                for (int i = 0; i < d->qtdcartas; i++)
                {
                    if (EhMesmoIdCarta(d->carta[i], d->carta[d->qtdcartas]))
                    {
                        pos = i;
                    }
                }

                if (pos >= 0) // ID já existe: substitui
                {
                    LiberaCarta(d->carta[pos]);
                    d->carta[pos] = d->carta[d->qtdcartas];
                }
                else // ID novo: cadastra
                {
                    d->qtdcartas++;
                }
            }
            else
            {
                LiberaCarta(d->carta[d->qtdcartas]);
                d->qtddescartadas++;
            }
        }
        else if (cod == 'L')
        {
            d->duelo[d->qtddeduelos] = LeDuelo();
            for (int i = 0; i < d->qtdcartas; i++)
            {
                if (GetC1Duelo(d->duelo[d->qtddeduelos]) == GetIdCarta(d->carta[i]))
                {
                    id1 = i;
                }
                if (GetC2Duelo(d->duelo[d->qtddeduelos]) == GetIdCarta(d->carta[i]))
                {
                    id2 = i;
                }
            }

            RealizaDuelo(d->duelo[d->qtddeduelos], d->carta[id1], d->carta[id2]);
            if (GetDiferencaDuelo(d->duelo[d->qtddeduelos]) > maior)
            {
                maior = GetDiferencaDuelo(d->duelo[d->qtddeduelos]);
                d->maiordiferenca = d->qtddeduelos + 1;
            }

            if (GetDesempateDuelo(d->duelo[d->qtddeduelos]))
            {
                d->qtddesempates++;
            }

            d->qtddeduelos++;
        }
        else if (cod == 'F')
        {
            break;
        }

        scanf(" %c", &cod);
    }
    return d;
}

/**
 * @brief Imprime o relatório final do jogo Dracomania.
 * @param d Ponteiro para a instância do jogo.
 */
void ImprimeRelatorioDracomania(tDracomania d)
{
    int maior = -1;
    int posvit;
    printf("Quantidade de Cartas: %d\n", d->qtdcartas);
    printf("Quantidade de descartadas: %d\n", d->qtddescartadas);
    printf("Quantidade de lutas: %d\n", d->qtddeduelos);
    if (d->qtddeduelos > 0)
    {

        printf("Lutas que foram desempatadas: %d\n", d->qtddesempates);
        for (int i = 0; i < d->qtdcartas; i++)
        {
            if (GetNumVitCarta(d->carta[i]) > maior)
            {
                maior = GetNumVitCarta(d->carta[i]);
                posvit = i;
            }
        }

        printf("Carta mais vitoriosa: %s\n", GetNomeCarta(d->carta[posvit]));
        printf("Luta com Maior Diferença: %d\n", d->maiordiferenca);
    }
}

/**
 * @brief Libera a memória alocada para a instância do jogo Dracomania.
 * @param d Ponteiro para a instância do jogo.
 */
void LiberaDracomania(tDracomania d)
{
    for (int i = 0; i < d->qtdcartas; i++)
    {
        LiberaCarta(d->carta[i]);
    }
    for (int i = 0; i < d->qtddeduelos; i++)
    {
        LiberaDuelo(d->duelo[i]);
    }
    free(d);
}