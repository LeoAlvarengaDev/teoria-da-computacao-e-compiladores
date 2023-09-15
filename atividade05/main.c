#include <stdio.h>
#include <stdlib.h>

//5) Calcule e apresente a área de um losango. As diagonais maior e menor do losango
//devem ser informadas pelo usuário. OBS: AREA = (DIAGONAL MAIOR * DIAGONAL MENOR) / 2.

int main()
{
    double menor, maior,area;

    printf("\nInsira a diagonal Maior: ");
    scanf("%lf",&maior);

    printf("\nInsira a diagonal Menor: ");
    scanf("%lf",&menor);

    area = (maior+menor)/2;

    printf("\nA area do Losando é de: %lf",area);

    return 0;
}
