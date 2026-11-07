#include <stdio.h>
#include <stdlib.h>
#include "encaminhamento.h"
#include <string.h>

#define MAX_nome 100
#define MAX_inst 200

/*
    Estrutura do tipo encaminho contendo os atributos necessários para a manipulação
*/
struct _Encaminho
{
    char nomeMedico[MAX_nome];
    char nomePaciente[MAX_nome];
    char especialidade[MAX_nome];
    char motivo[MAX_inst];
};

/*
    Função que cria uma encaminho e retorna o seu endereço de memória
    @param nomeMedico: nome do medico prescrito na encaminho
    @param nomePaciente: nome do paciente para quem a encaminho foi prescrita
    @param especialidade: nome do médico que prescreveu a encaminho
    @param motivo: instruções para o uso do medico
    @return: endereço de memória da encaminho criada
*/
encaminho *criaencaminho(char *nomeMedico, char *nomePaciente, char *especialidade, char *motivo)
{
    encaminho *r = (encaminho *)calloc(1, sizeof(encaminho));
    strcpy(r->motivo, motivo);
    strcpy(r->nomeMedico, nomeMedico);
    strcpy(r->especialidade, especialidade);
    strcpy(r->nomePaciente, nomePaciente);
    return r;
}

/*
    Função que lê os dados de uma encaminho a partir da entrada padrão de acordo com a especificação
    @return: endereço de memória da encaminho lida
*/
encaminho *leencaminho()
{
    char nomeMedico[MAX_nome];
    char nomePaciente[MAX_nome];
    char especialidade[MAX_nome];
    char motivo[MAX_inst];
    scanf(" %[^\n]\n", nomeMedico);
    scanf(" %[^\n]\n", nomePaciente);
    scanf(" %[^\n]\n", especialidade);
    scanf(" %[^\n]\n", motivo);
    encaminho *r = criaencaminho(nomeMedico, nomePaciente, especialidade, motivo);

    return r;
}

/*
    Função que calcula o preço de impressão de uma encaminho de acordo com a especificação
    @param dado: ponteiro genérico para a encaminho a ser calculada
    @param precoCaractere: preço por caractere utilizado no cálculo
    @return: preço de impressão da encaminho
*/
float calculaPrecoImpressaoencaminho(void *dado, float precoCaractere)
{
    encaminho *r = (encaminho *)dado;
    float total = 0;

    total += strlen(r->nomeMedico);
    total += strlen(r->especialidade);
    total += strlen(r->nomePaciente);
    total += strlen(r->motivo);

    return total * precoCaractere;
}

/*
    Função que imprime uma encaminho de acordo com a especificação (veja os casos de teste)
    @param dado: ponteiro genérico para a encaminho a ser impressa
*/
void imprimeencaminho(void *dado)
{
    encaminho *r = (encaminho *)dado;
    printf("- - ENCAMINHAMENTO - -\n");
    printf("PACIENTE: %s\n", r->nomePaciente);
    printf("ESPECIALIDADE: %s\n", r->especialidade);
    printf("MOTIVO: %s\n", r->motivo);
    printf("MEDICO: %s\n", r->nomeMedico);
    printf(" - - - - - - - - - - - -\n");
}

/*
    Função que desaloca uma encaminho
    @param dado: ponteiro genérico para a encaminho a ser desalocada
*/
void desalocaencaminho(void *dado)
{
    if (dado == NULL)
        return;
    encaminho *r = (encaminho *)dado;
    free(r);
}