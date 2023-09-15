#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//10) Receba o raio, calcule e apresente:
//a. O comprimento de uma esfera: C = 2 * π * R.
//b. A área de uma esfera: A = π * R2
//c. O volume de uma esfera: V = 3⁄4 * π * R3

int main()
{
    double comp,area,vol,raio, pi = 3.141592;

    printf("\nInsira o valor do raio do circulo: ");
    scanf("%lf",&raio);

    comp = 2*pi*raio ;
    area = pi*pow(raio,2);
    vol  = 0.75*pi*pow(raio,3);

    printf("\nSeu comprimento é:%lf\nSua area é:%lf\nSeu volume é:%lf ",comp,area,vol);

    return 0;
}
