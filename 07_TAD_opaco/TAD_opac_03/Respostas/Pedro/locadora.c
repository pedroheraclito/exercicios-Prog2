#include <stdio.h>
#include <stdlib.h>
#include "filme.h"
#include <string.h>
#include "locadora.h"

struct Locadora
{
    tFilme *filmes[100];
    int qtdfilmes;
    int lucro;
};

/**
 * @brief Cria uma nova instância de tLocadora e inicializa filme como NULL, numFilmes como 0 e lucro como 0.
 *
 * @return tLocadora* Ponteiro para a nova instância de tLocadora criada ou encerra o programa caso não haja memória suficiente.
 */
tLocadora *CriarLocadora()
{
    tLocadora *l = calloc(1, sizeof(tLocadora));

    for (int i = 0; i < 100; i++)
    {
        l->filmes[i] = NULL;
    }
    l->lucro = 0;
    l->qtdfilmes = 0;

    return l;
}

/**
 * @brief Destrói uma instância de tLocadora.
 *
 * @param locadora Ponteiro para a instância de tLocadora a ser destruída.
 */
void DestruirLocadora(tLocadora *locadora)
{
    for (int i = 0; i < locadora->qtdfilmes; i++)
    {
        DestruirFilme(locadora->filmes[i]);
    }
    free(locadora);
}

/**
 * @brief Verifica se um filme está cadastrado na locadora.
 *
 * @param locadora Ponteiro para a instância de tLocadora a ser verificada.
 * @param codigo Código do filme a ser verificado.
 * @return int 1 se o filme está cadastrado, 0 caso contrário.
 */
int VerificarFilmeCadastrado(tLocadora *locadora, int codigo)
{
    for (int i = 0; i < locadora->qtdfilmes; i++)
    {
        if (EhMesmoCodigoFilme(locadora->filmes[i], codigo))
        {
            return 1;
        }
    }
    return 0;
}

/**
 * @brief Cadastra um novo filme na locadora caso ele não esteja cadastrado.
 *
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 * @param filme Ponteiro para o filme a ser cadastrado.
 */
void CadastrarFilmeLocadora(tLocadora *locadora, tFilme *filme)
{
    if (!VerificarFilmeCadastrado(locadora, ObterCodigoFilme(filme)))
    {
        locadora->filmes[locadora->qtdfilmes] = filme;
        printf("Filme cadastrado %d - ", ObterCodigoFilme(locadora->filmes[locadora->qtdfilmes]));
        ImprimirNomeFilme(locadora->filmes[locadora->qtdfilmes]);
        printf("\n");
        locadora->qtdfilmes++;
    }
    else
    {
        printf("Filme ja cadastrado no estoque\n");
        DestruirFilme(filme);
    }
}

/**
 * @brief Lê os dados de cadastro de um filme e o cadastra na locadora.
 *
 * @param Locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void LerCadastroLocadora(tLocadora *Locadora)
{
    int codigo;

    while (scanf(" %d, ", &codigo))
    {
        tFilme *filme = CriarFilme();
        LeFilme(filme, codigo);
        CadastrarFilmeLocadora(Locadora, filme);
    }
    scanf("%*c");
}

/**
 * @brief Aluga um ou mais filmes da locadora.
 *
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 * @param codigos Vetor contendo os códigos dos filmes a serem alugados.
 * @param quantidadeCodigos Número de códigos de filmes a serem alugados.
 */
void AlugarFilmesLocadora(tLocadora *locadora, int *codigos, int quantidadeCodigos)
{
    int qtd = 0, valor = 0;
    for (int i = 0; i < quantidadeCodigos; i++)
    {
        int existe = 1;
        for (int j = 0; j < locadora->qtdfilmes; j++)
        {
            if (EhMesmoCodigoFilme(locadora->filmes[j], codigos[i]))
            {
                int qtdatual = ObterQtdEstoqueFilme(locadora->filmes[j]);
                if (qtdatual != 0)
                {
                    AlugarFilme(locadora->filmes[j]);
                    qtd++;
                    valor += ObterValorFilme(locadora->filmes[j]);
                    existe = 0;
                    break;
                }
                else
                {
                    printf("Filme %d - ", ObterCodigoFilme(locadora->filmes[j]));
                    ImprimirNomeFilme(locadora->filmes[j]);
                    printf(" nao disponivel no estoque. Volte mais tarde.\n");
                    existe = 0;
                }
            }
        }
        if (existe)
        {
            printf("Filme %d nao cadastrado.\n", codigos[i]);
        }
    }
    if (qtd)
    {
        printf("Total de filmes alugados: %d com custo de R$%d\n", qtd, valor);
    }
}

