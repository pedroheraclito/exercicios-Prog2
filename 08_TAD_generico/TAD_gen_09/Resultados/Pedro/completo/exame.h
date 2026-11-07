
#ifndef _EXAME_H
#define _EXAME_H

/*
    Estrutura do tipo exame contendo os atributos necessários para a manipulação
*/
typedef struct _exame exame;

/*
    Função que cria uma exame e retorna o seu endereço de memória
    @param nomeMedicamento: nome do medicamento prescrito na exame
    @param nomePaciente: nome do paciente para quem a exame foi prescrita
    @param nomeMedico: nome do médico que prescreveu a exame
    @param instrucoes: instruções para o uso do medicamento
    @return: endereço de memória da exame criada
*/
exame *criaexame(char *nomeMedico, char *nomePaciente, char *descricao);

/*
    Função que lê os dados de uma exame a partir da entrada padrão de acordo com a especificação
    @return: endereço de memória da exame lida
*/
exame *leexame();

/*
    Função que calcula o preço de impressão de uma exame de acordo com a especificação
    @param dado: ponteiro genérico para a exame a ser calculada
    @param precoCaractere: preço por caractere utilizado no cálculo
    @return: preço de impressão da exame
*/
float calculaPrecoImpressaoexame(void *dado, float precoCaractere);

/*
    Função que imprime uma exame de acordo com a especificação (veja os casos de teste)
    @param dado: ponteiro genérico para a exame a ser impressa
*/
void imprimeexame(void *dado);

/*
    Função que desaloca uma exame
    @param dado: ponteiro genérico para a exame a ser desalocada
*/
void desalocaexame(void *dado);

#endif