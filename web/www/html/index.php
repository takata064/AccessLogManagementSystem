<?php

$dsn      = 'mysql:host=localhost:33306;dbname=eagis;';
$user     = 'root';
$password = 'root';

// DBへ接続
try{
    $dbh = new PDO($dsn, $user, $password);

    $dbh->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    $dbh->setATTRIBUTE(PDO::ATTR_EMULATE_PREPARES, false);

    // クエリの実行
    $query = "SELECT * FROM member_list";
    $stmt = $dbh->query($query);

    // 表示処理
    while($row = $stmt->fetch(PDO::FETCH_ASSOC)){
        echo $row["name"];
    }

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