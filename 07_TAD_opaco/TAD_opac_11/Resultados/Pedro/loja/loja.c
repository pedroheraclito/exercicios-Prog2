#include <stdio.h>
#include <stdlib.h>
#include "vendedor.h"
#include <string.h>
#include "loja.h"

struct Loja{
    int id;
    float aluguel;
    tVendedor *vendedor[20];
    float lucro;
    int totalpessoas;
};
/**
 * @brief Abre uma nova loja.
 * 
 * @param id ID da loja.
 * @param aluguel Valor do aluguel da loja.
 * @return tLoja Retorna a estrutura do tipo tLoja com os dados da loja aberta.
 */
tLoja* AbreLoja(int id, float aluguel){
    tLoja *loja=calloc(1,sizeof(tLoja));
    if (loja==NULL)
    {
        printf("ERRO");
        exit(1);
    }
    loja->id=id;
    loja->aluguel=aluguel;
    loja->lucro=0;
    loja->totalpessoas=0;

    return loja;
}

/**
 * @brief Libera a memória alocada para uma loja.
 * 
 * @param loja Ponteiro para uma loja a ser apagado.
 */
void ApagaLoja(tLoja* loja){
    for (int i = 0; i < loja->totalpessoas; i++)
    {
        ApagaVendedor(loja->vendedor[i]);
    }
    free(loja);
}

/**
 * @brief Verifica se o ID de uma loja é igual a outro.
 * 
 * @param loja Estrutura do tipo tLoja contendo os dados da loja a ser verificada.
 * @param id ID da loja a ser comparado.
 * @return int Retorna 1 se o ID da loja é igual ao ID passado como parâmetro, ou 0 caso contrário.
 */
int VerificaIdLoja(tLoja* loja, int id){
    if (loja->id==id)
    {
        return 1;
    }
    return 0;
}

/**
 * @brief Contrata um novo vendedor para a loja.
 * 
 * @param loja Estrutura do tipo tLoja contendo os dados da loja.
 * @param vendedor Estrutura do tipo tVendedor contendo os dados do vendedor a ser contratado.
 * @return tLoja Retorna a estrutura do tipo tLoja atualizada com o novo vendedor contratado.
 */
void ContrataVendedor(tLoja* loja, tVendedor* vendedor){
    loja->vendedor[loja->totalpessoas]=vendedor;
    loja->totalpessoas++;
}

/**
 * @brief Registra uma nova venda para um vendedor da loja.
 * 
 * @param loja Estrutura do tipo tLoja contendo os dados da loja.
 * @param nome Nome do vendedor que realizou a venda.
 * @param valor Valor da venda a ser registrada.
 * @return tLoja Retorna a estrutura do tipo tLoja atualizada com a venda registrada.
 */
void RegistraVenda(tLoja* loja, char* nome, float valor){
    for (int i = 0; i < loja->totalpessoas; i++)
    {
        if (VerificaNomeVendedor(loja->vendedor[i],nome))
        {
            ContabilizaVenda(loja->vendedor[i],valor);
            break;
        }
        
    }
    
}

/**
 * @brief Calcula o lucro da loja.
 * 
 * @param loja Estrutura do tipo tLoja contendo os dados da loja.
 * @return tLoja Retorna a estrutura do tipo tLoja atualizada com o lucro calculado.
 */
void CalculaLucro(tLoja* loja){
    float total=0;
    for (int i = 0; i < loja->totalpessoas; i++)
    {
        total+=GetTotalVendido(loja->vendedor[i])-GetTotalRecebido(loja->vendedor[i]);
    }
    loja->lucro= total-loja->aluguel;
}

/**
 * @brief Imprime o relatório da loja.
 * 
 * @param loja Estrutura do tipo tLoja contendo os dados da loja.
 */
void ImprimeRelatorioLoja(tLoja* loja){
    printf("Loja %d: Lucro total: R$ %.2f\n",loja->id ,loja->lucro);
    for (int i = 0; i < loja->totalpessoas; i++)
    {
        ImprimeRelatorioVendedor(loja->vendedor[i]);
    }
    
}
