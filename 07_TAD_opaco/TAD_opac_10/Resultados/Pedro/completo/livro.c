#include <stdio.h>
#include <stdlib.h>
#include "livro.h"


struct Livros{
    char *titulo;
    char *autor;
    int ano;
};
/**
 * Cria um livro "vazio". Ponteiros devem receber null e os atributos numéricos valor -1;
 *
 * @return Um ponteiro para um livro livro "vazio"
 */
tLivros* CriaLivro(){
    tLivros *liv=calloc(1,sizeof(tLivros));

    liv->autor=calloc(50,sizeof(char));
    liv->titulo=calloc(50,sizeof(char));
    liv->ano=-1;
    
    return liv;
}

/**
 * Lê os atributos de um livro a partir da entrada padrão (teclado).
 *
 * @param livro Um ponteiro para um livro que receberá os atributos lidos
 */
void LerLivro(tLivros* livro){
    scanf(" %[^\n]",livro->titulo);
    scanf(" %[^\n]",livro->autor);
    scanf("%d",&livro->ano);

}

/**
 * Imprime os atributos da TAD tLivros (título, autor e ano de publicação).
 * 
 * @param livro Um ponteiro para o livro cujos atributos serão impressos
*/
void ImprimeLivro(tLivros* livro){
    printf("Titulo: %s\n",livro->titulo);
    printf("Autor: %s\n",livro->autor);
    printf("Ano de Publicacao: %d\n",livro->ano);
}

/**
 * Retorna o título do livro.
 * 
 * @param livro Ponteiro para o livro cujo título será retornado.
 * @return O título do livro.
*/
char *getTitulo(tLivros* livro){
    return livro->titulo;
}

/**
 * Função para liberar toda a memória alocada por um livro
 * 
 * @param livro Um ponteiro para o livro cujos atributos serão apagados/liberados
*/
void ApagaLivro(tLivros* livro){
    free(livro->autor);
    free(livro->titulo);
    free(livro);
}