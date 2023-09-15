#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void checaLetra( char texto);
void checaDigito(char texto);
void checaMaiusculo( char texto);
void checaMinusculo( char texto);
void checaDigitoELetra( char texto);

int main()
{
    char texto = 'A';

    checaLetra(texto);
    printf("\n");
    checaDigito(texto);
    printf("\n");
    checaMaiusculo(texto);
    printf("\n");
    checaMinusculo(texto);
    printf("\n");
    checaDigitoELetra(texto);
    printf("\n");
    return 0;

}

void checaLetra( char texto){

    if (isalpha(texto)) {
        printf("'%c' E uma letra.", texto);
    }else{
        printf("'%c'Nao e uma letra.", texto);
    }

}

void checaDigito( char texto){

    if (isdigit(texto)) {
        printf("'%c' E um digito.",texto);
    }else{
        printf("'%c' Nao e um digito.",texto);
    }

}

void checaMaiusculo( char texto){

    if (isupper(texto)) {
        printf("'%c' E uma letra maiuscula.",texto);
    }else{
        printf("'%c' Nao e uma letra maiuscula.",texto);
    }

}

void checaMinusculo( char texto){

    if (islower(texto)) {
        printf("'%c' E uma letra minuscula.",texto);
    }else{
        printf("'%c' Nao e uma letra minuscula.",texto);
    }

}

void checaDigitoELetra( char texto){

    if (isalnum(texto)) {
        printf("'%c' E um digito ou uma letra.",texto);
    }else{
        printf("'%c' Nao e um digito ou uma letra.",texto);
    }

}
