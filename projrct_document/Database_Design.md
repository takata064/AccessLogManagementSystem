# **データベース設計**

## 説明
* amac(AnonymousMACAdress)

  ハッシュ化されたMACアドレス。一人が複数台の端末を持っていることを想定している。
  ハッシュ化はSHA2-256->RIPEMD160の手順で行う。一方向ハッシュなので照合の際には注意すること。

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
  
## ユーザ権限
  まだわかりません


## データ型
|  カラム名  |  データ型  |
|----|----|
|  amac  |  varchar(40) くらい?  |
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

* memberlist

| id | name |
|----|----|
| k19064 | 高田優一 |

* amaclist

| amac | id |
|----|----|
| AJSHCHC#DAS | k19064 |        

* entrylist

| id | entrytime | updatetime |room |
|----|----|----|----|
| k19064 | 2021-06-02 12:30:00 | 2021-06-02 16:50:00 | 111 |

* accesslog

| id | entrytime | exittime |room |
|----|----|----|----|
| k19064 | 2021-06-02 12:30:00 | 2021-06-02 16:50:00 | 111 |
