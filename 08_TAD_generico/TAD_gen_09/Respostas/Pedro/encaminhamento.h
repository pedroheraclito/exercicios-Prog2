

#ifndef _ENCAMINHAMENTO_H
#define _ENCAMINHAMENTO_H

/*
    Estrutura do tipo encaminho contendo os atributos necessários para a manipulação
*/
typedef struct _Encaminho encaminho;

/*
    Função que cria uma encaminho e retorna o seu endereço de memória
    @param nomeMedico: nome do medico prescrito na encaminho
    @param nomePaciente: nome do paciente para quem a encaminho foi prescrita
    @param especialidade: nome do médico que prescreveu a encaminho
    @param instrucoes: instruções para o uso do medico
    @return: endereço de memória da encaminho criada
*/
encaminho *criaencaminho(char *nomeMedico, char *nomePaciente, char *especialidade, char *motivo);

/*
    Função que lê os dados de uma encaminho a partir da entrada padrão de acordo com a especificação
    @return: endereço de memória da encaminho lida
*/
encaminho *leencaminho();

/*
    Função que calcula o preço de impressão de uma encaminho de acordo com a especificação
    @param dado: ponteiro genérico para a encaminho a ser calculada
    @param precoCaractere: preço por caractere utilizado no cálculo
    @return: preço de impressão da encaminho
*/
float calculaPrecoImpressaoencaminho(void *dado, float precoCaractere);

/*
    Função que imprime uma encaminho de acordo com a especificação (veja os casos de teste)
    @param dado: ponteiro genérico para a encaminho a ser impressa
*/
void imprimeencaminho(void *dado);

/*
    Função que desaloca uma encaminho
    @param dado: ponteiro genérico para a encaminho a ser desalocada
*/
void desalocaencaminho(void *dado);

#endif