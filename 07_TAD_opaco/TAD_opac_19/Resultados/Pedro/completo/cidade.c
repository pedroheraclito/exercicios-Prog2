#include <stdio.h>
#include <stdlib.h>
#include "cidade.h"
#include "defesa.h"
#include "missil.h"
struct cidade
{
    float x;
    float y;
    char nome;
    tDefesa defesas[QTD_DEF];
    tMissil missil[QTD_DEF];
    int qtddefesas;
    int qtdmisseis;
    float danototal, danorecebido;
};
/**
 * @brief Cria uma nova cidade.
 *
 * @return tCidade Ponteiro para a cidade criada.
 */
tCidade CriaCidade()
{
    struct cidade *cidade = calloc(1, sizeof(struct cidade));
    if (cidade == NULL)
    {
        printf("erro na cidade");
        exit(1);
    }
    cidade->x = 0;
    cidade->y = 0;
    cidade->danorecebido = 0;
    cidade->danototal = 0;
    cidade->qtddefesas = 0;
    cidade->qtdmisseis = 0;

    return cidade;
}

/**
 * @brief Lê a entrada do usuário e preenche a cidade com as informações lidas.
 *
 * @param cidade Ponteiro para a cidade que será preenchida.
 * @return tCidade Ponteiro para a cidade preenchida.
 */
tCidade LeEntrada(tCidade cidade)
{
    scanf("%c %f %f", &cidade->nome, &cidade->x, &cidade->y);
    char cod;
    scanf("%c ", &cod);
    while (1)
    {
        if (cod == 'D')
        {
            cidade->defesas[cidade->qtddefesas] = LeDefesa();
            cidade->qtddefesas++;
        }
        else if (cod == 'M')
        {
            cidade->missil[cidade->qtdmisseis] = LeMissil();
            cidade->qtdmisseis++;
        }
        else if (cod == 'F')
        {
            break;
        }

        scanf("%c ", &cod);
    }

    return cidade;
}

/**
 * @brief Imprime as informações da cidade.
 *
 * @param cidade Ponteiro para a cidade que será impressa.
 */
void ImprimeCidade(tCidade cidade)
{
    for (int i = 0; i < cidade->qtddefesas; i++)
    {
        ImprimeDefesa(cidade->defesas[i]);
    }
    for (int i = 0; i < cidade->qtdmisseis; i++)
    {
        ImprimeDefesa(cidade->missil[i]);
    }
    printf("Efetividade:");
}

/**
 * @brief Libera a memória alocada para a cidade.
 *
 * @param cidade Ponteiro para a cidade que terá a memória liberada.
 */
void LiberaCidade(tCidade cidade)
{
    for (int i = 0; i < cidade->qtdmisseis; i++)
    {
        LiberaMissil(cidade->missil[i]);
    }

    for (int i = 0; i < cidade->qtddefesas; i++)
    {
        LiberaMissil(cidade->defesas[i]);
    }
    free(cidade);
}

/**
 * @brief Processa os ataques na cidade.
 *
 * @param cidade Ponteiro para a cidade que será atacada.
 */
void ProcessaAtaques(tCidade cidade)
{
    for (int i = 0; i < cidade->qtdmisseis; i++)
    {
        cidade->danototal += GetMissilPoder(cidade->missil[i]);
        for (int j = 0; j < cidade->qtddefesas; j++)
        {
            if (VerificaSeDentroArea(cidade->defesas[j], GetMissilX(cidade->missil[i]), GetMissilY(cidade->missil[i])))
            {
                if (PodeDefender(cidade->defesas[j]))
                {
                    if (GetDefesaPoder(cidade->defesas[j]) >= GetMissilPoder(cidade->missil[i]))
                    {
                        cidade->danorecebido += GetMissilPoder(cidade->missil[i]);
                        ReduzPoder(cidade->missil[i], GetMissilPoder(cidade->missil[i]));
                    }
                    else
                    {
                        cidade->danorecebido += GetDefesaPoder(cidade->defesas[j]);
                        ReduzPoder(cidade->missil[i], GetDefesaPoder(cidade->defesas[j]));
                    }
                    UsaDefesa(cidade->defesas[j]);
                }
            }
        }
    }
}

/**
 * @brief Imprime os dados finais da cidade.
 *
 * @param cidade Ponteiro para a cidade que terá os dados impressos.
 */
void ImprimeDados(tCidade cidade){
    for (int i = 0; i < cidade->qtddefesas; i++)
    {
        ImprimeDefesa(cidade->defesas[i]);
    }
    for (int i = 0; i < cidade->qtdmisseis; i++)
    {
        ImprimeMissil(cidade->missil[i]);
    }
    float eft=(cidade->danorecebido/cidade->danototal)*100;
    printf("Efetividade: %.2f%%",eft);
    
    
}