#include "data.h"
#include "lesao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Função que cria uma lesão a partir dos parâmetros fornecidos.
@param cartaoSus: Cartão SUS do paciente associado à lesão.
@param id: Identificador único da lesão.
@param diagnostico: Diagnóstico da lesão.
@param regiao: Região do corpo onde a lesão está localizada.
@param malignidade: Indicador de malignidade (1 para maligna, 0 para benigna).
@return Ponteiro para a lesão criada.
*/
Lesao *criaLesao(char *cartaoSus, char *id, char *diagnostico, char *regiao, int malignidade)
{
    Lesao *lesao = calloc(1, sizeof(Lesao));
    if (lesao == NULL)
    {
        printf("erro");
        exit(1);
    }
    strcpy(lesao->cartaoSus, cartaoSus);
    strcpy(lesao->id, id);
    strcpy(lesao->diagnostico, diagnostico);
    strcpy(lesao->regiao, regiao);
    lesao->malignidade = malignidade;

    return lesao;
}

/*
Função que lê os dados de uma lesão a partir da entrada padrão. Consulte o enunciado e/ou os casos de teste para o formato esperado.
@return Ponteiro para a lesão lida.
*/
Lesao *lerLesao()
{
    char cartaoSus[19];
    char id[11];
    char diagnostico[101];
    char regiao[101];
    int malignidade;
    scanf(" %[^\n]", cartaoSus);
    scanf(" %[^\n]", id);
    scanf(" %[^\n]", diagnostico);
    scanf(" %[^\n]", regiao);
    scanf("%d", &malignidade);

    return criaLesao(cartaoSus, id, diagnostico, regiao, malignidade);
}

/*
Função que obtém o cartão SUS associado a uma lesão.
@param l: Ponteiro para a lesão da qual se deseja obter o cartão SUS.
@param cartaoSus: String onde o cartão SUS será armazenado.
*/
char *getCartaoSusLesao(Lesao *l){
    return l->cartaoSus;
}

/*
Função que verifica se uma lesão é cirúrgica (maligna).
@param l: Ponteiro para a lesão a ser verificada.
@return 1 se a lesão for cirúrgica (maligna), 0 caso contrário.
*/
int verificaCirurgicaLesao(Lesao *l){
    if (l->malignidade>50)
    {
      return 1;
    }
    return 0;
}

/*
Função que imprime o identificador de uma lesão.
@param l: Ponteiro para a lesão cuja identificação será impressa.
*/
void imprimeIdLesao(Lesao *l){
    printf("%s\n",l->id);
}

/*
Função que libera a memória alocada para uma lesão.
@param l: Ponteiro para a lesão a ser liberada.
*/
void liberaLesao(Lesao *l){
    free(l);
}