#include <stdio.h>
#define n   10


int vetorA[n]; // vetor com as idades dos clientes
FILE *arquivo; // arquivo que guarda as idades
int i, j, Maxi; // contadores e Maxi para guardar a maior idade

int max(int vetorA[])
{
    int valorInicial, contador;

    for (contador = 1; contador < n; contador++) {
        if (valorInicial < vetorA[contador]) {
            valorInicial = vetorA[contador];
        }
    }

    return valorInicial;
}

int main()
{
    int valorMaximo;

    // 1. abre arquivo ja existente no disco vetor.txt deve estar na mesma pasta do projeto
    arquivo = fopen("vetor.txt", "r");

    // 2. percorre o vetor no disco (fscanf) e mostra na tela
    for (i = 0; i < n; i++) {
        fscanf(arquivo, "%d", &vetorA[i]);
        printf("%10d\n", vetorA[i]);
    }

    // 3. chamada da funcao Max com o parametro vetor A
    valorMaximo = max(vetorA);

    // 4. retorna em Maxi o valor da idade maxima e imprime
    printf("%d\n", valorMaximo);

    // 5. fecha arquivo no disco
    fclose(arquivo);

    return 0;
}
