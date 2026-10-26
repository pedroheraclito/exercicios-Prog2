#include <stdio.h>
#include <stdlib.h>
#include "livro.h"
#include "biblioteca.h"
#include <string.h>

struct Biblioteca
{
    tLivros **livros;
    int numlivros;
    int qtdalocada;
};

/**
 * Inicializa uma biblioteca vazia.
 * Ponteiros são inicializados com NULL;
 * @return A biblioteca inicializada.
 */
tBiblioteca *InicializarBiblioteca()
{
    tBiblioteca *b = calloc(1, sizeof(tBiblioteca));
    b->livros = calloc(30, sizeof(tLivros *));
    b->numlivros = 0;
    b->qtdalocada = 0;
    return b;
}

/**
 * Apaga toda a memória alocada dinamicamente dentro de uma biblioteca
 * Ponteiros são inicializados com NULL;
 * @return A biblioteca inicializada.
 */
void ApagaBiblioteca(tBiblioteca *biblioteca)
{
    for (int i = 0; i < biblioteca->numlivros; i++)
    {
        ApagaLivro(biblioteca->livros[i]);
    }
    free(biblioteca->livros);
    free(biblioteca);
}

/**
 * Adiciona um livro à biblioteca.
 * Se estiver dentro do tamanho máximo de livros, imprime "Livro adicionado com sucesso!"
 * Senão, imprime "A biblioteca está cheia. Não é possível adicionar mais livros."
 *
 * @param biblioteca Ponteiro para a biblioteca onde o livro será adicionado.
 * @param livro Ponteiro para o livro a ser adicionado.
 */
void AdicionarLivroNaBiblioteca(tBiblioteca *biblioteca, tLivros *livro)
{
    biblioteca->livros[biblioteca->numlivros] = livro;
    biblioteca->numlivros++;
    biblioteca->qtdalocada++;
    printf("Livro adicionado com sucesso!\n");
}

/**
 * Remove um livro da biblioteca pelo título.
 * Se o título for encontrado, imprime "Livro removido com sucesso!",
 * Senão, imprime "Livro não encontrado na biblioteca."
 *
 * @param biblioteca Ponteiro para a biblioteca da qual o livro será removido.
 * @param titulo O título do livro a ser removido.
 */
void RemoverLivroDaBiblioteca(tBiblioteca *biblioteca, char *titulo)
{
    int cont = 1;
    for (int i = 0; i < biblioteca->numlivros; i++)
    {
        
        if (strcmp(getTitulo(biblioteca->livros[i]), titulo) == 0)
        {
            ApagaLivro(biblioteca->livros[i]);
            for (int j = i; j < biblioteca->numlivros - 1; j++)
            {
                biblioteca->livros[j] = biblioteca->livros[j + 1];
            }
            biblioteca->numlivros--;
            printf("Livro removido com sucesso!\n");
            cont = 0;
            break;
        }
    }
    if (cont)
    {
        printf("Livro nao encontrado na biblioteca.\n");
    }
}

/**
 * Verifica se o título digitado é igual ao título do livro.
 *
 * @param livro Ponteiro para o livro cujo título será verificado.
 * @param titulo O título digitado pelo usuário.
 * @return se o título for igual, retorna 0.
 */
int VerificaTituloDoLivroNaBiblioteca(tLivros *livro, char *titulo)
{
    if (strcmp(getTitulo(livro), titulo) == 0)
    {
        return 1;
    }
    return 0;
}

/**
 * Lista todos os livros presentes na biblioteca.
 * Se não houver livros na biblioteca, imprime "A biblioteca esta vazia!"
 *
 * @param biblioteca Ponteiro para a biblioteca cujos livros serão listados.
 */
void ListarLivrosDaBiblioteca(tBiblioteca *biblioteca)
{
    if (biblioteca->numlivros == 0)
    {
        printf("A biblioteca esta vazia!\n");
    }
    else
    {

        printf("\nLista de Livros na Biblioteca:\n");
        for (int i = 0; i < biblioteca->numlivros; i++)
        {
            ImprimeLivro(biblioteca->livros[i]);
        }
    }
}