#include <stdio.h>
#include <stdlib.h>
#include "jogo.h"
#include "computador.h"

struct Computador
{
    int n;
    tJogo *jogo;
    int v;
    int d;
};

/**
 * @brief Cria uma variável (alocada dinamicamente) do tipo tComputador
 *
 * @return A variável do tipo Computador inicializada.
 */
tComputador *CriaComputador()
{
    tComputador *cmp = calloc(1, sizeof(tComputador));
    cmp->jogo = CriaJogo();
    cmp->v=0;
    cmp->d=0;
    return cmp;
}

/**
 * @brief Libera toda a memória alocada para uma variável do tipo computador.
 *
 * @param comp - A variável do tipo Computador que terá sua memória liberada
 */
void DestroiComputador(tComputador *comp)
{
    DestroiJogo(comp->jogo);
    free(comp);
}

/**
 * @brief Função que gerencia o jogo. Recebe os dados da entrada padrão, os processa e "lida" com as funções necessárias de jogo.
 *
 * @param computador - Variável computador que salvará o "log" das jogadas, para mostrar o relatório final (apresentado no roteiro)
 */
void GerenciaJogo(tComputador *computador)
{
    int min, max, n;
    int v = 0, d = 0;
    char c;

    printf("Jogo de adivinhação\n");

    while (1)
    {
        printf("Forneca um numero no intervalo entre 1 e 10000:\n");
        scanf("%d", &n);
        while (n < 1 || n > 10000)
        {
            printf("Forneca um numero no intervalo entre 1 e 10000:\n");
            scanf("%d", &n);
        }

        printf("Forneca um intervalo de numeros naturais:");
        scanf("%d %d", &min, &max);
        while (min >= max || min < 0 || max >= 1000000000)
        {
            if (min >= max)
                printf("\nO primeiro numero do intervalo deve ser inferior ao segundo\n");
            else
                printf("\nO segundo numero do intervalo deve ser menor que 1.000.000.000\n");
            printf("Forneca um intervalo de numeros naturais:");
            scanf("%d %d", &min, &max);
        }

        DefineMaximo(computador->jogo, max);
        DefineMinimo(computador->jogo, min);
        CalculaNumeroTentativas(computador->jogo);
        CalculaValorASerAdivinhado(computador->jogo, n);

        if (ProcessaTentativas(computador->jogo))
            computador->v++;
        else
           computador->d++;

        printf("\nDeseja continuar a jogar (s/n):\n");
        scanf(" %c", &c);
        while (c != 's' && c != 'n')
        {
            printf("Voce deve digitar s ou n!\n");
            printf("Deseja continuar a jogar (s/n):\n");
            scanf(" %c", &c);
        }

        if (c == 'n')
            break;
    }

    
}

/**
 * @brief Imprime o relatório "da rodada", mostrado quandoDefine o valor máximo do intervalo que o jogo deve considerar o jogador não deseja jogar novamente, como mostra o roteiro.
 *
 * @param computador - A variável do tipo computador que terá seus dados apresentados em tela.
 */
void ImprimeRelatorio(tComputador *computador)
{
    printf("Obrigado por jogar comigo. Desta vez, voce jogou %d jogo(s), ganhou %d jogo(s) e perdeu %d jogo(s). Ate a proxima!\n", computador->v + computador->d, computador->v, computador->d);
}