#include <stdio.h>
#include <stdlib.h>
#include "documento.h"
#include <string.h>
#include "receita.h"
#include "encaminhamento.h"
#include "exame.h"
#include "fila_imp.h"

int main()
{
    float precocaracter;
    scanf("%f", &precocaracter);
    char com[50];
    FilaImp *f = criaFilaImp();
    while (1)
    {
        scanf(" %[^\n] ", com);
        if (strcmp(com, "RECEITA") == 0)
        {
            Receita *r = leReceita();
            insereDocumentoFilaImp(f, r, imprimeReceita,
                                   desalocaReceita, calculaPrecoImpressaoReceita);
        }
        else if (strcmp(com, "EXAME") == 0)
        {
            Exame *r = leExame();
            insereDocumentoFilaImp(f, r, imprimeExame,
                                   desalocaExame, calculaPrecoImpressaoExame);
        }
        else if (strcmp(com, "ENCAMINHAMENTO") == 0)
        {
            Encaminhamento *r = leEncaminhamento();
            insereDocumentoFilaImp(f, r, imprimeEncaminhamento,
                                   desalocaEncaminhamento, calculaPrecoImpressaoEncaminhamento);
        }
        else if (strcmp(com, "FIM") == 0)
        {
            break;
        }
        else if (strcmp("IMPRIME", com) == 0)
        {
            imprimeFilaImp(f);
        }
        else if (strcmp("QUANTIDADE", com) == 0)
        {

                printf("- QUANTIDADE DE DOCUMENTOS NA FILA: %d\n", quantidadeDocumentosNaFilaImp(f));
            
        }
        else if (strcmp("PRECO", com) == 0)
        {


                printf("- PRECO TOTAL DA FILA: R$ %.2f\n", precoTotalImpressaoFilaImp(f, precocaracter));
            
        }
    }

    desalocaFilaImp(f);

    return 0;
}