#include <stdio.h>
#include <stdlib.h>
#include "jogo.h"

struct Jogo
{
    int min;
    int max;
    int x;
    int numten;
};

/**
 * @brief Cria uma variável do tipo jogo
 *
 * @return Uma variável do tipo jogo inicializada.
 */
tJogo *CriaJogo()
{
    tJogo *jogo = calloc(1, sizeof(tJogo));
    jogo->max = -1;
    jogo->min = -1;
    jogo->x=-1;
    jogo->numten = 0;

    return jogo;
}

/**
 * @brief Libera toda a memória alocada para um jogo.
 *
 * @param jogo - A variável do tipo jogo que será liberada.
 */
void DestroiJogo(tJogo *jogo)
{
    free(jogo);
}

/**
 * @brief Define o valor máximo do intervalo que o jogo deve considerar
 *
 * @param jogo - A variável do tipo jogo que tem os dados do jogo armazenados. O valor será armazenado nela
 * @param max - o valor máximo do intervalo do jogo.
 */
void DefineMaximo(tJogo *jogo, int max)
{
    jogo->max = max;
}

/**
 * @brief Define o valor mínimo do intervalo que o jogo deve considerar
 *
 * @param jogo - A variável do tipo jogo que tem os dados do jogo armazenados. O valor será armazenado nela
 * @param min - o valor mínimo do intervalo do jogo.
 */
void DefineMinimo(tJogo *jogo, int min)
{
    jogo->min = min;
}

/**
 * @brief Calcula o número a ser adivinhado pelo jogador
 * O cálculo deve ser feito como descrito no roteiro.
 *
 * @param jogo - A variável do tipo jogo que tem os dados do jogo armazenados. O cálculo será armazenado nela
 */
void CalculaValorASerAdivinhado(tJogo *jogo, int n)
{
    while (n<0 || n>10000)
    {
        printf("Forneca um numero no intervalo entre 1 e 10000: \n");
       scanf("%d",&n);
    }
    
    int x1 = 0, x2 = 1;
    int cont = 0;
    while (1)
    {
        int prox = x1 + x2;
        x1 = x2;
        x2 = prox;
        int primo = 1;
        if (x2 == 1)
        {
            primo = 0;
        }

        for (int i = 2; i*i < x2; i++)
        {
            if (x2 % i == 0)
            {
                primo = 0;
                break;
            }
        }
        if (primo || x2 == 2)
        {
            cont++;
        }

        if (cont == n)
        {
            int r = x2 % 101;
            jogo->x = (int)round((r / 100.0) * (jogo->max - jogo->min) + jogo->min);
            break;
        }
    }
}

/**
 * @brief Calcula o número de tentativas que o usuário irá ter para acertar o número.
 * O cálculo deve ser feito como descrito no roteiro.
 *
 * @param jogo - A variável do tipo jogo que tem os dados do jogo armazenados. O cálculo será armazenado nela
 */
void CalculaNumeroTentativas(tJogo *jogo)
{
    jogo->numten = (int)log2(jogo->max - jogo->min + 1) + 1;
}

/**
 * @brief Executa o jogo. Calcula o que for necessário e lê as tentativas, fazendo as devidas verificações.
 *
 * @param jogo - A variável do tipo jogo que tem os dados do jogo armazenados.
 * @return int 1 se o usuário venceu o jogo ou 0 caso contrário
 */
int ProcessaTentativas(tJogo *jogo)
{
    int num;
    printf("\n");
    printf("Voce tem direito a %d tentativas\n", jogo->numten);
    for (int i = 0; i < jogo->numten; i++)
    {

        printf("Tentativa %d:\n", i + 1);
        scanf("%d", &num);
        if (num > jogo->x)
        {
            printf("Alta\n");
        }
        else if (num < jogo->x)
        {
            printf("Baixa\n");
        }
        else
        {
            printf("Parabens, voce ganhou!\n");
            return 1;
        }
    }
    printf("Voce perdeu! O numero escolhido foi %d\n",jogo->x);
    return 0;
}