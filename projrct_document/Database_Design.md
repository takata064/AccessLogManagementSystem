# **データベース設計**

## データ型
|  カラム名  |  データ型  |
|----|----|
|  amac  |  varchar  |
| id | char(6) |
| name | varchar |
| entrytime | char(12) |
| exittime | char(12) |
| room | char(3) |


## テーブル一覧
* 一番最初のテーブル　

|  amac |  id  |  name  |  entrytime  |  exittime  | room |
| ---- | ---- |----|----|----|----|
|  AJSHCHC#DAS  |  k19064  |  高田優一  |   202106021230 | 202106021650 |  111 |

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
| k19064 | 202106021230 | 111 |

* log

| id | entrytime | exittime |room |
|----|----|----|----|
| k19064 | 202106021230 | 202106021650 | 111 |
