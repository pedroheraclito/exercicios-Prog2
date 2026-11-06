#include <stdio.h>
#include <stdlib.h>
#include "receita.h"
#include <string.h>

#define MAX_nome 100
#define MAX_inst 200
/*
    Estrutura do tipo Receita contendo os atributos necessários para a manipulação
*/
struct _Receita
{
    char nomeMedicamento[MAX_nome];
    char nomePaciente[MAX_nome];
    char nomeMedico[MAX_nome];
    char instrucoes[MAX_inst];
};

/*
    Função que cria uma receita e retorna o seu endereço de memória
    @param nomeMedicamento: nome do medicamento prescrito na receita
    @param nomePaciente: nome do paciente para quem a receita foi prescrita
    @param nomeMedico: nome do médico que prescreveu a receita
    @param instrucoes: instruções para o uso do medicamento
    @return: endereço de memória da receita criada
*/
Receita *criaReceita(char *nomeMedicamento, char *nomePaciente, char *nomeMedico, char *instrucoes)
{
    Receita *r = (Receita *)calloc(1, sizeof(Receita));
    strcpy(r->instrucoes, instrucoes);
    strcpy(r->nomeMedicamento, nomeMedicamento);
    strcpy(r->nomeMedico, nomeMedico);
    strcpy(r->nomePaciente, nomePaciente);

    return r;
}

/*
    Função que lê os dados de uma receita a partir da entrada padrão de acordo com a especificação
    @return: endereço de memória da receita lida
*/
Receita *leReceita()
{
    char nomeMedicamento[MAX_nome];
    char nomePaciente[MAX_nome];
    char nomeMedico[MAX_nome];
    char instrucoes[MAX_inst];
    scanf(" %[^\n]\n", nomeMedico);
    scanf(" %[^\n]\n", nomePaciente);
    scanf(" %[^\n]\n", nomeMedicamento);
    scanf(" %[^\n]\n", instrucoes);
    Receita *r = criaReceita(nomeMedicamento, nomePaciente, nomeMedico, instrucoes);

    return r;
}

/*
    Função que calcula o preço de impressão de uma receita de acordo com a especificação
    @param dado: ponteiro genérico para a receita a ser calculada
    @param precoCaractere: preço por caractere utilizado no cálculo
    @return: preço de impressão da receita
*/
float calculaPrecoImpressaoReceita(void *dado, float precoCaractere)
{
    Receita *r = (Receita *)dado;
    float total = 0;

    total += strlen(r->nomeMedicamento);
    total += strlen(r->nomeMedico);
    total += strlen(r->nomePaciente);
    total += strlen(r->instrucoes);

    return total*precoCaractere;
}

/*
    Função que imprime uma receita de acordo com a especificação (veja os casos de teste)
    @param dado: ponteiro genérico para a receita a ser impressa
*/
void imprimeReceita(void *dado)
{

    Receita *r = (Receita *)dado;
    printf("- - RECEITA - -\n");
    printf("MEDICAMENTO: %s\n", r->nomeMedicamento);
    printf("PACIENTE: %s\n", r->nomePaciente);
    printf("INSTRUCOES: %s\n", r->instrucoes);
    printf("MEDICO: %s\n", r->nomeMedico);
    printf("- - - - - - - -\n");
}

/*
    Função que desaloca uma receita
    @param dado: ponteiro genérico para a receita a ser desalocada
*/
void desalocaReceita(void *dado){
     if (dado == NULL) return;
     Receita *r = (Receita *)dado;
     free(r);
}