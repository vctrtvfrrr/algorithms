#include <stdio.h>
#include <stdlib.h>

//2.
typedef struct
{
    int info;
    struct t_pilha *prox;
} t_pilha;

//3.
t_pilha *topo;
int novoValor;

//5;

void cria_pilha()
{
    topo = malloc(sizeof (t_pilha));
    topo = NULL;
}

int vazia()
{
    return (topo == NULL ? 1 : 0);
}

//insercao na pilha
void push(int e)
{
    // aloca a estrutura pilha e aponta com aux
    t_pilha *aux = malloc(sizeof (t_pilha));

    //o campo do registro recebe a novo dado passado como parametro na funcao push
    aux->info = e;

    //o prox do aux aponta para o mesmo lugar
    aux->prox = topo; // aux->prox aponta para o topo.

    topo = aux; // topo aponta para o novo elemento aux.
}

//remocao na pilha
void pop()
{
    t_pilha *aux;

    if (vazia()) {
        printf("n Pilha vazia! n");
        return; // sai da funcao pq para sair do if basta "break"
    }

    //?? sempre remove o elemento do topo
    //?? topo aponta para o pr?ximo elemento

    printf("Elemento %d eliminado com sucesso", aux->info);
    free(aux); // apaga o elemento e libera mem?ria
}

void mostra_topo()
{
    if (vazia())
    {
        printf("n Pilha vazia! n");
        return;
    }
    printf("n+++++ TOPO DA PILHA +++++n");
    //????
}

void mostra_tudo()
{
    t_pilha *aux = topo;

    if (vazia())
    {
        printf("n Pilha vazia! n");
        return;
    }
    printf("n+++++ TODOS ELEMENTOS+++++n");
    while (aux != NULL) {
        printf("%dn", aux->info);
        aux = aux->prox;
    }
}

int menu()
{
    int opcao;

    printf("nn Opcoes possiveis n");
    printf("0 - Sairn");
    printf("1 - Inserirn");
    printf("2 - Removern");
    printf("3 - Mostrar topon");
    printf("4 - Mostrar tudon");
    printf("nO que deseja fazer? ");
    scanf("%d", &opcao);
    return opcao;
}

void lerDados()
{
    printf("nn=== Lendo os dados ===n");
    printf("Digite o valor a ser inserido na pilha: ");
    scanf("%d", &novoValor);
}

int main()
{
    int opcao;

    cria_pilha();
    do {
        opcao = menu();
        switch (opcao)
        {
            case 0:
                break;
            case 1: // inserir
                lerDados();
                push(novoValor);
                break;
            case 2: // remover
                pop();
                break;
            case 3: // mostrar topo
                mostra_topo();
                break;
            case 4: // mostrar tudo
                mostra_tudo();
                break;
            default:
                printf("_____________Opcao invalida_____________nn");
        } // fim switch
    } //fim while
    while (opcao != 0);
    return 0;
}
