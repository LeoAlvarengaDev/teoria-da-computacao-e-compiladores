#include <stdio.h>
#include <stdlib.h>
//8) Receba o peso de uma pessoa, calcule e apresente o novo peso:
//a. Se a pessoa engordar 15%.
//b. Se a pessoa emagrecer 20%.

int main()
{
    double peso, eng,ema;
    printf("Informe seu peso:");
    scanf("%lf",&peso);

    eng = peso + (peso*0.15);
    ema = peso - (peso*0.20);

    printf("\nPeso caso engorde  15%: %.2f",eng);
    printf("\nPeso caso emagreca 20%: %.2f",ema);
    return 0;
}
