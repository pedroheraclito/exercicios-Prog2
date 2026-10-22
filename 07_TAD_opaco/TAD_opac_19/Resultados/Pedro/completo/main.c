#include <stdio.h>
#include <stdlib.h>
#include "cidade.h"
#include "defesa.h"
#include "missil.h"

int main()
{
    tCidade cidade = CriaCidade();
    LeEntrada(cidade);
    ProcessaAtaques(cidade);
    ImprimeDados(cidade);
    LiberaCidade(cidade);

    return 0;
}