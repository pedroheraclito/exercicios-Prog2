#include <stdio.h>
#include <stdlib.h>
#include "conta.h"
#include "agencia.h"
#include "operacao.h"
#include <limits.h>
struct Agencia
{
    tConta **contas;
    tOperacao **operacao;
    int totalcontas;
    int totalop;
};

/**
 * @brief Cria uma variável (alocada dinamicamente) do tipo tAgencia. Ponteiros devem ser inicializados com NULL e variáveis numéricas com valor zero.
 *
 * @return A variável do tipo Agencia inicializada.
 */
tAgencia *CriaAgencia()
{
    tAgencia *a = calloc(1, sizeof(tAgencia));
    a->contas = calloc(70, sizeof(tConta *));
    for (int i = 0; i < 70; i++)
    {
        a->contas[i] = NULL;
    }
    a->operacao = calloc(100, sizeof(tOperacao *));
    for (int i = 0; i < 100; i++)
    {
        a->operacao[i] = NULL;
    }
    a->totalcontas = 0;
    a->totalop = 0;

    return a;
}

/**
 * @brief Libera toda a memória alocada para armazenar dados de uma agencia.
 *
 * @param A variável do tipo Agencia que será apagada.
 */
void DestroiAgencia(tAgencia *agencia)
{
    for (int i = 0; i < agencia->totalcontas; i++)
    {
        DestroiConta(agencia->contas[i]);
    }
    for (int i = 0; i < agencia->totalop; i++)
    {
        DestroiOperacao(agencia->operacao[i]);
    }
    free(agencia->contas);
    free(agencia->operacao);
    free(agencia);
}

/**
 * @brief Le as informações de uma agencia - contas e operações, no formato especificado no roteiro
 *
 * @param agencia - A variável do tipo agencia que salvará os dados lidos
 */
void LeOperacoes(tAgencia *agencia)
{
    int qtd, id, qtd2;
    float valor;
    scanf("%d", &qtd);
    agencia->totalcontas = qtd;
    for (int i = 0; i < qtd; i++)
    {
        scanf("%d", &id);
        while (id < 0)
        {
            printf("\nDigite um id valido para a conta a ser cadastrada!");
            scanf("%d", &id);
        }
        for (int j = 0; j < i; j++)
        {
            if (RetornaIdConta(agencia->contas[j]) == id)
            {
                printf("\nEste id ja esta cadastrado na agencia. Digite um id diferente!\n");
                scanf("%d", &id);
            }
        }

        agencia->contas[i] = CriaConta(id);
    }
    scanf("%d", &qtd2);
    for (int i = 0; i < qtd2; i++)
    {
        int cont=1;
        scanf("%d %f", &id, &valor);
        for (int i2 = 0; i2 < qtd; i2++)
        {
            if (RetornaIdConta(agencia->contas[i2]) == id)
            {
                agencia->operacao[agencia->totalop] = CriaOperacao(agencia->contas[i2], valor);
                AlteraSaldoConta(agencia->contas[i2], valor);
                agencia->totalop++;
                cont=0;
                break;
            }
        }
        if (cont)
        {
          printf("Conta Invalida! Repita a operacao, mas com uma conta valida!\n");
          i--;
        }
        
    }
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param agencia - A agencia na qual queremos buscar a conta com o id específico
 * @param id - o ID da conta que queremos buscar
 *conferido
 * @return A conta, caso exista, e NULL, caso contrário
 */
tConta *BuscaContaPorId(tAgencia *agencia, int id)
{
    for (int i = 0; i < agencia->totalcontas; i++)
    {
        if (RetornaIdConta(agencia->contas[i]) == id)
        {
            return agencia->contas[i];
        }
    }
    return NULL;
}

/**
 * @brief Função que imprime em tela as operações suspeitas de uma agência
 *
 * @param agencia A Agência na qual as operações suspeitas serão impressas em tela.
 */
void ImprimeOperacoesSuspeitas(tAgencia *agencia)
{
    printf("\nA lista de operações suspeitas:\n");
    for (int i = 0; i < agencia->totalop; i++)
    {
        if (ConsultaValorOperacao(agencia->operacao[i]) > 20000 || ConsultaValorOperacao(agencia->operacao[i]) < -20000)
        {
            ImprimeOperacao(agencia->operacao[i]);
        }
    }
}

/**
 * @brief Função que imprime em tela os dois correntistas com maior saldo
 *
 * @param agencia A Agência na qual os dois correntistas com maior saldo impressos em tela.
 */
void ImprimeDoisCorrentistasComMaiorSaldo(tAgencia *agencia)
{
    printf("\nOs dois correntistas com maior saldo são:\n");
    float maior = INT_MIN, maior2 = INT_MIN;
    tConta *c;
    tConta *c2;
    for (int i = 0; i < agencia->totalcontas; i++)
    {
        if (RetornaSaldoConta(agencia->contas[i]) > maior)
        {
            maior = RetornaSaldoConta(agencia->contas[i]);
            c = agencia->contas[i];
        }
    }
    printf("\nId: %d, Saldo: %.2f\n", RetornaIdConta(c), RetornaSaldoConta(c));

    for (int i = 0; i < agencia->totalcontas; i++)
    {
        if (RetornaSaldoConta(agencia->contas[i]) < maior && RetornaSaldoConta(agencia->contas[i]) > maior2)
        {
            maior2 = RetornaSaldoConta(agencia->contas[i]);
            c2 = agencia->contas[i];
        }
    }
    printf("Id: %d, Saldo: %.2f\n", RetornaIdConta(c2), RetornaSaldoConta(c2));
}

/**
 * @brief Função que imprime em tela o saldo total da agência
 *
 * @param agencia A Agência na qual o saldo total impresso em tela.
 */
void ImprimeSaldoTotal(tAgencia *agencia)
{
    float saldo = 0;
    for (int i = 0; i < agencia->totalcontas; i++)
    {
        saldo += RetornaSaldoConta(agencia->contas[i]);
    }

    printf("O saldo total da agencia eh: %.2f", saldo);
}