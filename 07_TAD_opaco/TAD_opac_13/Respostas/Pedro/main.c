#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "lesao.h"
#include <string.h>
#include "paciente.h"

int main()
{
    char cod;
    scanf(" %c ", &cod);
    if (cod == 'F')
    {
        printf("TOTAL PACIENTES: 0\n");
        printf("MEDIA IDADE (ANOS): -\n");
        printf("TOTAL LESOES: 0\n");
        printf("TOTAL CIRURGIAS: 0\n");
        printf("LISTA DE PACIENTES:\n");
        return 0;
    }

    Paciente *p[20];
    int qtdpacientes = 0;
    int qtdlesoes = 0;
    int qtdcirurgias = 0;
    while (1)
    {
        if (cod == 'P')
        {
            p[qtdpacientes] = lerPaciente();
            qtdpacientes++;
        }
        else if (cod == 'L')
        {
            Lesao *l = lerLesao();
            int cont = 1;
            if (qtdpacientes == 0)
            {
                printf("TOTAL PACIENTES: 0\n");
                printf("MEDIA IDADE (ANOS): -\n");
                printf("TOTAL LESOES: 0\n");
                printf("TOTAL CIRURGIAS: 0\n");
                printf("LISTA DE PACIENTES:\n");
                liberaLesao(l);
                return 0;
            }

            for (int i = 0; i < qtdpacientes; i++)
            {
                if (strcmp(getCartaoSusLesao(l), getCartaoSusPaciente(p[i])) == 0)
                {
                    adicionaLesaoPaciente(p[i], l);
                    cont = 0;
                    break;
                }
            }
            if (cont)
            {
                liberaLesao(l);
            }
            else
            {
                if (verificaCirurgicaLesao(l))
                {
                    qtdcirurgias++;
                }
                qtdlesoes++;
            }
        }
        else if (cod == 'F')
        {
            break;
        }

        scanf(" %c ", &cod);
    }
    Data *database = criaData(12, 9, 2023); // desalocar
    printf("TOTAL PACIENTES: %d\n", qtdpacientes);
    int media = 0;
    for (int i = 0; i < qtdpacientes; i++)
    {
        media += calculaIdadePaciente(p[i], database);
    }
    media = media / qtdpacientes;
    printf("MEDIA IDADE (ANOS): %d\n", media);
    printf("TOTAL LESOES: %d\n", qtdlesoes);
    printf("TOTAL CIRURGIAS: %d\n", qtdcirurgias);
    printf("LISTA DE PACIENTES:\n");
    for (int i = 0; i < qtdpacientes; i++)
    {
        imprimePaciente(p[i]);
    } // liberar agora

    for (int i = 0; i < qtdpacientes; i++)
    {
        liberaPaciente(p[i]);
    }
    liberaData(database);

    return 0;
}