#include <stdio.h>
#include <stdlib.h>
#include "relatorio.h"
#include "aluno.h"

int main()
{
    int qtd;
    scanf("%d", &qtd);
    tAluno *a;
    Vector *v=VectorConstruct();
    for (int i = 0; i < qtd; i++)
    {
        a = CriaAluno();
        LeAluno(a);
        VectorPushBack(v,a);
    }
    ImprimeRelatorio(v);
    VectorDestroy(v,DestroiAluno);

    return 0;
}