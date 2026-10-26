#include <stdio.h>
#include <stdlib.h>
#include "data.h"

/*
  Esse .h foi adaptado do TAD_pont_07
*/

struct Data
{
    int dia;
    int mes;
    int ano;
    int diaS;
    int horas;
    int minutos;
};

/**
 * @brief Aloca dinamicamente uma estrutura do tipo tData, e a retorna.
 * Os campos dessa estrutura devem ser preenchidos inicialmente com -1.
 *
 * @return tData - Data "Vazia"
 */
tData *CriaData()
{
    tData *d = calloc(1, sizeof(tData));
    d->dia = -1;
    d->mes = -1;
    d->ano = -1;
    d->diaS = 0;
    d->horas = 0;
    d->minutos = 0;

    return d;
}

/**
 * @brief Libera toda a memoria alocada dinamicamente para armazenar uma data
 *
 * @param tData - Data que será liberada
 */
void DestroiData(tData *data)
{
    free(data);
}

/**
 * @brief Processa o dia, mês e ano da string str e armazena em uma estrutura tData alocada dinamicamente.
 *
 * @param data - Ponteiro para a estrutura onde os dados serão armazenados. Lembre-se: Não pode ter valor NULL.
 * @param str - String que será processada
 */
void ProcessaDiaMesAno(tData *data, char *str)
{
    sscanf(str, "%d/%d/%d", &data->dia, &data->mes, &data->ano);
}

/**
 * @brief Processa o dia da semana da string str e armazena em uma estrutura tData alocada dinamicamente.
 *
 * @param data - Ponteiro para a estrutura onde os dados serão armazenados. Lembre-se: Não pode ter valor NULL.
 * @param str - String que será processada
 */
void ProcessaDiaDaSemana(tData *data, char *str)
{
    sscanf(str, "%d;", &data->diaS);
}

/**
 * @brief Processa hora, minuto e segundo da string str e armazena em uma estrutura tData alocada dinamicamente.
 *
 * @param data - Ponteiro para a estrutura onde os dados serão armazenados. Lembre-se: Não pode ter valor NULL.
 * @param str - String que será processada
 */
void ProcessaHorario(tData *data, char *str)
{
    sscanf(str, " %d:%d;", &data->horas, &data->minutos);
}

/**
 * @brief Verifica se uma data é válida.
 *
 * @param data Data a ser verificada.
 * @return int 1 se a data é válida, 0 caso contrário.
 */
