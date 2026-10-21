#include <stdio.h>
#include <stdlib.h>
#include "usuario.h"
#include <string.h>

struct Usuario
{
    char nome[50];
    char cpf[15];
};
/**
 * @brief Cria um novo usuário.
 * Se não for possível alocar memória, o programa é encerrado.
 *
 * @return Um ponteiro para o novo usuário criado.
 */
tUsuario *CriaUsuario()
{
    tUsuario *user = calloc(1, sizeof(tUsuario));
    if (user == NULL)
    {
        printf("sem usuario");
        exit(1);
    }
    strcpy(user->cpf, "\0");
    strcpy(user->nome, "\0");
    return user;
}

/**
 * @brief Desaloca a memória de um usuário.
 *
 * @param user Ponteiro para o usuário a ser destruído.
 */
void DestroiUsuario(tUsuario *user){
    free(user);
}

/**
 * @brief Lê os dados de um usuário da entrada padrão.
 *
 * @param user Ponteiro para o usuário a ser lido.
 */
void LeUsuario(tUsuario *user){
    scanf(" %s %s",user->nome,user->cpf);
}

/**
 * @brief Imprime os dados de um usuário.
 *
 * @param user Ponteiro para o usuário a ser impresso.
 */
void ImprimeUsuario(tUsuario *user){
    printf("Nome: %s\n",user->nome);
    printf("CPF: %s\n",user->cpf);
}