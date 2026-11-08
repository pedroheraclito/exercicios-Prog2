#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "banco.h"

/**
 * @brief Estrutura para representar um banco.
 */
struct Banco{
    tAgencia **agencia;
    int qtdagencia;
    char nome[50];
};

/**
 * @brief Função para criar um novo banco.
 * @return Um ponteiro para o novo banco criado. Se a memória não puder ser alocada, a função imprime uma mensagem de erro e termina o programa.
 */
tBanco *CriaBanco(){
    tBanco *b=(tBanco*)calloc(1,sizeof(tBanco));

    b->agencia=(tAgencia**)calloc(1,sizeof(tAgencia*));
    b->qtdagencia=0;


    return b;
}

/**
 * @brief Função para destruir um banco.
 * @param banco O banco a ser destruído.
 */
void DestroiBanco(tBanco *banco){
    for (int i = 0; i < banco->qtdagencia; i++)
    {
      DestroiAgencia(banco->agencia[i]);
    }
    free(banco->agencia);
    free(banco);
}

/**
 * @brief Função para ler o nome de um banco.
 * @param banco O banco a ser lido.
 */
void LeBanco(tBanco *banco){
    scanf(" %[^\n]",banco->nome);
}

/**
 * @brief Função para adicionar uma agência a um banco.
 * @param banco O banco.
 * @param agencia A agência a ser adicionada.
 */
void AdicionaAgencia(tBanco *banco, tAgencia *agencia){
    banco->agencia=(tAgencia**)realloc(banco->agencia,(1+banco->qtdagencia)*sizeof(tAgencia*));
    banco->agencia[banco->qtdagencia]=agencia;
    banco->qtdagencia++;
}

/**
 * @brief Função para inserir uma conta em uma agência pertencente ao banco.
 * @param banco O banco.
 * @param numAgencia O número da agência.
 * @param cliente A conta a ser inserida.
 * @pre A agência deve pertencer ao banco.
*/
void InsereContaBanco(tBanco *banco, int numAgencia, tConta *cliente){
    for (int i = 0; i < banco->qtdagencia; i++)
    {
        if (ComparaAgencia(numAgencia,banco->agencia[i]))
        {
           AdicionaConta(banco->agencia[i],cliente);
        }
        
    }
    
}

/**
 * @brief Função para imprimir o relatório de um banco, com o nome do banco e a lista de agências.
 * @param banco O banco.
 */
void ImprimeRelatorioBanco(tBanco *banco){
    printf("%s\n",banco->nome);
    printf("Lista de agencias:\n");
    for (int i = 0; i < banco->qtdagencia; i++)
    {
     ImprimeDadosAgencia(banco->agencia[i]);
    }
    
}