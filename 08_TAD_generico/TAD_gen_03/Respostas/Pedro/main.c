#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "relatorio.h"

int main()
{
    int qtd;
    scanf("%d", &qtd);
    Vector *alunos = VectorConstruct();
    for (int i = 0; i < qtd; i++)
    {
        tAluno *a = CriaAluno();
        LeAluno(a);
        VectorPushBack(alunos,a);
    }
    ImprimeRelatorio(alunos);
    VectorDestroy(alunos,DestroiAluno);
    return 0;
}