#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exame.h"

#define MAX_nome 100
#define MAX_inst 200

typedef struct _exame
{
    char nomeMedico[MAX_nome];
    char nomePaciente[MAX_nome];
    char descricao[MAX_nome];
};

/*
    Função que cria uma examecriaexame e retorna o seu endereço de memória
    @param nomeMedico: nome do mediconomeMedico prescrito na examecriaexame
    @param nomePaciente: nome do paciente para quem a examecriaexame foi prescrita
    @param nomeMedico: nome do médico que prescreveu a examecriaexame
    @param instrucoes: instruções para o uso do mediconomeMedico
    @return: endereço de memória da examecriaexame criada
*/
exame *criaexame(char *nomeMedico, char *nomePaciente, char *descricao)
{
    exame *r = (exame *)calloc(1, sizeof(exame));
    strcpy(r->descricao, descricao);
    strcpy(r->nomeMedico, nomeMedico);
    strcpy(r->nomePaciente, nomePaciente);

    return r;
}

/*
    Função que lê os dados de uma examecriaexame a partir da entrada padrão de acordo com a especificação
    @return: endereço de memória da examecriaexame lida
*/
exame *leexame()
{
    char nomeMedico[MAX_nome];
    char nomePaciente[MAX_nome];
    char descricao[MAX_nome];
    scanf(" %[^\n]\n", nomeMedico);
    scanf(" %[^\n]\n", nomePaciente);
    scanf(" %[^\n]\n", descricao);
    exame *r = criaexame(nomeMedico, nomePaciente, descricao);

    return r;
}

/*
    Função que calcula o preço de impressão de uma examecriaexame de acordo com a especificação
    @param dado: ponteiro genérico para a examecriaexame a ser calculada
    @param precoCaractere: preço por caractere utilizado no cálculo
    @return: preço de impressão da examecriaexame
*/
float calculaPrecoImpressaoexame(void *dado, float precoCaractere)
{
    exame *r = (exame *)dado;
    float total = 0;

    total += strlen(r->nomeMedico);
    total += strlen(r->descricao);
    total += strlen(r->nomePaciente);

    return total * precoCaractere;
}

/*
    Função que imprime uma examecriaexame de acordo com a especificação (veja os casos de teste)
    @param dado: ponteiro genérico para a examecriaexame a ser impressa
*/
void imprimeexame(void *dado)
{
    exame *r = (exame *)dado;
    printf("- - EXAME - -\n");
    printf("PACIENTE: %s\n", r->nomePaciente);
    printf("SOLICITACAO: %s\n", r->descricao);
    printf("MEDICO: %s\n", r->nomeMedico);
    printf("- - - - - - -\n");
}

/*
    Função que desaloca uma examecriaexame
    @param dado: ponteiro genérico para a examecriaexame a ser desalocada
*/
void desalocaexame(void *dado)
{
        if (dado == NULL)
        return;
    exame *r = (exame *)dado;
    free(r);
}