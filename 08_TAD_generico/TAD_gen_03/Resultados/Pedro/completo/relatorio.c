#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "relatorio.h"

/**
 * @brief Imprime o relatorio de uma coleção de alunos.
 * O relatorio deve possuir a media das notas, porcentagem de alunos aprovados e porcentagem de cada gênero.
 *
 * @param alunos Ponteiro para o vetor de alunos.
 */
void ImprimeRelatorio(Vector *alunos)
{
    float soma = 0, media = 0, nota = 0;
    int qtdaprovado = 0, masc = 0, fem = 0, outro = 0;
    for (int i = 0; i < VectorSize(alunos); i++)
    {
        soma += GetNotaAluno(VectorGet(alunos, i));
        nota = GetNotaAluno(VectorGet(alunos, i));
        if (GetGeneroAluno(VectorGet(alunos, i)) == 'F')
        {
            fem++;
        }
        else if (GetGeneroAluno(VectorGet(alunos, i)) == 'M')
        {
            masc++;
        }
        else
        {
            outro++;
        }
        if (nota >= 6)
        {
            qtdaprovado++;
        }
    }
    media = soma / VectorSize(alunos);
    printf("Media das notas: %.2f\n", media);
    printf("Porcentagem de alunos aprovados: %.2f%%\n", (float)qtdaprovado / VectorSize(alunos) * 100);
    printf("Porcentagem de cada genero:\n");
    printf("Masculino: %.2f%%\n", (float)masc / VectorSize(alunos) * 100);
    printf("Feminino: %.2f%%\n", (float)fem / VectorSize(alunos) * 100);
    printf("Outro: %.2f%%\n", (float)outro / VectorSize(alunos) * 100);
}