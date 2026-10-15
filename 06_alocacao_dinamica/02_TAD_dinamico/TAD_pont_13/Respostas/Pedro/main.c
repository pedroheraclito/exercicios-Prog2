#include "data.h"
#include "lesao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "paciente.h"

int main()
{
    char cod;
    Paciente *p[20];
    int totapacientes = 0, totalesoes = 0, totalcirurgias = 0, mediaidades = 0, soma = 0;
    scanf(" %c%*c", &cod);
    while (1)
    {
        if (cod == 'P')
        {
            p[totapacientes] = lerPaciente();
            totapacientes++;
        }
        else if (cod == 'L')
        {
            Lesao *lesao = lerLesao();
            int vinculada = 0;
            for (int i = 0; i < totapacientes; i++)
            {
                if (strcmp(getCartaoSusPaciente(p[i]), getCartaoSusLesao(lesao)) == 0)
                {
                    vinculaLesaoPaciente(p[i], lesao);
                    vinculada = 1;
                    break;
                }
            }
            if (vinculada)
            {
                totalesoes++;
            }
            else
            {
                liberaLesao(lesao);
            }
        }
        else if (cod == 'F')
        {
            break;
        }
        scanf(" %c%*c", &cod);
    }
    Data *hoje = criaData(12, 9, 2023);
    for (int i = 0; i < totapacientes; i++)
    {
        soma += calculaIdadePaciente(p[i], hoje);
    }
    liberaData(hoje);
    if (totapacientes != 0)
    {
        mediaidades = soma / totapacientes;
    }
    printf("TOTAL PACIENTES: %d\n", totapacientes);
    if (mediaidades == 0)
    {
       printf("MEDIA IDADE (ANOS): -\n", mediaidades);
    }
    else
    {
        printf("MEDIA IDADE (ANOS): %d\n", mediaidades);
    }

    printf("TOTAL LESOES: %d\n", totalesoes);
    for (int i = 0; i < totapacientes; i++)
    {
        totalcirurgias += qtdLesoesCirurgicasPaciente(p[i]);
    }
    printf("TOTAL CIRURGIAS: %d\n", totalcirurgias);
    printf("LISTA DE PACIENTES:\n");
    for (int i = 0; i < totapacientes; i++)
    {
        imprimePaciente(p[i]);
    }
    for (int i = 0; i < totapacientes; i++) // libera pacientes
    {

        liberaPaciente(p[i]);
    }

    return 0;
}