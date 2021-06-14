# MACアドレス等の情報保持クラス-ドキュメント

- ファイル名：UserInfo.cpp
- クラス名：UserInfo

## 使用ライブラリ
- ctime
- string

## メンバ変数

|型|変数名|詳細|
|-|-|-|
|std::string|mac_address|MACアドレスを保持|
|std::time_t|last_time|最後に在席確認した時間を保持|

## コンストラクタ

|関数名|引数１|引数２|詳細|
|-|-|-|-|
|UserInfo|std::string mac_address|std::time_t last_time|値をメンバ変数に格納|
## メンバ関数

|関数名|引数|返り値|詳細|
|-|-|-|-|
|setMacAdress|std::string mac_address|なし|MACアドレスを、変数mac_addressに格納|
|getMacAdress|なし|std::string mac_address|mac_addressの値を取得|
|setLastTime|std::time_t last_time|なし|最後に在席確認した時間を変数last_timeに格納
|getLastTime|なし|std::time_t last_time|last_timeの値を取得|