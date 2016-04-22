void excluir()
{
    // Se o ponteiro L estiver vazio retorna nulo
    if (L == NULL) {
        return;
    }

    char nome[50]; // Nome do aluno que queremos excluir
    t_no *ant = NULL; // Ponteiro auxiliar que nos dirá qual a próxima estrutura
    t_no *elem = L; // Ponteiro auxiliar que nos dirá qual a estrutura a seguir

    printf("\nDigite o nome do aluno que deseja excluir: ");
    fflush();
    scanf("%s", &nome);

    while (elem != NULL) {
    	// Se encontrarmos o aluno correto
        if(strcmp(nome, elem->nome) == 0) {
        	// Interrompe o loop
            break;
        }

        ant = elem;
        elem = elem->prox;
    }

    // Se a variável elem não for nula significa que encontramos o elemento
    if (elem != NULL) {
        ant = elem->prox; // Apontamos o elemento anterior para o ponteiro que apontava o elemento atual
	    printf("\nAluno excluído com sucesso!\n\n");
	    free(elem);
    }
}

