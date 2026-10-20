#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

int main()
{
    int qtd, cont = 0;
    scanf("%d", &qtd);
    tAluno *aprovados[qtd];
    for (int i = 0; i < qtd; i++)
    {
        tAluno *aluno = CriaAluno();
        LeAluno(aluno);
        if (VerificaAprovacao(aluno))
        {
            aprovados[cont] = aluno;
            cont++;
        }
        else
        {
            ApagaAluno(aluno);
        }
    }
    for (int i = 0; i < cont; i++)
    {
        for (int j = i + 1; j < cont; j++)
        {
            if (ComparaMatricula(aprovados[i], aprovados[j]) == 1)
            {
                tAluno *temp = aprovados[i];
                aprovados[i] = aprovados[j];
                aprovados[j] = temp;
            }
        }
    }

    for (int i = 0; i < cont; i++)// APAGAR APROVADOS
    {
        ImprimeAluno(aprovados[i]);
        ApagaAluno(aprovados[i]);
    }

    return 0;
}