#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//9) Receba os valores dos dois catetos de um triângulo, calcule e apresente o valor da
//hipotenusa. OBS - Teorema de Pitágoras: a2 = b2 + c2.

int main()
{
    double cat1,cat2,hip,soma;

    printf("\nInforme os dois catetos do triangulo:");
    scanf("%lf",&cat1);scanf("%lf",&cat2);

    soma = pow(cat1,2) + pow(cat2,2);
    hip = sqrt(soma);

    printf("\nO valor da hipotenusa é de: %lf",hip);
    return 0;
}
