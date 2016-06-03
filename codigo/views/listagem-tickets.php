<!DOCTYPE html>
<html>
	<head>
		<title><?php echo $view ?></title>
	</head>
	<body>
		<?php foreach ($tickets as $ticket) : ?>
			<strong><?php echo $ticket['title'] ?></strong>
			<p>
				<?php echo $ticket['description'] ?>
			</p>
		<?php endforeach; ?>
	</body>
</html>