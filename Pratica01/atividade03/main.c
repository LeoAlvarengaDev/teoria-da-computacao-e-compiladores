#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//3) Receba a cota��o do d�lar em reais e um valor que o usu�rio possui em d�lares.
//Imprima este valor em reais.

int main()
{
    double dollar,usu,real;

    printf("\nInforme a cotacao do dollar: ");
    scanf("%lf",&dollar);

    printf("\nInforme quantos dollars voce tem : ");
    scanf("%lf",&usu);

    real = usu*dollar;

    printf("\nVoce tem R$%.2f",real);
    return 0;
}
