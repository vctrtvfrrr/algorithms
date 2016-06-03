<?php

class Database
{
	
	public function connect()
	{
		return new \PDO("mysql:host=localhost;dbname=nome_do_banco", "root", "senha"); 
	}
}