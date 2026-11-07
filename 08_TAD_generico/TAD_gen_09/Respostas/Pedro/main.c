#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "exame.h"
#include "encaminhamento.h"
#include "receita.h"
#include "fila_imp.h"
#include "documento.h"

int main()
{
    float precocaracter = 0;
    char cod[50];
    scanf("%f", &precocaracter);
    FilaImp *f = criaFilaImp();
    scanf(" %[^\n]\n", cod);

    while (1)
    {
        if (strcmp(cod, "RECEITA") == 0)
        {
            Receita *r = leReceita();
            insereDocumentoFilaImp(f, r, imprimeReceita, desalocaReceita, calculaPrecoImpressaoReceita);
        }
        else if (strcmp(cod, "EXAME") == 0)
        {
            exame *r = leexame();
            insereDocumentoFilaImp(f, r, imprimeexame, desalocaexame, calculaPrecoImpressaoexame);
        }
        else if (strcmp(cod, "ENCAMINHAMENTO") == 0)
        {
            encaminho *r = leencaminho();
            insereDocumentoFilaImp(f, r, imprimeencaminho, desalocaencaminho, calculaPrecoImpressaoencaminho);
        }
        else if (strcmp(cod, "QUANTIDADE") == 0)
        {
            printf("- QUANTIDADE DE DOCUMENTOS NA FILA: %d\n",quantidadeDocumentosNaFilaImp(f));
        }
        else if (strcmp(cod, "PRECO") == 0)
        {
            printf("- PRECO TOTAL DA FILA: R$ %.2f\n",precoTotalImpressaoFilaImp(f,precocaracter));
        }
        else if (strcmp(cod, "IMPRIME") == 0)
        {
           imprimeFilaImp(f);
        }
        else if (strcmp(cod, "FIM") == 0)
        {
            break;
        }

        scanf(" %[^\n]\n", cod);
    }
    desalocaFilaImp(f);

    return 0;
}