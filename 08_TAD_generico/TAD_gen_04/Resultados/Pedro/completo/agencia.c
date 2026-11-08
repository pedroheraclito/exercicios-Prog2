#include <stdio.h>
#include <stdlib.h>
#include "conta.h"
#include "agencia.h"

/**
 * @brief Estrutura para representar uma agência bancária.
 */
struct Agencia
{
    int numero;
    char nome[50];
    tConta **contas;
    int qtdcontas;
};

/**
 * @brief Função para criar uma nova agência bancária.
 * @return Um ponteiro para a nova agência bancária criada. Se a memória não puder ser alocada, a função imprime uma mensagem de erro e termina o programa.
 */
tAgencia *CriaAgencia()
{
    tAgencia *a = (tAgencia *)calloc(1, sizeof(tAgencia));

    a->contas = (tConta **)calloc(1, sizeof(tConta*));
    a->qtdcontas=0;

    return a;
}

/**
 * @brief Função para destruir uma agência bancária.
 * @param agencia A agência bancária a ser destruída.
 */
void DestroiAgencia(DataType agencia)
{
    tAgencia *sup=(tAgencia*)agencia;
    for (int  i = 0; i < sup->qtdcontas; i++)
    {
        DestroiConta(sup->contas[i]);
    }
    free(sup->contas);
    free(sup);
}

/**
 * @brief Função para ler uma agência bancária no formato "numero;nome".
 * @param agencia A agência bancária a ser lida.
 */
void LeAgencia(tAgencia *agencia){
    scanf("%d;%[^\n]",&agencia->numero,agencia->nome);
}

/**
 * @brief Função para adicionar uma conta bancária a uma agência bancária.
 * @param agencia A agência bancária.
 * @param conta A conta bancária a ser adicionada.
 */
void AdicionaConta(tAgencia *agencia, tConta *conta){
    agencia->contas=realloc(agencia->contas,(1+agencia->qtdcontas)*sizeof(tConta*));
    agencia->contas[agencia->qtdcontas]=conta;
    agencia->qtdcontas++;
}

/**
 * @brief Função para comparar um número de agência bancária com uma agência bancária.
 * @param numAgencia O número da agência bancária.
 * @param agencia2 A agência bancária a ser comparada.
 * @return 1 se os números forem iguais, 0 caso contrário.
 */
int ComparaAgencia(int numAgencia, tAgencia *agencia2){
    if (agencia2->numero==numAgencia)
    {
       return 1;
    }
    return 0;
}

/**
 * @brief Função para obter o saldo médio das contas de uma agência bancária.
 * @param agencia A agência bancária.
 * @return O saldo médio das contas da agência.
 */
float GetSaldoMedioAgencia(tAgencia *agencia){
    float soma=0,media=0;
    for (int i = 0; i < agencia->qtdcontas; i++)
    {
        soma+=GetSaldoConta(agencia->contas[i]);
    }
    media=soma/agencia->qtdcontas;

    return media;
}

/**
 * @brief Função para imprimir os dados de uma agência bancária (nome, número, número de contas cadastradas e saldo médio).
 * @param agencia A agência bancária.
 */
void ImprimeDadosAgencia(tAgencia *agencia){
    printf("	Nome: %s\n",agencia->nome);
    printf("	Numero: %d\n",agencia->numero);
    printf("	Numero de contas cadastradas: %d\n",agencia->qtdcontas);
    printf("	Saldo médio: R$%.2f\n",GetSaldoMedioAgencia(agencia));
}