#include <stdio.h>
#include <stdlib.h>
#include "usuario.h"
#include <string.h>
#include "conta.h"
#include "banco.h"

struct Banco
{
    int contasalocadas;
    int qtdContas;
    tConta **contas;
};
/**
 * @brief Cria um novo banco, com 5 contas alocadas e nenhuma conta aberta.
 * Se não for possível alocar memória, o programa é encerrado.
 *
 * @return Um ponteiro para o novo banco criado.
 */
tBanco *CriaBanco()
{
    tBanco *banco = calloc(1, sizeof(tBanco));

    banco->contasalocadas = 5;
    banco->qtdContas = 0;
    banco->contas = calloc(banco->contasalocadas, sizeof(tConta *));
}

/**
 * @brief Desaloca a memória de um banco e de todas as suas contas.
 *
 * @param banco Ponteiro para o banco a ser destruído.
 */
void DestroiBanco(tBanco *banco)
{
    for (int i = 0; i < banco->qtdContas; i++)
    {
        DestroiConta(banco->contas[i]);
    }
    free(banco->contas);
    free(banco);
}

/**
 * @brief Abre uma nova conta no banco e a adiciona ao vetor de contas.
 *
 * @param banco Ponteiro para o banco onde a conta será aberta.
 */
void AbreContaBanco(tBanco *banco)
{
    if (banco->qtdContas < banco->contasalocadas)
    {
        banco->contas[banco->qtdContas] = CriaConta();
        LeConta(banco->contas[banco->qtdContas]);
        banco->qtdContas++;
    }
}

/**
 * @brief Realiza um saque em uma conta do banco se ela existir e tiver saldo suficiente.
 * Nessa função é necessário ler o número da conta e o valor do saque.
 *
 * @param banco Ponteiro para o banco onde a conta será sacada.
 */
void SaqueContaBanco(tBanco *banco)
{
    int numero, idx = -1;
    float valor;
    scanf("%d %f ", &numero, &valor);
    for (int i = 0; i < banco->qtdContas; i++)
    {
        if (VerificaConta(banco->contas[i], numero))
        {
            idx = i;
            break;
        }
    }
    if (idx != -1)
    {
        SaqueConta(banco->contas[idx], valor);
    }
}

/**
 * @brief Realiza um depósito em uma conta do banco se ela existir.
 * Nessa função é necessário ler o número da conta e o valor do depósito.
 *
 * @param banco Ponteiro para o banco onde a conta será depositada.
 */
void DepositoContaBanco(tBanco *banco)
{
    int numero, idx = -1;
    float valor;
    scanf("%d %f ", &numero, &valor);
    for (int i = 0; i < banco->qtdContas; i++)
    {
        if (VerificaConta(banco->contas[i], numero))
        {
            idx = i;
            break;
        }
    }
    if (idx != -1)
    {
        DepositoConta(banco->contas[idx], valor);
    }
}

/**
 * @brief Realiza uma transferência entre duas contas do banco se elas existirem e a conta de origem tiver saldo suficiente.
 * Nessa função é necessário ler o número da conta de origem, o número da conta de destino e o valor da transferência.
 *
 * @param banco Ponteiro para o banco onde as contas estão.
 */
void TransferenciaContaBanco(tBanco *banco)
{
    int numero1, numero2, idx1 = -1, idx2 = -1;
    float valor;
    scanf("%d %d %f ", &numero1, &numero2, &valor);
    for (int i = 0; i < banco->qtdContas; i++)
    {
        if (VerificaConta(banco->contas[i], numero1))
        {
            idx1 = i;
            break;
        }
    }
    for (int i = 0; i < banco->qtdContas; i++)
    {
        if (VerificaConta(banco->contas[i], numero2))
        {
            idx2 = i;
            break;
        }
    }
    if (idx1 != -1 && idx2 != -1)
    {
        TransferenciaConta(banco->contas[idx1], banco->contas[idx2], valor);
    }
}

/**
 * @brief Imprime o relatório do banco, com todas as contas e seus respectivos dados.
 *
 * @param banco Ponteiro para o banco a ser impresso.
 */
void ImprimeRelatorioBanco(tBanco *banco)
{
    printf("===| Imprimindo Relatorio |===\n");
    for (int i = 0; i < banco->qtdContas; i++)
    {
        ImprimeConta(banco->contas[i]);
    }
}
