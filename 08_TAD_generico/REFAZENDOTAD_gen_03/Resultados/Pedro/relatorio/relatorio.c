#include <stdio.h>
#include <stdlib.h>
#include "relatorio.h"
#include "aluno.h"

/**
 * @brief Imprime o relatorio de uma coleção de alunos.
 * O relatorio deve possuir a media das notas, porcentagem de alunos aprovados e porcentagem de cada gênero.
 *
 * @param alunos Ponteiro para o vetor de alunos.
 */
void ImprimeRelatorio(Vector *alunos)
{
    int aprovados = 0;
    float soma = 0;
    int masc = 0;
    int fem = 0, outro = 0;
    for (int i = 0; i < VectorSize(alunos); i++)
    {
        soma += GetNotaAluno(VectorGet(alunos, i));
        if (GetNotaAluno(VectorGet(alunos, i)) >= 6)
        {
            aprovados++;
        }

        if (GetGeneroAluno(VectorGet(alunos, i)) == 'M')
        {
            masc++;
        }
        else if (GetGeneroAluno(VectorGet(alunos, i)) == 'F')
        {
            fem++;
        }
        else
        {
            outro++;
        }
    }
    float media = soma / VectorSize(alunos);
    printf("Media das notas: %.2f\n", media);
    float prct=(float)aprovados/VectorSize(alunos)*100;
    printf("Porcentagem de alunos aprovados: %.2f%%\n",prct);
    printf("Porcentagem de cada genero:\n");
    float prct2=(float)masc/VectorSize(alunos)*100;
    printf("Masculino: %.2f%%\n",prct2);
    prct2=(float)fem/VectorSize(alunos)*100;
    printf("Feminino: %.2f%%\n",prct2);
    prct2=(float)outro/VectorSize(alunos)*100;
    printf("Outro: %.2f%%\n",prct2);
}