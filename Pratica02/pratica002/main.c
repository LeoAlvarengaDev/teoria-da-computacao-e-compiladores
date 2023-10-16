#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Função para ler a sequência de números do usuário e escrevê-la em um arquivo
int lerSequencia(FILE **arq, const char *nomeArquivo);

// Função para mostrar o conteúdo do arquivo na tela
void mostrarConteudoArquivo(const char *nomeArquivo);

// Função para extrair números do arquivo de texto e armazená-los em um vetor
void extrairNumeros(const char *nomeArquivo, int vet[]);

// Função para organizar e apresentar os números armazenados no vetor
void organizarApresentarVetor(int vet[], int tam);

// Função para criar Conjuntos a partir de vetores e escrevê-los em um arquivo.
void criarConjuntos(FILE **arq, const char *nomeArquivo, int vetA[], int vetB[], int tamA, int tamB);

// Função para mostrar os conjuntos criados a partir dos vetores
void apresentarConjuntos(const char *nomeArquivo);

// Função para calcular a potência de um conjunto
void calcularPotencia(int vet[], int x, const char letra, const char *nomeArquivo);

// Esta função gera todos os subconjuntos de um conjunto representado por um vetor 'vet'.
void conjuntosProprios(char letra, const char *nomeArquivo, int x, const int vet[]);

// Esta função calcula a união de dois conjuntos representados por vetores 'vetA' e 'vetB'.
void uniaoConjuntos(int vetA[], int vetB[], int tamA, int tamB, const char *nomeArquivo);

// Esta função calcula a interseção de dois conjuntos representados por vetores 'vetA' e 'vetB'.
void intersecao(int vetA[], int vetB[], int tamA, int tamB, const char *nomeArquivo);

// Esta função calcula a diferença entre dois conjuntos representados por vetores 'vet_01' e 'vet_02'.
void diferenca(int vet_01[],int vet_02[],int tam_01,int tam_02, const char *nomeArquivo, char a , char b);

// Esta função calcula o produto cartesiano entre dois conjuntos representados por vetores 'vet_01' e 'vet_02'.
void produtoCartesiano(int vet_01[], int vet_02[], int tam_01, int tam_02, const char *nomeArquivo, char a, char b);

int main() {
    FILE *arq;
    int n, contA = 0, contB = 0;
    char a = 'A', b = 'B';
    const char *nomeArquivo = "Naturais.txt";

    printf("\nInforme uma sequencia de numeros Naturais\n");
    // Chama a função lerSequencia para obter números do usuário e escrevê-los no arquivo
    contA = lerSequencia(&arq, nomeArquivo);

    // Cria um vetor com base no contador
    int vetA[contA];

    // Mostra o conteúdo do arquivo na tela
    mostrarConteudoArquivo(nomeArquivo);

    // Extrai os números do arquivo e armazena no vetor
    extrairNumeros(nomeArquivo, vetA);

    // Organiza e apresenta os números no vetor
    organizarApresentarVetor(vetA, contA);

    printf("\nInforme uma segunda sequencia de numeros Naturais\n");
    // Chama a função lerSequencia para obter números do usuário e escrevê-los no arquivo
    contB = lerSequencia(&arq, nomeArquivo);

    // Cria um vetor com base no contador
    int vetB[contB];

    // Mostra o conteúdo do arquivo na tela
    mostrarConteudoArquivo(nomeArquivo);

    // Extrai os números do arquivo e armazena no vetor
    extrairNumeros(nomeArquivo, vetB);

    // Organiza e apresenta os números no vetor
    organizarApresentarVetor(vetB, contB);

    // Cria dois conjuntos a partir dos vetores A, B
    criarConjuntos(&arq, nomeArquivo, vetA, vetB, contA, contB);

    // Apresenta os conjuntos gerados pelos vetores A, B
    apresentarConjuntos(nomeArquivo);

    // Calculando as Potências dos conjuntos A e B.
    calcularPotencia(vetA, contA, a, nomeArquivo);
    calcularPotencia(vetB, contB, b, nomeArquivo);

    conjuntosProprios(a,nomeArquivo,contA,vetA);
    conjuntosProprios(b,nomeArquivo,contB,vetB);

    uniaoConjuntos(vetA, vetB, contA, contB, nomeArquivo);

    intersecao(vetA, vetB, contA, contB, nomeArquivo);

    //Calculando a difrença entre A e B
    diferenca(vetA,vetB,contA,contB,nomeArquivo,a,b);

    //Calculando diferença entre B e A.
    diferenca(vetB,vetA,contB,contA,nomeArquivo,b,a);

    produtoCartesiano(vetA,vetB,contA,contB,nomeArquivo,a,b);

    produtoCartesiano(vetB,vetA,contB,contA,nomeArquivo,b,a);
    return 0;
}

