#include <stdio.h>
#include <stdlib.h>
#include "empresa.h"

struct empresa
{
    tFuncionario *funcionario[20];
    int id;
    int qtdfuncionarios;
};
/**
 * @brief Cria uma empresa "vazia"
 *
 * Seus atributos devem ser inicializados com NULL (ponteiros), ou -1 caso contrário
 * @return TEmpresa* Ponteiro para empresa criada a partir do Id fornecido.
 */
tEmpresa *CriaEmpresa()
{
    tEmpresa *empresa = calloc(1, sizeof(tEmpresa));
    if (empresa == NULL)
    {
        printf("erro na empresa");
        exit(1);
    }
    empresa->id = -1;
    empresa->qtdfuncionarios = 0;
    return empresa;
}

/**
 * @brief Le os dados de uma empresa da entrada padrao.
 * @param *empresa - ponteiro para empresa que terá seus dados preenchidos
 */
void LeEmpresa(tEmpresa *empresa)
{
    int qtd;
    scanf("%d %d", &empresa->id, &qtd);
    for (int i = 0; i < qtd; i++)
    {
        empresa->funcionario[i] = CriaFuncionario();
        LeFuncionario(empresa->funcionario[i]);
        ContrataFuncionarioEmpresa(empresa, empresa->funcionario[i]);
    }
}

/**
 * @brief Libera toda a memória alocada dinamicamente para uma empresa
 * @param *empresa - ponteiro para empresa que terá seus dados apagados e memória liberada
 */
void ApagaEmpresa(tEmpresa *empresa)
{
    for (int i = 0; i < empresa->qtdfuncionarios; i++)
    {
        ApagaFuncionario(empresa->funcionario[i]);
    }
    free(empresa);
}

/**
 * @brief Adiciona um funcionario a uma empresa caso o id do funcionario ainda nao esteja registrado na empresa.
 *
 * @param empresa Ponteiro para Empresa em que o funcionario deve ser adicionado.
 * @param funcionario Ponteiro para Funcionario que deve ser adicionado a empresa.
 */
void ContrataFuncionarioEmpresa(tEmpresa *empresa, tFuncionario *funcionario)
{
    int igual=0;
    for (int i = 0; i < empresa->qtdfuncionarios; i++)
    {
        if (GetIdFuncionario(funcionario)==GetIdFuncionario(empresa->funcionario[i]))
        {
            igual=1;
            printf("A empresa %d ja possui um funcionario com o id %d\n",empresa->id,GetIdFuncionario(funcionario));
            break;
        }
    }
    if (!igual)
    {
        empresa->funcionario[empresa->qtdfuncionarios]=funcionario;
        empresa->qtdfuncionarios++;
    }else{
        ApagaFuncionario(funcionario);
    }
}

/**
 * @brief Imprime todos os dados de um empresa.
 *
 * @param empresa Ponteiro para Empresa a ser impressa no terminal.
 */
void ImprimeEmpresa(tEmpresa *empresa){
    printf("Empresa %d:\n",empresa->id);
    for (int i = 0; i < empresa->qtdfuncionarios; i++)
    {
        ImprimeFuncionario(empresa->funcionario[i]);
    }
    
}