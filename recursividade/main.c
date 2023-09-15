#include <stdio.h>
#include <stdlib.h>
int potencia(int x, int y){
    if( y == 1){
        return x;
    } else if (y == 0){
        return 1;
    }else{
        return x * potencia(x, y - 1);
    }
}
int somaNaturais(int n){
    if(n == 1){
        return 1;
    }else if (n == 0){
        return 0;
    }else{
        return n + somaNaturais(n-1);
    }
}
int main()
{
    int x , y , resultado;
    x = 3;
    y = 5;
    resultado = potencia(x,y);

    printf("O resulatdo de %d elevado a %d e %d", x,y,resultado);

    resultado = somaNaturais(y);

    printf("\nO resulatdo da soma dos numeros naturais  de 1 ate %d e %d",y,resultado);
    return 0;
}
