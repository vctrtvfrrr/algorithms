<?php

namespace Controller;

class Auth
{
	
	public function logic()
	{
		if ($_SERVER['REQUEST_METHOD'] == 'POST') {
			$con = new Database();
			var_dump($con); exit;
			// $_POST
		} else {
			$view = 'login';
			return compact('view');
		}
	}
}