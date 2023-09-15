#include <stdio.h>
#include <stdlib.h>

//4) Faça um programa que receba o salário de um funcionário, calcule e mostre o novo
//salário, sabendo-se que ele teve um aumento de 25%.

int main()
{
    float salario,aumento;

    printf("\nInforme seu salario: ");
    scanf("%f",&salario);

    aumento = salario + (salario * 25)/100;
    printf("\n Seu novo salario é de: %.2f",aumento);


    return 0;
}
