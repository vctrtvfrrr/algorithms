/**
 * Grafos
 */

// Inclusão das bibliotecas
#include <stdio.h>
#include <stdlib.h>

// Protótipos das funções
void menu(int *opcaoMenu);
int grau(int vertice);

/**
 * Função principal
 *
 * @return integer
 */
int main()
{
    int opcaoMenu;

    do {
        // Invoca o menu principal
        menu(&opcaoMenu);

        // Limpamos a tela para a exibição da opção escolhida
        system("clear");

        switch (opcaoMenu) {
            case 1:
                grau(2);
                break;

            case 2:
                grau(2);
                break;

            case 3:
                grau(2);
                break;

            case 4:
                grau(2);
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
 * Função que retorna o grau de um determinado vértice.
 *
 * @return integer
 */
int grau(int vertice)
{
    int grau = 0;
    int matrix[3][3] = {{0,1,0},{1,1,1},{1,1,0}};

    // Ajusta o número do vértice para corresponder à matriz
    vertice--;

    for (int i = 0; i < 3; ++i) {
        if (matrix[vertice][i] != 0) {
            grau++;
        }
    }

    printf("Grau do vértice: %i", grau);

    return grau;
}
