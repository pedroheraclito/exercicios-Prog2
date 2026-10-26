#include <stdio.h>
#include <stdlib.h>
#include "livro.h"
#include "biblioteca.h"
#include <string.h>

int main()
{
    int n, cod;
    char titulo[50];
    scanf("%d", &n);
    printf("Lista de operacoes:\n");
    printf("1 - Cadastrar livros.\n");
    printf("2 - Remover livros.\n");
    printf("3 - Listar todos os livros cadastrados.\n");
    tBiblioteca *b = InicializarBiblioteca();
    scanf("%d", &cod);
    for (int i = 0; i < n; i++)
    {
        if (cod == 1)
        {
            tLivros *L = CriaLivro();
            LerLivro(L);
            AdicionarLivroNaBiblioteca(b, L);
        }
        else if (cod == 2)
        {
            scanf(" %[^\n]", titulo);
            RemoverLivroDaBiblioteca(b, titulo);
        }
        else if (cod == 3)
        {
            ListarLivrosDaBiblioteca(b);
        }
        else
        {
            printf("Operacao invalida!\n");
             ApagaBiblioteca(b);
            return 0;
        }
        scanf("%d", &cod);
    }
    ApagaBiblioteca(b);

    return 0;
}