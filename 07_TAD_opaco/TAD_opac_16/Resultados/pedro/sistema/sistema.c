#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"
#include "sistema.h"

struct Sistema
{
    float total;
    float precoUtil;
    float precoFds;
};

/**
 * @brief Cria um sistema de gerenciamento de tíquetes de um estacionamento
 *
 * @return Uma variável do tipo tSistema;
 */
tSistema *CriaSistema()
{
    tSistema *sys = calloc(1, sizeof(tSistema));

    sys->total = 0;
    sys->precoUtil = 1.0f; /* R$ 1/h em dia útil */
    sys->precoFds = 2.0f;  /* R$ 2/h sáb e dom */

    return sys;
}

/**
 * @brief Libera toda a memória necessária para armazenar um sistema de gerenciamento do estacionamento.
 *
 * @param sys - Variável que terá sua memória liberada
 */
void DestroiSistema(tSistema *sys)
{
    free(sys);
}

/**
 * @brief Lê os dados do sistema e os tíquetes a serem processados
 *
 * @param sys - A variável que armazenará os dados do sistema e os tíquetes

 */
void LeSistema(tSistema *sys)
{
    char linha[200];

    while (fgets(linha, sizeof(linha), stdin))
    {
        linha[strcspn(linha, "\r\n")] = '\0';
        if (linha[0] == '\0') /* linha vazia = fim */
            break;

        tData *entrada = CriaData();
        tData *saida = CriaData();

        ProcessaDiaDaSemana(entrada, strtok(linha, ";"));
        ProcessaDiaMesAno(entrada, strtok(NULL, ";"));
        ProcessaHorario(entrada, strtok(NULL, ";"));
        ProcessaDiaMesAno(saida, strtok(NULL, ";"));
        ProcessaHorario(saida, strtok(NULL, ";"));

        float preco = CalculaPrecoTiquete(sys, entrada, saida);
        printf("O tiquete processado tem valor: %.2f reais\n", preco);
        sys->total += preco;

        DestroiData(entrada);
        DestroiData(saida);
    }
}

/**
 * @brief Processa um tíquete e faz as contas para saber o valor que o motorista deve pagar.
 *
 * @param sys A variável que representa o sistema e seus dados.
 * @param dataEntrada - Uma variável que representa os dados da data de entrada do tíquete processado
 * @param dataSaida - Uma variável que representa os dados da data de saída do tíquete processado.
 * @return Um número real que representa o preço de um ticket específico que tem dataEntrada e foi faturado na dataSaida
 */
float CalculaPrecoTiquete(tSistema *sys, tData *dataEntrada, tData *dataSaida)
{
    float horasUtil = 0, horasFds = 0;

    tData *ant = CriaData();
    tData *prox = CriaData();

    if (CalculaDiferencaDias(dataEntrada, dataSaida) == 0)
    {
        float h = CalculaHorasEntreDatas(dataEntrada, dataSaida);
        if (h > 0.25f) /* tolerância de 15 min */
        {
            if (DataEhSabadoOuDomingo(dataEntrada))
                horasFds += h;
            else
                horasUtil += h;
        }
    }
    else
    {
        /* 1º dia: da hora de entrada até meia-noite */
        CopiaDiaMesAno(dataEntrada, ant);
        CopiaDiaMesAno(dataEntrada, prox);
        DataDiaSeguinte(prox);
        if (DataEhSabadoOuDomingo(dataEntrada))
            horasFds += CalculaHorasEntreDatas(dataEntrada, prox);
        else
            horasUtil += CalculaHorasEntreDatas(dataEntrada, prox);
        CopiaDiaMesAno(prox, ant);

        /* dias seguintes: 24h cada */
        while (ComparaDiaMesAno(prox, dataSaida) != 1)
        {
            if (DataEhSabadoOuDomingo(prox))
                horasFds += 24;
            else
                horasUtil += 24;
            CopiaDiaMesAno(prox, ant);
            DataDiaSeguinte(prox);
        }

        /* último dia: de meia-noite até a hora de saída */
        if (DataEhSabadoOuDomingo(ant))
            horasFds += CalculaHorasEntreDatas(ant, dataSaida);
        else
            horasUtil += CalculaHorasEntreDatas(ant, dataSaida);
    }

    int util = (int)horasUtil; /* arredonda pra cima */
    if (horasUtil > util)
        util++;
    int fds = (int)horasFds;
    if (horasFds > fds)
        fds++;

    float preco = util * sys->precoUtil + fds * sys->precoFds;

    DestroiData(ant);
    DestroiData(prox);
    return preco;
}

/**
 * @brief Imprime o faturamento de um sistema.
 *
 * @param sys O sistema que terá seu faturamento impresso em tela
 */
void ImprimeFaturamentoSistema(tSistema *sys)
{
    printf("O sistema faturou: %.2f reais\n", sys->total);
}