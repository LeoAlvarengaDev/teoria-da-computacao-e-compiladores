#include <stdio.h>
#include <stdlib.h>
//Reconhecimento de números naturais.
void automato1() {
    int a, erro;
    char estado = '0';
    char estadoAnt = '0';

    while (1) {
        erro = 0;
        printf("\nEntre com os dados:");

        while ((a = getchar()) != '\n') {
            switch (estado) {
                case '0':
                    if (a == '0') {
                        estado = '0';
                    } else if (a == '1') {
                        estado = '1';
                    } else {
                        erro = 1;
                    }
                    break;
                case '1':
                    if (a == '0') {
                        estado = '3';
                    } else if (a == '1') {
                        estado = '2';
                    } else {
                        erro = 1;
                    }
                    break;
                case '2':
                    if (a == '0') {
                        estado = '2';
                    } else if (a == '1') {
                        estado = '3';
                    } else {
                        erro = 1;
                    }
                    break;
                case '3':
                    if (a == '0' || a == '1') {
                        estado = '3';
                    } else {
                        erro = 1;
                    }
                    break;
                default:
                    erro = 1;
                    break;
            }
        }

        if (erro == 0) {
            printf("\nTransicao de estado de q%c -> q%c", estadoAnt, estado);
        } else {
            printf("\nEstado de erro.");
        }

        printf("\n\nTecle <ENTER> para continuar.");
        getchar();
        system("clear || cls");

        estadoAnt = estado;
    }
}

void automato2() {
    int a, erro;
    char estado = '0';
    char estadoAnt = '0';

    while (1) {
        erro = 0;
        printf("\nEntre com os dados:");

        while ((a = getchar()) != '\n') {
            switch (estado) {
                case '0':
                    if (a == 'a') {
                        estado = '1';
                    } else if (a == 'b') {
                        estado = '3';
                    } else {
                        erro = 1;
                    }
                    break;
                case '1':
                    if (a == 'a') {
                        estado = '5';
                    } else if (a == 'b') {
                        estado = '2';
                    } else {
                        erro = 1;
                    }
                    break;
                case '2':
                    if (a == 'a') {
                        estado = '1';
                    } else if (a == 'b') {
                        estado = '2';
                    } else {
                        erro = 1;
                    }
                    break;
                case '3':
                    if (a == 'a') {
                        estado = '4';
                    } else if (a == 'b') {
                        estado = '3';
                    } else {
                        erro = 1;
                    }
                    break;
                case '4':
                    if (a == 'a') {
                        estado = '5';
                    } else if (a == 'b') {
                        estado = '3';
                    } else {
                        erro = 1;
                    }
                    break;
                case '5':
                    if (a == 'a' || a == 'b') {
                        estado = '5';
                    } else {
                        erro = 1;
                    }
                    break;
                default:
                    erro = 1;
                    break;
            }
        }

        if (erro == 0) {
            printf("\nTransicao de estado de q%c -> q%c", estadoAnt, estado);
        } else {
            printf("\nEstado de erro.");
        }

        printf("\n\nTecle <ENTER> para continuar.");
        getchar();
        system("clear || cls");

        estadoAnt = estado;
    }
}

void automato3() {
    int a, erro;
    char estado = '0';
    char estadoAnt = '0';

    while (1) {
        erro = 0;
        printf("\nEntre com os dados:");

        while ((a = getchar()) != '\n') {
            switch (estado) {
                case '0':
                    if (a == '0') {
                        estado = '1';
                    } else if (a == '1') {
                        estado = '0';
                    } else {
                        erro = 1;
                    }
                    break;
                case '1':
                    if (a == '0') {
                        estado = '2';
                    } else if (a == '1') {
                        estado = '1';
                    } else {
                        erro = 1;
                    }
                    break;
                case '2':
                    if (a == '0') {
                        estado = '3';
                    } else if (a == '1') {
                        estado = '2';
                    } else {
                        erro = 1;
                    }
                    break;
                case '3':
                    if (a == '0' || a == '1') {
                        estado = '3';
                    } else {
                        erro = 1;
                    }
                    break;
                default:
                    erro = 1;
                    break;
            }
        }

        if (erro == 0) {
            printf("\nTransicao de estado de q%c -> q%c", estadoAnt, estado);
        } else {
            printf("\nEstado de erro.");
        }

        printf("\n\nTecle <ENTER> para continuar.");
        getchar();
        system("clear || cls");

        estadoAnt = estado;
    }
}

void automato4() {
    int a, erro;
    char estado = '0';
    char estadoAnt = '0';

    while (1) {
        erro = 0;
        printf("\nEntre com os dados:");

        while ((a = getchar()) != '\n') {
            switch (estado) {
                case '0':
                    if (a == 'a') {
                        estado = '1';
                    } else if (a == 'b') {
                        estado = '3';
                    } else {
                        erro = 1;
                    }
                    break;
                case '1':
                    if (a == 'a') {
                        estado = '5';
                    } else if (a == 'b') {
                        estado = '2';
                    } else {
                        erro = 1;
                    }
                    break;
                case '2':
                    if (a == 'a') {
                        estado = '1';
                    } else if (a == 'b') {
                        estado = '2';
                    } else {
                        erro = 1;
                    }
                    break;
                case '3':
                    if (a == 'a') {
                        estado = '4';
                    } else if (a == 'b') {
                        estado = '3';
                    } else {
                        erro = 1;
                    }
                    break;
                case '4':
                    if (a == 'a') {
                        estado = '5';
                    } else if (a == 'b') {
                        estado = '3';
                    } else {
                        erro = 1;
                    }
                    break;
                case '5':
                    if (a == 'a' || a == 'b') {
                        estado = '5';
                    } else {
                        erro = 1;
                    }
                    break;
                default:
                    erro = 1;
                    break;
            }
        }

        if (erro == 0) {
            printf("\nTransicao de estado de q%c -> q%c", estadoAnt, estado);
        } else {
            printf("\nEstado de erro.");
        }

        printf("\n\nTecle <ENTER> para continuar.");
        getchar();
        system("clear || cls");

        estadoAnt = estado;
    }
}

void automato5() {
    int a, erro;
    char estado = '0';
    char estadoAnt = '0';

    while (1) {
        erro = 0;
        printf("\nEntre com os dados:");

        while ((a = getchar()) != '\n') {
            switch (estado) {
                case '0':
                    if (a == '0') {
                        estado = '1';
                    } else if (a == '1') {
                        estado = '2';
                    } else {
                        erro = 1;
                    }
                    break;
                case '1':
                    if (a == '1') {
                        estado = '3';
                    } else if (a == '0') {
                        estado = '0';
                    } else {
                        erro = 1;
                    }
                    break;
                case '2':
                    if (a == '1') {
                        estado = '0';
                    } else if (a == '0') {
                        estado = '3';
                    } else {
                        erro = 1;
                    }
                    break;
                case '3':
                    if (a == '0' || a == '1') {
                        estado = '3';
                    } else {
                        erro = 1;
                    }
                    break;
                default:
                    erro = 1;
                    break;
            }
        }

        if (erro == 0) {
            printf("\nTransicao de estado de q%c -> q%c", estadoAnt, estado);
        } else {
            printf("\nEstado de erro.");
        }

        printf("\n\nTecle <ENTER> para continuar.");
        getchar();
        system("clear || cls");

        estadoAnt = estado;
    }
}

int main() {
  // automato1();
  // automato2();
  // automato3();
  // automato4();
  automato5();
}

