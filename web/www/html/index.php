<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
 "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="ja" lang="ja">
<head>
<meta http-equiv="Content-Type" content="text/html;charset=UTF-8" />
<title>サンプル</title>
</head>
<body>

<?php
#print 'Hello Word';
$original_string = "パスワード";
$hased_string = hash('sha256', $original_string);
#print_r($hased_string.PHP_EOL);
$rimed_string = hash('ripemd160', $hased_string);
print_r($rimed_string.PHP_EOL);
?>

</body>
</html>