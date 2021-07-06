# **データベース設計**

## 説明
* amac(AnonymousMACAdress)

  ハッシュ化されたMACアドレス。一人が複数台の端末を持っていることを想定している。
  ハッシュ化にはHMACのアルゴリズムを使う。

* salt

  ハッシュ化に使うランダムな文字列。

* name

  その人の名前。本名でなくとも、識別できるものであればよい。

* password
  
  認証に使うパスワード。ハッシュ化して保存。
 
* status
  
  その人の情報、役割。学生、院生など。
  
* comment
  
  デバイスの説明。ここの情報で何のデバイスかを識別。

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
  
## HMACのアルゴリズムを使ったハッシュ化

アルゴリズムは以下のようになる。

|名前|記号|
|----|----|
|ソルト|k|
|MACアドレス|m|
|ipad|ipad|
|opad|opad|
|okey|okey|
|ikey|ikey|
|SHA2_256()|H_1()|
|RIPEMD160()|H_2()|

* ソルトKと定数ipad,opadの排他的論理和をとり、カギを作成

  <img src="https://latex.codecogs.com/gif.latex?{\color{Cyan}&space;ikey&space;=&space;k&space;\oplus&space;ipad&space;}"> \\
  
  <img src="https://latex.codecogs.com/gif.latex?{\color{Cyan}&space;okey&space;=&space;k&space;\oplus&space;opad&space;}">

* 作成したカギとMACアドレスを組み合わせたものに対してハッシュ化を重ね合わせることで、解読しにくくする

  <img src="https://latex.codecogs.com/gif.latex?{\color{Cyan}AMAC&space;=&space;H_2&space;\left&space;(&space;H_1\left&space;(okey&space;\left&space;\|&space;H_1\left&space;(&space;ikey&space;\right&space;\|m&space;\right&space;)&space;\right&space;)&space;\right&space;)&space;}">


## データ型
|  カラム名  |  データ型  |
|----|----|
|  amac  |  varchar(40) くらい?  |
| salt | char(8) |
| password | varchar(32) |
| name | varchar(80) |
| status | varchar(40) |
| comment | varchar(40) |
| entrytime | timestamp |
| updatetime | timestamp |
| exittime | timestamp |
| room | varchar(8) |


## 未処理のテーブル
* 第一正規化後のテーブル　

|  amac |  salt  |  name  | password |  status  |  comment  |  entrytime  | updatetime |  exittime  | room |
| ---- | ---- |----|----|----|----|----|----|----|----|
|  AJSHCHC#DAS  |  abcdefgh  |  たかたか  |  cisco1234  |  学部生  |  iPhone  |   2021-06-02 12:30:00 | 2021-06-02 16:50:00 | 2021-06-02 16:50:00 |  111 |

## テーブル一覧

* memberlist

| name | status | password |
|----|----|----|
| たかたか | 学部生 | cisco1234 |

* devicelist

| amac | salt | comment | name |
|----|----|----|----|
| AJSHCHC#DAS | abcdefgh | iPhone | たかたか |        

* entrylist

| amac | name | entrytime | updatetime |room |
|----|----|----|----|----|
| AJSHCHC#DAS | たかたか | 2021-06-02 12:30:00 | 2021-06-02 16:50:00 | 111 |

* log

| amac | name | entrytime | exittime |room |
|----|----|----|----|----|
| AJSHCHC#DAS | たかたか | 2021-06-02 12:30:00 | 2021-06-02 16:50:00 | 111 |
