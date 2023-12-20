<?php

$module = 'daruma_framework';
if (!extension_loaded($module)) {
	echo ">> Module $module is not compiled into PHP\n\n";
	exit;
}

echo ">> Module $module loaded!\n\n";

$functions = get_extension_funcs($module);
echo ">> Functions available:\n";
foreach ($functions as $func) {
	echo $func . "\n";
}
