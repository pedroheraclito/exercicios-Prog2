#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "exame.h"
#include "encaminhamento.h"
#include "receita.h"
#include "fila_imp.h"
#include "documento.h"


int main(){
 float precocaracter=0;
 char cod[50];
 scanf("%f",&precocaracter);
 FilaImp *f=criaFilaImp();
    scanf(" %[\n]",cod);

    while (1)
    {
        if (strcmp(cod,"RECEITA")==0)
        {
            Receita *r=leReceita();
            insereDocumentoFilaImp(f, r, imprimeReceita,desalocaReceita,calculaPrecoImpressaoReceita);
        }else if (strcmp(cod,"EXAME")==0)
        {
            Receita *r=leReceita();
            insereDocumentoFilaImp(f, r, imprimeReceita,desalocaReceita,calculaPrecoImpressaoReceita);
        }else if (strcmp(cod,"ENCAMINHAMENTO")==0)
        {
            /* code */
        }
        
        scanf(" %[\n]",cod);
    }
    





    return 0;
}