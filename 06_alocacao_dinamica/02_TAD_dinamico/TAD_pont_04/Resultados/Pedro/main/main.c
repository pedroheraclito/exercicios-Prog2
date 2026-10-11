#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int qtd;
    scanf("%d", &qtd);

    tAluno *aprovados[20];
    int numAprovados = 0;

    for (int i = 0; i < qtd; i++)
    {
        tAluno *aluno = CriaAluno();
        LeAluno(aluno);

        if (VerificaAprovacao(aluno))
        {
            aprovados[numAprovados++] = aluno;
        }
        else
        {
            ApagaAluno(aluno);
        }
    }

    for (int i = 0; i < numAprovados; i++)
    {
        for (int j = i + 1; j < numAprovados; j++)
        {
            if (ComparaMatricula(aprovados[i], aprovados[j]) == 1)
            {
                tAluno *temp = aprovados[i];
                aprovados[i] = aprovados[j];
                aprovados[j] = temp;
            }
        }
    }

    for (int i = 0; i < numAprovados; i++)
    {
        ImprimeAluno(aprovados[i]);
        ApagaAluno(aprovados[i]);
    }

    return 0;
}