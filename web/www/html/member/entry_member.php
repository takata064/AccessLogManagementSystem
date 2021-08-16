<?php
    $question = $_GET['name'];

    $dsn      = 'mysql:host=db;dbname=eagis;';
    $user     = 'root';
    $password = 'root';

    // DBへ接続
    try{
        $dbh = new PDO($dsn, $user, $password);

        $dbh->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
        $dbh->setATTRIBUTE(PDO::ATTR_EMULATE_PREPARES, false);

        // クエリの実行
        $query = "SELECT * FROM entrylist WHERE name="."'".$question."'";
        $stmt = $dbh->query($query);

        // 表示処理
        while($row = $stmt->fetch(PDO::FETCH_ASSOC)){
            echo $row["name"];
            echo $row["entrytime"];
            echo $row["updatetime"];
            echo $row["room"];
        }

    }catch(PDOException $e){
        print("データベースの接続に失敗しました".$e->getMessage());
        die();
    }

    // 接続を閉じる
    $dbh = null;
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    entry
</body>
</html>