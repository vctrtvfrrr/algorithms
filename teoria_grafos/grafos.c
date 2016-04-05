/**
 * Grafos
 */

// Inclusão das bibliotecas
#include <stdio.h>
#include <stdlib.h>

// Protótipos das funções
void menu(int *opcaoMenu);
void grau(int vertice);
void novo_grafo();

// Variáveis globais
int  qtdVertices;
char direcionado, peso;

/**
 * Função principal
 *
 * @return integer
 */
int main()
{
    int opcaoMenu;
	int vertice;

    do {
        // Invoca o menu principal
        menu(&opcaoMenu);

        // Limpamos a tela para a exibição da opção escolhida
        system("clear");

        switch (opcaoMenu) {
            case 1:
                novo_grafo();
                break;

            case 2:
    			printf("\nInforme o número do vértice: ");
    			scanf("%i", &vertice);

                grau(vertice);
                break;

            case 3:
                break;

            case 4:
                break;
        }
    } while (opcaoMenu != 0);

    return 0;
}


// Implementação das funções

/**
 * Função para impressão do menu
 */
void menu(int *opcaoMenu)
{
    printf("Bem vindo ao programa!\n");
    printf("______________________\n");
    printf("         MENU         \n");
    printf("______________________\n");
    printf("1. Informar um novo grafo \n");
    printf("2. Calcular o grau de um vértice \n");
    printf("3. Verificar se o grafo é regular \n");
    printf("4. Verificar se o grafo é completo \n");
    printf("0. Sair do programa \n");
    printf("\nEscolha uma das opções acima: ");

    scanf("%i", &(*opcaoMenu));
}

/**
 * Função que preenche a matriz com o grafo informado.
 *
 * @return void
 */
void novo_grafo()
{
    system("clear");

    printf("Informar um novo Grafo\n");
    printf("______________________\n");
    printf("Qual a quantidade de vértices do grafo?");
    scanf("%d", &qtdVertices);
    printf("O grafo a ser informado é direcionado? (S ou N)");
    do {
        scanf("%c", &direcionado);
    } while(strcmp(direcionado, "S") != 0 || strcmp(direcionado, "s") != 0 || strcmp(direcionado, "N") != 0 || strcmp(direcionado, "n") != 0);

    printf("As arestas do grafo possuem peso? (S ou N)");
    do {
        scanf("%c", &peso);
    } while(strcmp(peso, "S") != 0 || strcmp(peso, "s") != 0 || strcmp(peso, "N") != 0 || strcmp(peso, "n") != 0);
}

/**
 * Função que retorna o grau de um determinado vértice.
 *
 * @return void
 */
void grau(int vertice)
{
    int grau = 0;
    //int matrix[4][4] = {{0,1,0,1},{1,0,1,1},{0,1,0,0},{1,1,0,0}}; // não direcionado
    int matrix[4][4] = {{0,1,0,0},{0,0,0,0},{0,1,0,1},{0,1,0,0}}; // direcionado

    // Ajusta o número do vértice para corresponder à matriz
    vertice--;

    for (int i = 0; i < 4; ++i) {
        if (matrix[vertice][i] != 0) {
            grau++;
        }
    }

    // Se o grafo or direcionado...
    if (1) {
	    for (int i = 0; i < 4; ++i) {
	        if (matrix[i][vertice] != 0) {
	            grau++;
	        }
	    }
    }

    printf("Grau do vértice: %i", grau);
}