#include <stdio.h>
#include <stdlib.h>

//4) Fa�a um programa que receba o sal�rio de um funcion�rio, calcule e mostre o novo
//sal�rio, sabendo-se que ele teve um aumento de 25%.

int main()
{
    float salario,aumento;

    printf("\nInforme seu salario: ");
    scanf("%f",&salario);

    aumento = salario + (salario * 25)/100;
    printf("\n Seu novo salario � de: %.2f",aumento);


    return 0;
}
