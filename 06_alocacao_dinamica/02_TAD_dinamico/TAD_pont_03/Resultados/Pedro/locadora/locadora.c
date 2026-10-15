#include <stdio.h>
#include <stdlib.h>
#include "locadora.h"
#include <string.h>

/**
 * @brief Cria uma nova instância de tLocadora e inicializa filme como NULL, numFilmes como 0 e lucro como 0.
 *
 * @return tLocadora* Ponteiro para a nova instância de tLocadora criada ou encerra o programa caso não haja memória suficiente.
 */
tLocadora *CriarLocadora()
{
    tLocadora *locadora = calloc(1, sizeof(tLocadora));
    locadora->filme = NULL;
    locadora->numFilmes = 0;
    locadora->lucro = 0;
    return locadora;
}

/**
 * @brief Destrói uma instância de tLocadora.
 *
 * @param locadora Ponteiro para a instância de tLocadora a ser destruída.
 */
void DestruirLocadora(tLocadora *locadora)
{
    for (int i = 0; i < locadora->numFilmes; i++)
    {
        DestruirFilme(locadora->filme[i]);
    }
    free(locadora->filme);
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
    for (int i = 0; i < locadora->numFilmes; i++)
    {
        if (codigo == ObterCodigoFilme(locadora->filme[i]))
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
        locadora->filme = realloc(locadora->filme, (locadora->numFilmes + 1) * sizeof(tFilme *));
        locadora->filme[locadora->numFilmes] = filme;
        printf("Filme cadastrado %d - ", ObterCodigoFilme(locadora->filme[locadora->numFilmes]));
        ImprimirNomeFilme(locadora->filme[locadora->numFilmes]);
        printf("\n");
        locadora->numFilmes++;
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
    while (scanf("%d,", &codigo) == 1)
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
    int cont = 0, dinheiro = 0, qtd = 0;
    ;
    for (int i = 0; i < quantidadeCodigos; i++)
    {
        for (int i2 = 0; i2 < locadora->numFilmes; i2++)
        {
            if (EhMesmoCodigoFilme(locadora->filme[i2], codigos[i]))
            {
                if (ObterQtdEstoqueFilme(locadora->filme[i2]) != 0)
                {
                    dinheiro += ObterValorFilme(locadora->filme[i2]);
                    qtd++;
                    AlugarFilme(locadora->filme[i2]);
                }
                else
                {
                    printf("Filme %d - ", ObterCodigoFilme(locadora->filme[i2]));
                    ImprimirNomeFilme(locadora->filme[i2]);
                    printf(" nao disponivel no estoque. Volte mais tarde.\n");
                }

                cont = 1;
            }
        }
        if (cont == 0)
        {
            printf("Filme %d nao cadastrado.\n", codigos[i]);
        }

        cont = 0;
    }

    if (dinheiro != 0)
    {
        printf("Total de filmes alugados: %d com custo de R$%d\n", qtd, dinheiro);
    }
}

/**
 * @brief Lê o aluguel de um conjunto de filmes a partir da entrada padrão e os aluga na locadora.
 *
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void LerAluguelLocadora(tLocadora *locadora)
{
    int codigos[20];
    int i = 0;
    while (scanf("%d", &codigos[i]) == 1 && i < 20)
    {
        i++;
    }
    scanf("%*c");
    AlugarFilmesLocadora(locadora, codigos, i);
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
    int cadastrado = 0;
    for (int i = 0; i < quantidadeCodigos; i++)
    {
        for (int i2 = 0; i2 < locadora->numFilmes; i2++)
        {
            if (EhMesmoCodigoFilme(locadora->filme[i2], codigos[i]))
            {
                if (ObterQtdAlugadaFilme(locadora->filme[i2]))
                {
                    locadora->lucro = locadora->lucro + ObterValorFilme(locadora->filme[i2]);
                    DevolverFilme(locadora->filme[i2]);
                    printf("Filme %d - ", ObterCodigoFilme(locadora->filme[i2]));
                    ImprimirNomeFilme(locadora->filme[i2]);
                    printf(" Devolvido!\n");
                }
                else
                {
                    printf("Nao e possivel devolver o filme %d - ", ObterCodigoFilme(locadora->filme[i2]));
                    ImprimirNomeFilme(locadora->filme[i2]);
                    printf(".\n");
                }
                cadastrado = 1;
            }
        }
        if (cadastrado == 0)
        {
            printf("Filme %d nao cadastrado.\n", codigos[i]);
        }
        cadastrado = 0;
    }
}

/**
 * @brief Lê os dados de devolução de um ou mais filmes e os devolve na locadora.
 *
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void LerDevolucaoLocadora(tLocadora *locadora)
{
    int codigos[20];
    int i = 0;
    while (scanf("%d", &codigos[i]) == 1 && i < 20)
    {
        i++;
    }
    scanf("%*c");
    DevolverFilmesLocadora(locadora, codigos, i);
}

/**
 * @brief Ordena os filmes cadastrados na locadora por ordem alfabética.
 *
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void OrdenarFilmesLocadora(tLocadora *locadora)
{
    for (int i = 0; i < locadora->numFilmes; i++)
    {
        for (int i2 = i + 1; i2 < locadora->numFilmes; i2++)
        {
            if (CompararNomesFilmes(locadora->filme[i], locadora->filme[i2]) == 1)
            {
                tFilme *temp = locadora->filme[i];
                locadora->filme[i] = locadora->filme[i2];
                locadora->filme[i2] = temp;
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
    OrdenarFilmesLocadora(locadora);
    for (int i = 0; i < locadora->numFilmes; i++)
    {
        printf("%d - ", ObterCodigoFilme(locadora->filme[i]));
        ImprimirNomeFilme(locadora->filme[i]);
        printf(" Fitas em estoque: %d\n", ObterQtdEstoqueFilme(locadora->filme[i]));
    }
}

/**
 * @brief Consulta o lucro da locadora.
 *
 * @param locadora Ponteiro para a instância de tLocadora a ser consultada.
 */
void ConsultarLucroLocadora(tLocadora *locadora)
{
    if (locadora->lucro != 0)
    {
        printf("\n");
        printf("Lucro total R$%d\n", locadora->lucro);
    }
}