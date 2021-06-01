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
* exittime
出て行った時間。
* room
部屋番号。

## データ型
|  カラム名  |  データ型  |
|----|----|
|  amac  |  varchar  |
| id | char(6) |
| name | varchar |
| entrytime | timestamp |
| exittime | timestamp |
| room | varchar |


## テーブル一覧
* 一番最初のテーブル　

|  amac |  id  |  name  |  entrytime  |  exittime  | room |
| ---- | ---- |----|----|----|----|
|  AJSHCHC#DAS  |  k19064  |  高田優一  |   2021-06-02 12:30:00 | 2021-06-02 16:50:00 |  111 |

* member

| id | name |
|----|----|
| k19064 | 高田優一 |

* amaclist

| amac | id |
|----|----|
| AJSHCHC#DAS | k19064 |        

* entrymember

| id | entrytime | room |
|----|----|----|
| k19064 | 2021-06-02 12:30:00 | 111 |

* log

| id | entrytime | exittime |room |
|----|----|----|----|
| k19064 | 2021-06-02 12:30:00 | 2021-06-02 16:50:00 | 111 |
