#include <stdio.h>
#include <stdlib.h>
#include "conta.h"
#include "agencia.h"
#include "operacao.h"
#include <limits.h>

int main(){
    tAgencia *a=CriaAgencia();
    printf("--- Agencia Bancaria ---");
    LeOperacoes(a);
    ImprimeOperacoesSuspeitas(a);
    ImprimeDoisCorrentistasComMaiorSaldo(a);
    ImprimeSaldoTotal(a);
    DestroiAgencia(a);

    return 0;
}