/**
 * @brief Lê o aluguel de um conjunto de filmes a partir da entrada padrão e os aluga na locadora.
 *
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void LerAluguelLocadora(tLocadora *locadora)
{
    int cod, qtd = 0;
    int codigos[30];
    while (scanf(" %d ", &cod) == 1)
    {
        codigos[qtd] = cod;
        qtd++;
    }
    AlugarFilmesLocadora(locadora, codigos, qtd);
}

/**
 * @brief Devolve um ou mais filmes alugados da locadora.
 *
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 * @param codigos Vetor contendo os códigos dos filmes a serem devolvidos.
 * @param quantidadeCodigos Número de códigos de filmes a serem devolvidos.
 */
void DevolverFilmesLocadora(tLocadora *locadora, int *codigos, int quantidadeCodigos)
{
    for (int i = 0; i < quantidadeCodigos; i++)
    {
        int existe=1;
        for (int j = 0; j < locadora->qtdfilmes; j++)
        {
            if (EhMesmoCodigoFilme(locadora->filmes[j], codigos[i]))
            {
                if (ObterQtdAlugadaFilme(locadora->filmes[j]) == 0)
                {
                    printf("Nao e possivel devolver o filme %d - ", ObterCodigoFilme(locadora->filmes[j]));
                    ImprimirNomeFilme(locadora->filmes[j]);
                    existe=0;
                    printf(".\n");
                }
                else
                {
                    DevolverFilme(locadora->filmes[j]);
                    printf("Filme %d - ", ObterCodigoFilme(locadora->filmes[j]));
                    ImprimirNomeFilme(locadora->filmes[j]);
                    printf(" Devolvido!\n");
                    locadora->lucro += ObterValorFilme(locadora->filmes[j]);
                    existe=0;
                    break;
                }
            }
        }
        if (existe)
        {
            printf("Filme %d nao cadastrado.\n", codigos[i]);
        }
    }
}

/**
 * @brief Lê os dados de devolução de um ou mais filmes e os devolve na locadora.
 *
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void LerDevolucaoLocadora(tLocadora *locadora)
{
    int cod, qtd = 0;
    int codigos[30];
    while (scanf(" %d ", &cod) == 1)
    {
        codigos[qtd] = cod;
        qtd++;
    }
    DevolverFilmesLocadora(locadora, codigos, qtd);
}

/**
 * @brief Ordena os filmes cadastrados na locadora por ordem alfabética.
 *
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void OrdenarFilmesLocadora(tLocadora *locadora)
{
    for (int i = 0; i < locadora->qtdfilmes; i++)
    {
        for (int j = i + 1; j < locadora->qtdfilmes; j++)
        {
            if (CompararNomesFilmes(locadora->filmes[i], locadora->filmes[j]) == 1)
            {
                tFilme *f = locadora->filmes[i];
                locadora->filmes[i] = locadora->filmes[j];
                locadora->filmes[j] = f;
            }
        }
    }
}

/**
 * @brief Consulta o estoque de filmes da locadora.
 *
 * @param locadora Ponteiro para a instância de tLocadora a ser consultada.
 */
void ConsultarEstoqueLocadora(tLocadora *locadora)
{
    printf("~ESTOQUE~\n");
    for (int i = 0; i < locadora->qtdfilmes; i++)
    {
        printf("%d - ", ObterCodigoFilme(locadora->filmes[i]));
        ImprimirNomeFilme(locadora->filmes[i]);
        printf(" Fitas em estoque: %d\n", ObterQtdEstoqueFilme(locadora->filmes[i]));
    }
}

/**
 * @brief Consulta o lucro da locadora.
 *
 * @param locadora Ponteiro para a instância de tLocadora a ser consultada.
 */
void ConsultarLucroLocadora(tLocadora *locadora)
{
    if (locadora->lucro > 0)
    {
        printf("\nLucro total R$%d\n", locadora->lucro);
    }
}