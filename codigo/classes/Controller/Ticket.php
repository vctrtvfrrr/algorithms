<?php

namespace Controller;

class Ticket
{
	public function __construct()
	{
		if (!isset($_SESSION['USER'])) {
			echo "Não autorizado!";
			exit;
		}
	}

	public function logic()
	{
		$tickets = [
			[
				'title' => 'Teste 1',
				'description' => 'descrição do ticket 1',
			],
			[
				'title' => 'Teste 2',
				'description' => 'descrição do ticket 2',
			],
			[
				'title' => 'Teste 3',
				'description' => 'descrição do ticket 3',
			],
		];

		$numTotal = count($tickets);
		
		$view = 'listagem-tickets';

		return compact('tickets', 'numTotal', 'view');
	}
}