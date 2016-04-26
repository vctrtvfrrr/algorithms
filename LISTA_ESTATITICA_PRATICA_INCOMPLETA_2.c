#include <stdio.h>
//bloco 1 - ?
#define MAX_ELEMENTOS 10 // Constante com o m�ximo de elementos da lista

//bloco 2
typedef struct
{
    char vetor[MAX_ELEMENTOS]; // Intervalo de 0 ... 9
    int fim;
} t_lista;

//bloco 3
t_lista L;
int opcao;

void inicializar()
{
    // Inicializa a vari�vel fim com -1.
    L.fim = -1;
}

int cheia()
{
    // Se vari�vel fim � igual ao n�mero m�ximo de elementos - 1,
    // a lista est� cheia.
    return (L.fim == (MAX_ELEMENTOS - 1));
}

int vazia()
{
    // Se vari�vel fim � igual a -1, a lista est� vazia.
    return (L.fim == -1);
}

void incluir()
{
    int i, posicao;
    char novo_elemento;

    //verificar se a lista esta cheia
    if (cheia()) {
        printf("\n LISTA CHEIA! \n");
        return;
    } else { // Se a lista n�o est� cheia, pode inserir.
        printf("Digite o caractere que deseja inserir: ");
        fflush(stdin);
        scanf("%s", &novo_elemento);

        printf("Em qual posicao deseja inserir.......: ");
        scanf("%d", &posicao);


        // Primeira posi��o � 0, portanto n�o pode ser menor que 0.
        // posi��o n�o pode ser maior que o fim da lista, ou seja,
        // n�o � poss�vel pular posi��es.
        if ((posicao < 0) || (posicao > L.fim + 1)) {
            printf("\n POSICAO INVALIDA! \n");
        } else {

            // A lista permite que o usu�rio insira numa posi��o j� preenchida
            // portanto � preciso que o programa coloque o novo valor na
            // posi��o desejada e desloque os valores subsequentes � posi��o
            // escolhida para a direita.

            for (i = L.fim; i > posicao; i--) {
                // Desloca os elementos para direita
                L.vetor[i] = L.vetor[i - 1];
            }

            L.vetor[posicao] = novo_elemento;
            L.fim += 1;
        }
    }
}

void excluir()
{
    int i, posicao;

    if (vazia()) {
        printf("\n LISTA VAZIA! \n");
        return;
    }

    printf("Em qual posicao deseja remover: ");
    scanf("%d", &posicao);

    // Posi��o n�o pode ser menor que 0.
    // Posi��o n�o pode ser maior que n�mero de elementos da lista.
    if ((posicao < 0) || (posicao > L.fim)) {
        printf("\n POSICAO INVALIDA \n");
    } else {
        // Para remover um elemento, podemos, a partir da posi��o desejada,
        // deslocar o vetor para esquerda e decrementar a vari�vel fim.
        for (i = posicao; i <= L.fim; i++) {
            L.vetor[i] = L.vetor[i + 1]; // Desloca os elementos para esquerda
        }

        L.fim -= 1;
    }
}

void mostrar()
{
    // Exibe os elementos da lista percorrendo o L.vetor desde
    // o in�cio at� a posi��o L.fim
    int i;

    if (vazia()) {
        printf("\n LISTA VAZIA! \n");
        return;
    }

    printf("\nA lista possui %d elemento(s)\n", L.fim + 1);

    for (i = 0; i < L.fim; i++) {
        printf("%c", L.vetor[i]);
    }

    printf("\n\n"); // pula duas linhas
}

void menu()
{
    printf("\n-----Menu de Opcoes------\n\n");
    printf("0 - Sair\n");
    printf("1 - Incluir um elemento na lista\n");
    printf("2 - Excluir um elemento da lista\n");
    printf("3 - Exibir a lista\n");
    printf("\nO que deseja fazer? ");
    scanf("%d", &opcao);
}

int main()
{
    inicializar();

    do {
        menu();
        switch (opcao) {
            case 0:
                break;
            case 1:
                incluir();
                break;
            case 2:
                excluir();
                break;
            case 3:
                mostrar();
                break;
            default:
                printf("_____________Opcao invalida_____________\n\n");
        }
    } while (opcao != 0);

    return 0;
}
