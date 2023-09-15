#include <stdio.h>
#include <stdlib.h>

//6) Receba uma temperatura em Celsius, calcule e mostre essa temperatura em Fahrenheit.
//OBS: F = (C * 1,8) + 32.

int main()
{
    double c,f;

    printf("\nInsira a temperatura em Celsius: ");
    scanf("%lf",&c);

    f = c*1.8 + 32;

    printf("\nA temperatura em Fahrenheit é: %lf ",f);
}
