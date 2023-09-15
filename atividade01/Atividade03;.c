#include <stdio.h>
#include <stdlib.h>

int main()
{
    double dollar,usu,real;

    printf("\nInforme a cotacao do dollar");
    scanf("%d",&dollar);

    printf("\nInforme quantos dollars voce tem : ");
    scanf("%d",&usu);

    real = usu*dollar;

    printf("\nVoce tem R$%.2f",real)
    return 0;
}
