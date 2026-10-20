#include <stdio.h>
#include <stdlib.h>
#include "circulo.h"

int main()
{
    float x_centro, y_centro, raio, p_x, p_y;
    int resultado;
    scanf("%f %f %f %f %f", &x_centro, &y_centro, &raio, &p_x, &p_y);
    tCirculo *circulo=Circulo_Cria(x_centro, y_centro, raio);
    tPonto *ponto=Pto_Cria (p_x,p_y);
    resultado=Circulo_Interior(circulo,ponto);
    printf("%d",resultado);
    Pto_Apaga(ponto);
    Circulo_Apaga(circulo);
    return 0;
}