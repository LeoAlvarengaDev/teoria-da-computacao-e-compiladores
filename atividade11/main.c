#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,i;
    printf("\nInforme um numero: ");
    scanf("%d",&x);

    for(i=0;i<=10;i++)
        printf("%d X %d = %d\n",x,i,x*i);

    return 0;
}
