void excluir() 
{
	int novo_elemento, i, posicao;

	printf("Qual posicao deseja apagar? ");
	scanf("%d", &posicao);

	// Primeira posição é 0, portanto não pode ser menor que 0.
	// posição não pode ser maior que o fim da lista.
	if ((posicao < 0) || (posicao > L.fim + 1)) {
		printf("\n POSICAO INVALIDA! \n");
	} else {
		// Se a posição informada pelo usuário é válida
		// removemos o conteúdo da posição sobrescrevendo-o
		// com os dados à direita do vetor
		for (i = posicao; i < L.fim; i++) {
			L.vetor[i] = L.vetor[i + 1]; //Desloca os elementos para a esquerda
			L.fim -= 1; // Removemos uma posição do fim
		}
	}
}
