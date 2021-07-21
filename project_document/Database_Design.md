# **データベース設計**

## 説明
* amac(AnonymousMACAdress)

  ハッシュ化されたMACアドレス。一人が複数台の端末を持っていることを想定している。
  ハッシュ化にはRIPEMD160とSHA2_256を使う。

* name

  その人の名前。本名でなくとも、識別できるものであればよい。

* password
  
  認証に使うパスワード。ハッシュ化して保存。
 
* status
  
  その人の情報、役割。学生、院生など。
  
* device
  
  デバイスの説明。ここの情報で何のデバイスかを識別。

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
|  amac  |  varchar(40) |
| password | varchar(32) |
| name | varchar(80) |
| status | varchar(40) |
| device | varchar(40) |
| entrytime | timestamp |
| updatetime | timestamp |
| exittime | timestamp |
| room | varchar(8) |


## 未処理のテーブル
* 第一正規化後のテーブル　

|  amac |  name  | password |  status  |  device  |  entrytime  | updatetime |  exittime  | room |
| ---- | ---- |----|----|----|----|----|----|----|
|  AJSHCHC#DAS  |  たかたか  |  cisco1234  |  学部生  |  iPhone  |   2021-06-02 12:30:00 | 2021-06-02 16:50:00 | 2021-06-02 16:50:00 |  111 |

## テーブル一覧

* memberlist

| name | status | password |
|----|----|----|
| たかたか | 学部生 | cisco1234 |

* devicelist

| amac | device | name |
|----|----|----|
| AJSHCHC#DAS | iPhone | たかたか |        

* entrylist

| amac | name | entrytime | updatetime |room |
|----|----|----|----|----|
| AJSHCHC#DAS | たかたか | 2021-06-02 12:30:00 | 2021-06-02 16:50:00 | 111 |

* log

| amac | name | entrytime | exittime |room |
|----|----|----|----|----|
| AJSHCHC#DAS | たかたか | 2021-06-02 12:30:00 | 2021-06-02 16:50:00 | 111 |
