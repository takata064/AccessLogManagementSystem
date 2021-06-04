# **データベース設計**

# 説明
* amac(AnonymousMACAdress)

暗号化されたMACアドレス。一人が複数台の端末を持っていることを想定している。

* id

学籍番号。先頭小文字のk00000というフォーマットで保存。

* name

その人の名前。

* entrytime

入ってきた時間。

* updatetime

直近で在室が確認できた時間

* exittime

最後に在室していたであろう時間。

* room

部屋番号。

## データ型
|  カラム名  |  データ型  |
|----|----|
|  amac  |  varchar(20)  |
| id | char(6) |
| name | varchar(20) |
| entrytime | timestamp |
| updatetime | timestamp |
| exittime | timestamp |
| room | varchar(5) |


## テーブル一覧
* 未処理のテーブル　

|  amac |  id  |  name  |  entrytime  | updatetime |  exittime  | room |
| ---- | ---- |----|----|----|----|----|
|  AJSHCHC#DAS  |  k19064  |  高田優一  |   2021-06-02 12:30:00 | 2021-06-02 16:50:00 | 2021-06-02 16:50:00 |  111 |

* member

| id | name |
|----|----|
| k19064 | 高田優一 |

* amaclist

| amac | id |
|----|----|
| AJSHCHC#DAS | k19064 |        

* entrymember

| id | entrytime | updatetime |room |
|----|----|----|----|
| k19064 | 2021-06-02 12:30:00 | 2021-06-02 16:50:00 | 111 |

* log

| id | entrytime | exittime |room |
|----|----|----|----|
| k19064 | 2021-06-02 12:30:00 | 2021-06-02 16:50:00 | 111 |
