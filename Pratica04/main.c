#include <stdio.h>
#include <stdlib.h>

// Função recursiva para determinar o tamanho (comprimento) da string
int recursiveStringLength(const char *str, int index) {
    if (str[index] == '\0') {
        return index;
    }
    return recursiveStringLength(str, index + 1);
}

// Função recursiva para determinar o reverso da string
void recursiveReverseString(const char *str, char *result, int index) {
    if (str[index] == '\0') {
        result[index] = '\0';
        return;
    }

    recursiveReverseString(str, result, index + 1);
    result[strlen(str) - index - 1] = str[index];
}

int main() {
    FILE *file = fopen("texto.txt", "r");
    if (file == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        return 1;
    }

    // Ler a string do arquivo
    char str[100];
    fgets(str, sizeof(str), file);
    fclose(file);

    // Calcular o tamanho da string recursivamente
    int length = recursiveStringLength(str, 0);

    // Calcular o reverso da string recursivamente
    char reversed[100];
    recursiveReverseString(str, reversed, 0);

    // Abrir o arquivo novamente para escrever os resultados
    file = fopen("texto.txt", "w");
    if (file == NULL) {
        printf("Não foi possível abrir o arquivo para escrita.\n");
        return 1;
    }

    // Escrever o tamanho e o reverso da string no arquivo
    fprintf(file, "Tamanho da string: %d\n", length);
    fprintf(file, "Reverso da string: %s\n", reversed);

    fclose(file);

    printf("Tamanho da string: %d\n", length);
    printf("Reverso da string: %s\n", reversed);

    return 0;
}
