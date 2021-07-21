<?php

$dsn      = 'mysql:host=192.168.3.3:33306;dbname=eagis;';
$user     = 'root';
$password = 'root';

// DBへ接続
try{
    $dbh = new PDO($dsn, $user, $password);

    $dbh->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    $dbh->setATTRIBUTE(PDO::ATTR_EMULATE_PREPARES, false);


    $sql = "INSERT INTO memberlist (name, status, password) VALUES (:name, :status, :password)";

    // クエリの実行
    $stmt = $dbh->prepare($sql);
    $params = array(':name' => '高田', ':status' => '学生', ':password' => 'aaaaa');
    $stmt->execute($params);

    // 表示処理
    //while($row = $stmt->fetch(PDO::FETCH_ASSOC)){
        //echo $row["name"];
    //}

}catch(PDOException $e){
    print("データベースの接続に失敗しました".$e->getMessage());
    die();
}

// 接続を閉じる
$dbh = null;

?>
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8">
        <title>Example</title>
    </head>
    <body>
        <!-- ここではHTMLを書く以外のことは一切しない -->
    </body>
</html>