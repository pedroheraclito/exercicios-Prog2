#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agencia.h"
struct Agencia{
    tConta **conta;
    int qtdcontas;
    char nome[50];
    int numagencia;
};

/**
 * @brief Função para criar uma nova agência bancária.
 * @return Um ponteiro para a nova agência bancária criada. Se a memória não puder ser alocada, a função imprime uma mensagem de erro e termina o programa.
 */
tAgencia *CriaAgencia(){
    tAgencia*a=(tAgencia*)calloc(1,sizeof(tAgencia));
    a->conta=(tConta**)calloc(1,sizeof(tConta*));
    a->qtdcontas=0;

    return a;
}

/**
 * @brief Função para destruir uma agência bancária.
 * @param agencia A agência bancária a ser destruída.
 */
void DestroiAgencia(DataType agencia){
    tAgencia*a=(tAgencia*)agencia;
    for (int i = 0; i < a->qtdcontas; i++)
    {
        DestroiConta(a->conta[i]);
    }
    free(a->conta);
    free(a);
}

/**
 * @brief Função para ler uma agência bancária no formato "numero;nome".
 * @param agencia A agência bancária a ser lida.
 */
void LeAgencia(tAgencia *agencia){
    scanf("%d;%[^\n]",&agencia->numagencia,agencia->nome);
}

/**
 * @brief Função para adicionar uma conta bancária a uma agência bancária.
 * @param agencia A agência bancária.
 * @param conta A conta bancária a ser adicionada.
 */
void AdicionaConta(tAgencia *agencia, tConta *conta){
   agencia->conta= realloc(agencia->conta,(agencia->qtdcontas+1)*sizeof(tConta*));
   agencia->conta[agencia->qtdcontas]=conta;
   agencia->qtdcontas++;
}

/**
 * @brief Função para comparar um número de agência bancária com uma agência bancária.
 * @param numAgencia O número da agência bancária.
 * @param agencia2 A agência bancária a ser comparada.
 * @return 1 se os números forem iguais, 0 caso contrário.
 */
int ComparaAgencia(int numAgencia, tAgencia *agencia2){
    if (numAgencia==agencia2->numagencia)
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
float GetSaldoMedioAgencia (tAgencia *agencia){
    float soma=0,media=0;
    for (int i = 0; i < agencia->qtdcontas; i++)
    {
        soma+=GetSaldoConta(agencia->conta[i]);
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
    printf("	Numero: %d\n",agencia->numagencia);
    printf("	Numero de contas cadastradas: %d\n",agencia->qtdcontas);
    printf("	Saldo médio: R$%.2f\n",GetSaldoMedioAgencia(agencia));
    
}