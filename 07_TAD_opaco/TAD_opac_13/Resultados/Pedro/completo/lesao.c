#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "lesao.h"
#include <string.h>

#define MAX_CARTAO_LES 19
#define MAX_ID_LES 11
#define MAX_DIAG_LES 101
#define MAX_REG_LES 101

struct Lesao
{
    char cartaosus[MAX_CARTAO_LES];
    char id[MAX_ID_LES];
    char diag[MAX_DIAG_LES];
    char regiao[MAX_REG_LES];
    int magnilidade;
};

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
    Lesao *l = calloc(1, sizeof(Lesao));

    strcpy(l->cartaosus, cartaoSus);
    strcpy(l->id, id);
    strcpy(l->diag, diagnostico);
    strcpy(l->regiao, regiao);
    l->magnilidade = malignidade;

    return l;
}

/*
Função que lê os dados de uma lesão a partir da entrada padrão. Consulte o enunciado e/ou os casos de teste para o formato esperado.
@return Ponteiro para a lesão lida.
*/
Lesao *lerLesao(){
    char cartaosus[MAX_CARTAO_LES];
    char id[MAX_ID_LES];
    char diag[MAX_DIAG_LES];
    char regiao[MAX_REG_LES];
    int magnilidade;
    scanf(" %[^\n]",cartaosus);
    scanf(" %[^\n]",id);
    scanf(" %[^\n]",diag);
    scanf(" %[^\n]",regiao);
    scanf("%d ",&magnilidade);
    Lesao *l=criaLesao(cartaosus,id,diag,regiao,magnilidade);

    return l;
}

/*
Função que obtém o cartão SUS associado a uma lesão.
@param l: Ponteiro para a lesão da qual se deseja obter o cartão SUS.
@param cartaoSus: String onde o cartão SUS será armazenado.
*/
char *getCartaoSusLesao(Lesao *l){
    return l->cartaosus;
}

/*
Função que verifica se uma lesão é cirúrgica (maligna).
@param l: Ponteiro para a lesão a ser verificada.
@return 1 se a lesão for cirúrgica (maligna), 0 caso contrário.
*/
int verificaCirurgicaLesao(Lesao *l){
    if (l->magnilidade>50)
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
    printf("%s ",l->id);
}

/*
Função que libera a memória alocada para uma lesão.
@param l: Ponteiro para a lesão a ser liberada.
*/
void liberaLesao(Lesao *l){
    free(l);
}