// Função para ler a sequência de números do usuário e escrevê-la em um arquivo
int lerSequencia(FILE **arq, const char *nomeArquivo) {
    *arq = fopen(nomeArquivo, "w");
    int resp, n, cont = 0;
    char a = '}';
    if (*arq == NULL) {
        printf("\nErro ao abrir o arquivo %s\n", nomeArquivo);
        system("pause");
        exit(1);
    }

    printf("\nInforme um numero: \n");
    scanf("%d", &n);
    fprintf(*arq, "%d", n);
    cont++;

    printf("\nDeseja inserir mais numeros:\n1 -> Sim \n2 -> Nao\n");
    scanf("%d", &resp);

    if (resp != 2) {
        do {
            printf("\nInforme um numero: \n");
            scanf("%d", &n);
            fprintf(*arq, ",%d", n);

            printf("\nDeseja inserir mais numeros:\n1 -> Sim \n2 -> Nao\n");
            scanf("%d", &resp);

            cont++; // Incrementa o contador

        } while (resp != 2);
    }
    fclose(*arq);
    return cont;
}

// Função para mostrar o conteúdo do arquivo na tela
void mostrarConteudoArquivo(const char *nomeArquivo) {
    FILE *arq = fopen(nomeArquivo, "r");
    if (arq == NULL) {
        printf("\nErro ao abrir o arquivo %s\n", nomeArquivo);
        return;
    }
    printf("\nSequencia informada\n");
    char ch;
    while ((ch = fgetc(arq)) != EOF) {
        putchar(ch);
    }

    fclose(arq);
}

// Função para extrair números do arquivo de texto e armazená-los em um vetor
void extrairNumeros(const char *nomeArquivo, int vet[]) {
    FILE *arq = fopen(nomeArquivo, "r");
    int i = 0;
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
        return;
    }

    char linha[256]; // Tamanho máximo da linha
    char *token;

    while (fgets(linha, sizeof(linha), arq) != NULL) {
        token = strtok(linha, ","); // Divide a linha em tokens com base em '{', '}', e ','

        while (token != NULL) {
            int numero = atoi(token); // Converte o token para um número inteiro

            if (numero >= 0) {
                vet[i] = numero; // Inserindo o numero no vetor
                i++;
            }

            token = strtok(NULL, "{},"); // Obtém o próximo token
        }
    }

    fclose(arq);
}

// Função para organizar e apresentar os números armazenados no vetor
void organizarApresentarVetor(int vet[],int tam) {
    int acc;
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < tam; j++) {
            if (vet[i] < vet[j]) {
                acc = vet[i];
                vet[i] = vet[j];
                vet[j] = acc;
            }
        }
    }

    printf("\nVetor formado\n[");
    for (int i = 0; i < tam; i++) {
        printf("%d-", vet[i]);
    }
    printf("]\n");
}

