#include <stdio.h>
#include <stdlib.h>
#include "filme.h"
#include <string.h>
#include "locadora.h"

int main()
{
    char comando[30];
    tLocadora *locadora = CriarLocadora();
    int primeiro = 1;
    while (scanf("%s", comando) == 1)
    {
        if (strcmp("Cadastrar", comando) == 0)
        {
            LerCadastroLocadora(locadora);
            printf("\n");
        }
        else if (strcmp("Alugar", comando) == 0)
        {
            LerAluguelLocadora(locadora);
            printf("\n");
        }
        else if (strcmp("Devolver", comando) == 0)
        {
            LerDevolucaoLocadora(locadora);
            printf("\n");
        }
        else if (strcmp("Estoque", comando) == 0)
        {
            OrdenarFilmesLocadora(locadora);
            ConsultarEstoqueLocadora(locadora);
        }
    }
    ConsultarLucroLocadora(locadora);
    DestruirLocadora(locadora);

    return 0;
}