int VerificaDataValida(tData *data)
{
    if (data->mes == 1 || data->mes == 3 || data->mes == 5 || data->mes == 7 || data->mes == 8 || data->mes == 10 || data->mes == 12)
    {
        if (data->dia <= 31 && data->dia > 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if (data->mes == 4 || data->mes == 6 || data->mes == 9 || data->mes == 11)
    {
        if (data->dia <= 30 && data->dia > 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if (data->mes == 2)
    {
        if (VerificaBissexto(data))
        {
            if (data->dia <= 29 && data->dia > 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            if (data->dia <= 28 && data->dia > 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
    return 0;
}

/**
 * @brief Verifica se um ano é bissexto.
 *
 * @param data Data cujo ano será verificado.
 * @return int 1 se o ano é bissexto, 0 caso contrário.
 */
int VerificaBissexto(tData *data)
{
    if ((data->ano % 4 == 0 && data->ano % 100 != 0) || data->ano % 400 == 0)
    {
        return 1;
    }
    return 0;
}

/**
 * @brief Retorna o número de dias de um determinado mês.
 *
 * @param data Data cujo mês terá o número de dias retornado.
 * @return int Número de dias do mês da data.
 */
int NumeroDiasMes(tData *data)
{
    if (data->mes == 1 || data->mes == 3 || data->mes == 5 || data->mes == 7 || data->mes == 8 || data->mes == 10 || data->mes == 12)
    {
        return 31;
    }
    else if (data->mes == 4 || data->mes == 6 || data->mes == 9 || data->mes == 11)
    {
        return 30;
    }
    else if (data->mes == 2)
    {
        if (VerificaBissexto(data))
        {
            return 29;
        }
        else
        {
            return 28;
        }
    }
    return 30;
}

/**
 * @brief Compara duas datas.
 *
 * @param data1 Primeira data a ser comparada.
 * @param data2 Segunda data a ser comparada.
 * @return int 1 se data1 é maior que data2, -1 se data1 é menor que data2, 0 se as datas são iguais.
 * A data ser maior significa que ela é mais recente.
 */
int ComparaDiaMesAno(tData *data1, tData *data2)
{
    if (data1->ano > data2->ano)
    {
        return 1;
    }
    else if (data1->ano < data2->ano)
    {
        return -1;
    }
    else if (data1->ano == data2->ano)
    {
        if (data1->mes > data2->mes)
        {
            return 1;
        }
        else if (data1->mes < data2->mes)
        {
            return -1;
        }
        else if (data1->mes == data2->mes)
        {
            if (data1->dia > data2->dia)
            {
                return 1;
            }
            else if (data1->dia < data2->dia)
            {
                return -1;
            }
            else if (data1->mes == data2->mes)
            {
                return 0;
            }
        }
    }
    return 0;
}

/**
 * @brief Calcula o número de dias até o início do mês de uma determinada data.
 *
 * @param data Data cujo número de dias até o início do mês será calculado.
 * @return int Número de dias até o início do mês da data.
 */
int CalculaDiasAteMes(tData *data)
{
    int totaldias = 0;
    tData *sup = CriaData();
    sup->ano = data->ano;   
    for (int i = 0; i < data->mes - 1; i++)
    {
        sup->mes = i + 1;
        totaldias += NumeroDiasMes(sup);
    }
    DestroiData(sup);
    return totaldias;
}

/**
 * @brief Calcula a diferença em dias entre duas datas.
 *
 * @param data1 Primeira data a ser comparada.
 * @param data2 Segunda data a ser comparada.
 * @return int Número de dias entre as duas datas.
 */
int CalculaDiferencaDias(tData *data1, tData *data2)
{
    tData *aux = CriaData();
    int diferenca = 0;
    if (ComparaDiaMesAno(data1, data2) == 1)
    {
        diferenca = CalculaDiasAteMes(data1) + data1->dia - CalculaDiasAteMes(data2) - data2->dia;
        for (int i = 0; i < data1->ano - data2->ano; i++)
        {
            int ano = data2->ano + i;
            aux->ano = ano;

            if (VerificaBissexto(aux))
            {
                diferenca += 366;
            }
            else
            {
                diferenca += 365;
            }
        }
    }
    else if (ComparaDiaMesAno(data1, data2) == -1)
    {
        diferenca = CalculaDiasAteMes(data2) + data2->dia - CalculaDiasAteMes(data1) - data1->dia;
        for (int i = 0; i < data2->ano - data1->ano; i++)
        {
            int ano = data1->ano + i;
            aux->ano = ano;

            if (VerificaBissexto(aux))
            {
                diferenca += 366;
            }
            else
            {
                diferenca += 365;
            }
        }
    }
    DestroiData(aux);
    return diferenca;
}

/**
 * @brief Calcula a diferença em horas entre duas datas.
 *
 * @param data1 Primeira data a ser comparada.
 * @param data2 Segunda data a ser comparada.
 * @return float número de horas entre as duas datas (2,5 horas = 2h30)
 */
float CalculaHorasEntreDatas(tData *data1, tData *data2)
{
    int diasMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    long min1 = 0, min2 = 0;
    long dias1 = 0, dias2 = 0;

    /* ---- data1 ---- */
    for (int a = 1; a < data1->ano; a++)
        dias1 += ((a % 4 == 0 && a % 100 != 0) || a % 400 == 0) ? 366 : 365;
    for (int m = 1; m < data1->mes; m++)
    {
        dias1 += diasMes[m - 1];
        if (m == 2 && ((data1->ano % 4 == 0 && data1->ano % 100 != 0) || data1->ano % 400 == 0))
            dias1 += 1;
    }
    dias1 += data1->dia - 1;
    min1 = dias1 * 24 * 60 + data1->horas * 60 + data1->minutos;

    /* ---- data2 ---- */
    for (int a = 1; a < data2->ano; a++)
        dias2 += ((a % 4 == 0 && a % 100 != 0) || a % 400 == 0) ? 366 : 365;
    for (int m = 1; m < data2->mes; m++)
    {
        dias2 += diasMes[m - 1];
        if (m == 2 && ((data2->ano % 4 == 0 && data2->ano % 100 != 0) || data2->ano % 400 == 0))
            dias2 += 1;
    }
    dias2 += data2->dia - 1;
    min2 = dias2 * 24 * 60 + data2->horas * 60 + data2->minutos;

    if (ComparaDiaMesAno(data1, data2) == 1)
        return 0;
    return (float)(min2 - min1) / 60.0f;
}

/**
 * @brief Verifica se uma data corresponde a um sábado ou domingo
 *
 * @param data1 Primeira data a ser comparada.
 * @return int 1 se é sábado ou domingo, 0 caso contrário
 */
int DataEhSabadoOuDomingo(tData *data)
{
    if (data->diaS == 6 || data->diaS == 0)
    {
        return 1;
    }
    return 0;
}

/**
 * @brief Atualiza a data para a data do dia seguinte (esta data deve ser válida!)
 *
 * @param data Data a ser modificada.
 *
 */
void DataDiaSeguinte(tData *data)
{
    if (NumeroDiasMes(data) != data->dia)
    {
        data->dia++;
    }
    else if (data->mes != 12)
    {
        data->mes++;
        data->dia = 1;
    }
    else
    {
        data->ano++;
        data->mes = 1;
        data->dia = 1;
    }

    if (data->diaS != 6)
    {
        data->diaS++;
    }
    else
    {
        data->diaS = 0;
    }
}

/**
 * @brief Copia os dados de Dia/Mês/Ano de uma data src para uma data tgt.
 *
 * @param src Data que terá seus dados copiados
 * @param tgt Data que armazenará a cópia
 */
void CopiaDiaMesAno(tData *src, tData *tgt)
{
    tgt->dia = src->dia;
    tgt->mes = src->mes;
    tgt->ano = src->ano;
     tgt->diaS = src->diaS;
}