// Função para criar Conjuntos apartir de vetores e escrevê-los em um arquivo.
void criarConjuntos(FILE **arq, const char *nomeArquivo, int vetA[], int vetB[], int tamA, int tamB) {
    // Abre o arquivo especificado para escrita
    arq = fopen(nomeArquivo, "w");

    // Verifica se o arquivo foi aberto com sucesso
    if (arq == NULL) {
        printf("\nErro ao abrir o arquivo.txt");
        system("pause");
        exit(1);
    }

    char a = '}'; // Define o caractere de fechamento do conjunto
    char b = '{'; // Define o caractere de abertura do conjunto

    // Escreve o caractere de abertura do conjunto no arquivo
    fprintf(arq, "%c", b);

    // Loop para percorrer o vetor vetA e escrever seus elementos no arquivo
    for (int i = 0; i < tamA; i++) {
        if (i == 0) {
            // Se for o primeiro elemento, escreve-o sem vírgula de separação
            fprintf(arq, "%d", vetA[i]);
        } else {
            // Se não for o primeiro elemento e for diferente do anterior, escreve-o com vírgula
            if (vetA[i - 1] != vetA[i]) {
                fprintf(arq, ",%d", vetA[i]);
            }
        }
    }

    // Escreve o caractere de fechamento do conjunto no arquivo
    fprintf(arq, "%c ", a);

    // Escreve o caractere de abertura do conjunto no arquivo
    fprintf(arq, "%c", b);

    // Loop para percorrer o vetor vetB e escrever seus elementos no arquivo
    for (int i = 0; i < tamB; i++) {
        if (i == 0) {
            // Se for o primeiro elemento, escreve-o sem vírgula de separação
            fprintf(arq, "%d", vetB[i]);
        } else {
            // Se não for o primeiro elemento e for diferente do anterior, escreve-o com vírgula
            if (vetB[i - 1] != vetB[i]) {
                fprintf(arq, ",%d", vetB[i]);
            }
        }
    }

    // Escreve o caractere de fechamento do conjunto no arquivo
    fprintf(arq, "%c", a);

    // Fecha o arquivo
    fclose(arq);
}

// Função para mostrar os conjutos criados apartir dos vetores
void apresentarConjuntos(const char *nomeArquivo){

    FILE *arq = fopen(nomeArquivo, "r");
    if (arq == NULL) {
        printf("\nErro ao abrir o arquivo %s\n", nomeArquivo);
        return;
    }
    printf("\nConjuntos Criados apartir das sequencias\n");
    char ch;
    printf("A:");
    do{
        ch = fgetc(arq);
        printf("%c", ch);
        if(ch == ' '){
            printf("\nB:");
        }
    }while(ch != EOF);

    fclose(arq);
}

// Função para calcular a potência de um conjunto
void calcularPotencia(int vet[], int x,char letra,const char *nomeArquivo) {
    char vir = ',';
    FILE *arq = fopen(nomeArquivo, "a");

    if (arq == NULL) {
        printf("\nErro ao abrir o arquivo %s\n", nomeArquivo);
        return;
    }


    printf("\nP(%c):",letra);
    fprintf(arq, "\nP(%c):", letra);

    for (int i = 0; i < (1 << x); i++) { // Loop para gerar os subconjuntos
        printf("{");
        fprintf(arq,"{");
        int primeiro = 1;
        for (int j = 0; j < x; j++) {
            if ((i & (1 << j)) != 0) {
                if (!primeiro) {
                    printf(",");
                    fprintf(arq, "%c", vir);
                }
                printf("%d", vet[j]);
                fprintf(arq, "%d", vet[j]);
                primeiro = 0;
            }
        }
        printf("}");
        fprintf(arq, "%}");
        if (i != (1 << x) - 1) {
            printf(",");
            printf(arq, "%c", vir);
        }
    }

    printf("\n");
    printf(arq, "\n");
}

