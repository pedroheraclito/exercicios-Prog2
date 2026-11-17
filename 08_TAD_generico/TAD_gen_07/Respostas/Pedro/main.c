#include <stdio.h>
#include <stdlib.h>
#include "histograma.h"

int main()
{
    int n;
    scanf("%d", &n);
    Imagem *img = LerImagem();
    Histograma *h = CalcularHistograma(img, n);
    MostrarHistograma(h);
    DestruirHistograma(h);
    DestruirImagem(img);

    return 0;
}