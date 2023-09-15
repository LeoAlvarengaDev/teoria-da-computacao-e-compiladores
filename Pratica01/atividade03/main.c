#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//3) Receba a cotação do dólar em reais e um valor que o usuário possui em dólares.
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