// Esta função gera todos os subconjuntos de um conjunto representado por um vetor 'vet'.
void conjuntosProprios(char letra, const char *nomeArquivo, int x, const int vet[]) {
    // Abre o arquivo 'nomeArquivo' para escrita no modo "append" (acrescentar ao final do arquivo).
    FILE *arq = fopen(nomeArquivo, "a");

    // Verifica se o arquivo foi aberto com sucesso.
    if (arq == NULL) {
        printf("\nErro ao abrir o arquivo %s\n", nomeArquivo);
        return;
    }

    // Imprime no console e escreve no arquivo a letra identificadora.
    printf("\n%c:", letra);
    fprintf(arq, "\nc:", letra);

    // Loop para gerar os subconjuntos.
    for (int i = 0; i < (1 << x); i++) {
        int primeiro = 1;

        for (int j = 0; j < x; j++) {
            if ((i & (1 << j)) != 0) {
                if (!primeiro) {
                    printf(",");
                    fprintf(arq, "%c", ',');
                } else {
                    printf("{");
                    fprintf(arq, "{");
                }
                printf("%d", vet[j]);
                fprintf(arq, "%d", vet[j]);
                primeiro = 0;
            }
        }

        if (!primeiro) {
            printf("}");
            fprintf(arq, "}");
        }

        if (i != (1 << x) - 1) {
            printf(",");
            fprintf(arq, "%c", ',');
        }
    }

    printf("\n");
    fprintf(arq, "\n");
    fclose(arq);
}

// Esta função calcula a união de dois conjuntos representados por vetores 'vetA' e 'vetB'.
void uniaoConjuntos(int vetA[], int vetB[], int tamA, int tamB, const char *nomeArquivo) {
    // Calcula o tamanho da união dos conjuntos.
    int tamUni = tamA + tamB;
    int vetUni[tamUni];
    int uni = 0;
    char abri = '{', fecha = '}';

    // Copia os elementos do primeiro conjunto para 'vetUni'.
    for (int i = 0; i < tamA; i++) {
        vetUni[uni] = vetA[i];
        uni++;
    }

    // Copia os elementos do segundo conjunto para 'vetUni'.
    for (int i = 0; i < tamB; i++) {
        vetUni[uni] = vetB[i];
        uni++;
    }

    // Abre o arquivo 'nomeArquivo' para escrita no modo "append".
    FILE *arq = fopen(nomeArquivo, "a");

    // Verifica se o arquivo foi aberto com sucesso.
    if (arq == NULL) {
        printf("\nErro ao abrir o arquivo %s\n", nomeArquivo);
        return;
    }

    // Imprime e escreve a união dos conjuntos no arquivo.
    printf("\nA u B = {%d", vetUni[0]);
    fprintf(arq, "\nA u B:%c%d", abri, vetUni[0]);

    for (int i = 1; i < tamUni; i++) {
        printf(",%d", vetUni[i]);
        fprintf(arq, ",%d", vetUni[i]);
    }

    printf("}");
    fprintf(arq, "%c", fecha);

    fclose(arq);
}

// Esta função calcula a interseção de dois conjuntos representados por vetores 'vetA' e 'vetB'.
void intersecao(int vetA[], int vetB[], int tamA, int tamB, const char *nomeArquivo) {
    // Calcula o tamanho dos conjuntos.
    int maior, menor;
    int *ma, *me;
    char abri = '{', fecha = '}';
    int primeiro = 0;

    // Abre o arquivo 'nomeArquivo' para escrita no modo "append".
    FILE *arq = fopen(nomeArquivo, "a");

    // Verifica se o arquivo foi aberto com sucesso.
    if (arq == NULL) {
        printf("\nErro ao abrir o arquivo %s\n", nomeArquivo);
        return;
    }

    // Determina qual conjunto é o maior e qual é o menor.
    if (tamA > tamB) {
        maior = tamA;
        menor = tamB;
        ma = vetA;
        me = vetB;
    } else {
        maior = tamB;
        menor = tamA;
        ma = vetB;
        me = vetA;
    }

    // Imprime e escreve a interseção dos conjuntos no arquivo.
    printf("\nA ∩ B = {");
    fprintf(arq, "\nA ∩ B:%c", abri);

    for (int i = 0; i < maior; i++) {
        for (int j = 0; j < menor; j++) {
            if (ma[i] == me[j]) {
                if (primeiro > 0) {
                    printf(",");
                    fprintf(arq, ",");
                }
                printf("%d", ma[i]);
                fprintf(arq, "%d", ma[i]);
                primeiro++;
            }
        }
    }

    printf("}");
    fprintf(arq, "%c", fecha);

    fclose(arq);
}

