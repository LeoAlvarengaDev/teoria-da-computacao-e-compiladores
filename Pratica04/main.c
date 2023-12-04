#include <stdio.h>
#include <stdlib.h>

// Função recursiva para determinar o tamanho (comprimento) da string
int ComprimentoDaStringRecursiva(const char *str, int index) {
    if (str[index] == '\0') {
        return index;
    }
    return ComprimentoDaStringRecursiva(str, index + 1);
}

// Função recursiva para determinar o reverso da string
void StringReversaRecursiva(const char *str, char *result, int index) {
    if (str[index] == '\0') {
        result[index] = '\0';
        return;
    }

    StringReversaRecursiva(str, result, index + 1);
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
    int comprimento = ComprimentoDaStringRecursiva(str, 0);

    // Calcular o reverso da string recursivamente
    char invertida[100];
    StringReversaRecursiva(str, reversed, 0);

    // Abrir o arquivo novamente para escrever os resultados
    file = fopen("texto.txt", "w");
    if (file == NULL) {
        printf("Não foi possível abrir o arquivo para escrita.\n");
        return 1;
    }

    // Escrever o tamanho e o reverso da string no arquivo
    fprintf(file, "Tamanho da string: %d\n", comprimento);
    fprintf(file, "Reverso da string: %s\n", invertida);

    fclose(file);

    printf("Tamanho da string: %d\n", comprimento);
    printf("Reverso da string: %s\n", invertida);

    return 0;
}
