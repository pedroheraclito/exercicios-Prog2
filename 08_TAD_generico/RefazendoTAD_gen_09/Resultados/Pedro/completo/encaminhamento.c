#include <stdio.h>
#include <stdlib.h>
#include "encaminhamento.h"
#include <string.h>

/*
    Estrutura do tipo Encaminhamento contendo os atributos necessários para a manipulação
*/
struct _Encaminhamento
{
    char especialidade[50];
    char nomePaciente[100];
    char nomeMedico[100];
    char motivo[200];
};

/*
    Função que cria uma Encaminhamento e retorna o seu endereço de memória
    @param nomeMedicamento: nome do medicamento prescrito na Encaminhamento
    @param nomePaciente: nome do paciente para quem a Encaminhamento foi prescrita
    @param nomeMedico: nome do médico que prescreveu a Encaminhamento
    @param instrucoes: instruções para o uso do medicamento
    @return: endereço de memória da Encaminhamento criada
*/
Encaminhamento *criaEncaminhamento(char *especialidade, char *nomePaciente, char *nomeMedico, char *motivo)
{
    Encaminhamento *e = (Encaminhamento *)calloc(1, sizeof(Encaminhamento));
    strcpy(e->especialidade, especialidade);
    strcpy(e->motivo, motivo);
    strcpy(e->nomeMedico, nomeMedico);
    strcpy(e->nomePaciente, nomePaciente);

    return e;
}

/*
    Função que lê os dados de uma Encaminhamento a partir da entrada padrão de acordo com a especificação
    @return: endereço de memória da Encaminhamento lida
*/
Encaminhamento *leEncaminhamento(){
        char especialidade[50];
    char nomePaciente[100];
    char nomeMedico[100];
    char motivo[200];
    scanf(" %[^\n]\n",nomeMedico);
    scanf(" %[^\n]\n",nomePaciente);
    scanf(" %[^\n]\n",especialidade);
    scanf(" %[^\n]\n",motivo);

    return criaEncaminhamento(especialidade,nomePaciente,nomeMedico,motivo);
}

/*
    Função que calcula o preço de impressão de uma Encaminhamento de acordo com a especificação
    @param dado: ponteiro genérico para a Encaminhamento a ser calculada
    @param precoCaractere: preço por caractere utilizado no cálculo
    @return: preço de impressão da Encaminhamento
*/
float calculaPrecoImpressaoEncaminhamento(void *dado, float precoCaractere){
    Encaminhamento*e=(Encaminhamento*)dado;
    float total=0;
    total+=strlen(e->especialidade);
    total+=strlen(e->nomeMedico);
    total+=strlen(e->nomePaciente);
    total+=strlen(e->motivo);

    return total*precoCaractere;
}

/*
    Função que imprime uma Encaminhamento de acordo com a especificação (veja os casos de teste)
    @param dado: ponteiro genérico para a Encaminhamento a ser impressa
*/
void imprimeEncaminhamento(void *dado){
    Encaminhamento*e=(Encaminhamento*)dado;
    printf("- - ENCAMINHAMENTO - -\n");
    printf("PACIENTE: %s\n",e->nomePaciente);
    printf("ESPECIALIDADE: %s\n",e->especialidade);
    printf("MOTIVO: %s\n",e->motivo);
    printf("MEDICO: %s\n",e->nomeMedico);
    printf("- - - - - - - - - - - -\n");
}

/*
    Função que desaloca uma Encaminhamento
    @param dado: ponteiro genérico para a Encaminhamento a ser desalocada
*/
void desalocaEncaminhamento(void *dado){
    Encaminhamento*e=(Encaminhamento*)dado;
    free(e);
}