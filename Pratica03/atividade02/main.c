#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,n;

    printf("Informe os numeros a serem somados: ");
    scanf("%d", &m);
    scanf("%d", &n);

    somaSucessor(m,n);
    printf("\n");
    printSucessor(m);
    printf(" + ");
    printSucessor(n);
    printf(" = ");
    printSucessor(n+m);
    return 0;
}
void  somaSucessor( int m ,int n){

    printf("%d + %d = %d",m,Sucessor(n),Sucessor(m+n));

}

void Sucessor(int n){
        if(n == 0){
            return 0;
        }else if(n == 1){
            return 1;
        }else if (n > 1){
            return n+1;
        }else{
            return Sucessor(n-1);
        }

}

void printSucessor(int n){

        if (n == 0) {
        printf("0");
    } else if (n > 0) {
        printf("s(");
        for (int i = 0; i < n; i++) {
            printf("s(");
        }
        printf("0");
        for (int i = 0; i < n; i++) {
            printf(")");
        }
    } else {
        printf("Erro: Não definido para números negativos.");
    }
}