// Esta função calcula a diferença entre dois conjuntos representados por vetores 'vet_01' e 'vet_02'.
void diferenca(int vet_01[], int vet_02[], int tam_01, int tam_02, const char *nomeArquivo, char a, char b) {
    // Abre o arquivo 'nomeArquivo' para escrita no modo "append".
    FILE *arq = fopen(nomeArquivo, "a");
    int primeiro = 0;

    // Verifica se o arquivo foi aberto com sucesso.
    if (arq == NULL) {
        printf("\nErro ao abrir o arquivo %s\n", nomeArquivo);
        return;
    }

    // Imprime no console e escreve no arquivo a representação da diferença entre os conjuntos 'a' e 'b'.
    printf("\n%c-%c = {", a, b);
    fprintf(arq, "\n%c-%c = {", a, b);

    // Percorre o primeiro vetor 'vet_01'.
    for (int i = 0; i < tam_01; i++) {
        int encontrou = 0;

        // Compara cada elemento do 'vet_01' com todos os elementos do 'vet_02'.
        for (int j = 0; j < tam_02; j++) {
            if (vet_01[i] == vet_02[j]) {
                encontrou = 1;
                break; // Se um elemento for encontrado no segundo conjunto, não é incluído na diferença.
            }
        }

        // Se o elemento não foi encontrado no segundo conjunto, é incluído na diferença.
        if (!encontrou) {
            if (primeiro > 0) {
                printf(",");
                fprintf(arq, ",");
            }
            printf("%d", vet_01[i]);
            fprintf(arq, "%d", vet_01[i]);
            primeiro++;
        }
    }

    // Fecha o conjunto de chaves e fecha o arquivo.
    printf("}");
    fprintf(arq, "}");
    fclose(arq);
}

// Esta função calcula o produto cartesiano entre dois conjuntos representados por vetores 'vet_01' e 'vet_02'.
void produtoCartesiano(int vet_01[], int vet_02[], int tam_01, int tam_02, const char *nomeArquivo, char a, char b){
        // Abre o arquivo 'nomeArquivo' para escrita no modo "append".
        FILE *arq = fopen(nomeArquivo, "a");

        // Verifica se o arquivo foi aberto com sucesso.
        if (arq == NULL) {
            printf("\nErro ao abrir o arquivo %s\n", nomeArquivo);
            return;
        }

        // Imprime no console e escreve no arquivo a representação do produto cartesiano entre os conjuntos 'a' e 'b'.
        printf("\n%cx%c = {", a, b);
        fprintf(arq, "\n%cx%c = {", a, b);

        // Percorre os elementos do primeiro conjunto 'vet_01'.
        for(int i = 0; i < tam_01; i++){
            // Percorre os elementos do segundo conjunto 'vet_02'.
            for(int j = 0; j < tam_02; j++){
                printf("{");
                fprintf(arq,"{");
                printf("%d,%d",vet_01[i],vet_02[j]);
                fprintf(arq,"%d,%d",vet_01[i],vet_02[j]);
                printf("}");
                fprintf(arq,"}");
            }
        }

        // Fecha o conjunto de chaves e fecha o arquivo.
        printf("}");
        fprintf(arq,"}");
        fclose(arq);
}










































































