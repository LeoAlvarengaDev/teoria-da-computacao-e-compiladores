#include <stdio.h>
#include <stdlib.h>
//2) Receba o ano de nascimento de uma pessoa, o ano atual e imprima:
//a. A idade da pessoa no ano atual.
//b. A idade que a pessoa terá em 2050.

void anoAtual();
void ano2050();

int main()
{

    anoAtual();
    ano2050();

    return 0;
}
void anoAtual()
{
    int anoNas,anoAt,idade;

    printf("\nInsira seu ano de nascimento: ");
    scanf("%d",&anoNas);

    printf("\nInsira o ano atual: ");
    scanf("%d",&anoAt);

    idade = anoAt-anoNas;

    printf("\nVoce tem %d anos",idade);
}

void ano2050()
{
    int anoNas,idade;

    printf("\nInsira seu ano de nascimento: ");
    scanf("%d",&anoNas);


    idade = 2050-anoNas;

    printf("\nVoce tera %d anos em 2050",idade);
}
