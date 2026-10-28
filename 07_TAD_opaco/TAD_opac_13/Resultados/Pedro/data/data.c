#include <stdio.h>
#include <stdlib.h>
#include "data.h"

struct Data
{
    int dia;
    int mes;
    int ano;
};

/*
Função que cria uma data a partir do dia, mês e ano fornecidos e retorna um ponteiro para a data criada
@param dia: Dia da data.
@param mes: Mês da data.
@param ano: Ano da data.
@return Data criada.
*/
Data *criaData(int dia, int mes, int ano)
{
    Data *d = calloc(1, sizeof(Data));

    d->dia = dia;
    d->mes = mes;
    d->ano = ano;

    return d;
}

/*
Função que lê uma data do formato DD/MM/AAAA a partir da entrada padrão e retorna um ponteiro para a data lida.
@return Data lida.
*/
Data *lerData()
{
    int dia, mes, ano;
    scanf("%d/%d/%d ", &dia, &mes, &ano);
    Data *d = criaData(dia, mes, ano);
    return d;
}

/*
Função que calcula a diferença em anos entre duas datas. A diferença é calculada como o número de anos completos entre a data inicial e a data atual.
Ex: Se a data inicial for 15/08/2000 e a data atual for 14/08/2023, a diferença será 22 anos.
@param inicial: Data inicial.
@param atual: Data atual.
@return Diferença em anos entre as duas datas.
*/
int diferencaAnoData(Data *inicial, Data *atual)
{
    int diferenca = atual->ano - inicial->ano;
    if (atual->mes < inicial->mes)
    {
        diferenca--;
    }
    else if (atual->mes == inicial->mes)
    {
        if (atual->dia < inicial->dia)
        {
            diferenca--;
        }
    }
    return diferenca;
}

/*
Função que imprime uma data no formato DD/MM/AAAA.
@param d: Data a ser impressa.
*/
void imprimeData(Data *d){
    printf("%02d/%02d/%04d",d->dia,d->mes,d->ano);
}

/*
Função que libera a memória alocada para uma data.
@param d: Ponteiro para a data a ser liberada.
*/
void liberaData(Data *d){
    free(d);
}