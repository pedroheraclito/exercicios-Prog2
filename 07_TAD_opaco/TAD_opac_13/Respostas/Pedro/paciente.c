#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "lesao.h"
#include <string.h>
#include "paciente.h"

#define MAX_NOME_PAC 101
#define MAX_CARTAO_SUS 19
#define MAX_LESOES 10

#include "data.h"
#include "lesao.h"

struct Paciente
{
    char nome[MAX_NOME_PAC];
    char cartaoSus[MAX_CARTAO_SUS];
    Lesao *lesao[MAX_LESOES];
    char genero;
    Data *dataNasc;
    int qtdlesoes;
};

/*
Função que cria um paciente a partir dos parâmetros fornecidos.
@param nome: Nome do paciente.
@param cartaoSus: Cartão SUS do paciente.
@param genero: Gênero do paciente.
@param dataNasc: Data de nascimento do paciente.
@return Ponteiro para o paciente criado.
*/
Paciente *criaPaciente(char *nome, char *cartaoSus, char genero, Data *dataNasc)
{
    Paciente *p = calloc(1, sizeof(Paciente));

    strcpy(p->cartaoSus, cartaoSus);
    strcpy(p->nome, nome);
    p->dataNasc = dataNasc;
    p->genero = genero;
    p->qtdlesoes = 0;

    return p;
}

/*
Função que lê os dados de um paciente a partir da entrada padrão. Consulte o enunciado e/ou os casos de teste para o formato esperado.
@return Ponteiro para o paciente lido.
*/
Paciente *lerPaciente()
{
    char nome[MAX_NOME_PAC];
    char cartaosus[MAX_CARTAO_LES];
    char genero;

    scanf(" %[^\n] ", nome);
    Data *data = lerData();
    scanf(" %[^\n] ", cartaosus);
    scanf(" %c ", &genero);

    Paciente *p = criaPaciente(nome, cartaosus, genero, data);

    return p;
}

/*
Função que adiciona uma lesão ao paciente.
Basicamente, a lesão é adicionada à lista de lesões do paciente realizando toda a alocação dinâmica necessária.
@param p: Ponteiro para o paciente ao qual a lesão será vinculada.
@param l: Ponteiro para a lesão a ser vinculada ao paciente.
*/
void adicionaLesaoPaciente(Paciente *p, Lesao *l)
{
    if (MAX_LESOES > p->qtdlesoes)
    {
        p->lesao[p->qtdlesoes] = l;
        p->qtdlesoes++;
    }
    else
    {
        liberaLesao(l);
    }
}

/*
Função que calcula a idade do paciente em anos completos com base em uma data de referência.
@param p: O paciente cuja idade será calculada.
@param dataBase: A data de referência para o cálculo da idade.
@return A idade do paciente em anos completos.
*/
int calculaIdadePaciente(Paciente *p, Data *dataBase)
{
    return diferencaAnoData(p->dataNasc, dataBase);
}

/*
Função que obtém o cartão SUS de um paciente.
@param p: Ponteiro para o paciente do qual se deseja obter o cartão SUS.
@return Ponteiro para cartão SUS do paciente.
*/
char *getCartaoSusPaciente(Paciente *p)
{
    return p->cartaoSus;
}

/*
Função que obtém o número de lesões associadas a um paciente.
@param p: Ponteiro para o paciente cuja quantidade de lesões será obtida.
@return O número de lesões do paciente.
*/
int getNumLesoesPaciente(Paciente *p)
{
    return p->qtdlesoes;
}

/*
Função que calcula a quantidade de lesões cirúrgicas (malignas) associadas a um paciente.
@param p: Ponteiro para o paciente cuja quantidade de lesões cirúrgicas será calculada.
@return A quantidade de lesões cirúrgicas do paciente.
*/
int qtdLesoesCirurgicasPaciente(Paciente *p)
{
    int qtd = 0;
    for (int i = 0; i < p->qtdlesoes; i++)
    {
        if (verificaCirurgicaLesao(p->lesao[i]))
        {
            qtd++;
        }
    }
    return qtd;
}

/*
Função que imprime o nome do paciente e o ID das lesões associadas a ele (exatamente como solicitado no enunciado e nos casos de teste).
@param p: Ponteiro para o paciente cujas informações serão impressas.
*/
void imprimePaciente(Paciente *p)
{
    int cont = 0;
    for (int i = 0; i < p->qtdlesoes; i++)
    {
        if (verificaCirurgicaLesao(p->lesao[i]))
        {
            cont = 1;
        }
    }
    if (p->qtdlesoes != 0)
    {
        printf("- %s - ", p->nome);
        for (int i = 0; i < p->qtdlesoes; i++)
        {
            imprimeIdLesao(p->lesao[i]);
        }

        printf("\n");
    }
}

/*
Função que libera a memória alocada para um paciente.
@param p: Ponteiro para o paciente a ser liberado.
*/
void liberaPaciente(Paciente *p)
{
    for (int i = 0; i < p->qtdlesoes; i++)
    {
        liberaLesao(p->lesao[i]);
    }
    liberaData(p->dataNasc);
    free(p);
}