<?php

class Application
{
	
	public function __construct()
	{
		$router = new Router();
		$route = $router->parseRoute($_SERVER['REQUEST_URI']);

		$controller = new $route();
		$result = $controller->logic();

		$view = new View();
		$view->render($result['view'], $result);
	}
}