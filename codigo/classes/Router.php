<?php

class Router
{
	public function parseRoute($uri)
	{
		switch ($uri) {
			case '/login':
				return Controller\Auth::class;
				break;

			case '/tickets':
				return Controller\Ticket::class;
				break;

			case '/':
			default:
				return Controller\Home::class;
				break;
		}
	}
}