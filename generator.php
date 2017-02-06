<?php

$tab = [];

$value  = rand (0, 100000000);
$i = 0;

while ($i != 10000)
{
	while (already_exist($value, $tab))
	{
		$value  = rand (0, 100000000);
	}
	$tab [] = $value;
	$i++;
}

function already_exist($value, $tab)
{
	foreach ($tab as $elem)
	{
		if ($elem == $value)
		 return (true);
	}
	return (false);
}

foreach ($tab as $elem)
{
	echo $elem . ' ';
}
