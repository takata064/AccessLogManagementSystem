# opensslの環境構築(macOS)

## step1
* 下のサイトからopensslの実体をダウンロード
> [openSSL](https://www.openssl.org/source/)

## step2
* ビルドの手順はINSTALL.mdに書いてある。

* ダウンロードしたファイルに移動して、ターミナルで
```
make
```
を実行してビルド

* 次に
```
make test
```
を実行して、ライブラリのテストを行う。エラーらしきものが見当たらなければOK。時間かかるので注意！

* 最後に
```
make install
```
を実行。openSSL開発者によると、openSSLに依存しているソフトウェアが既にある場合は注意しろ、とのこと。
usr/local/ にsslがあればOK。

## step3
* 適当なディレクトリに以下のMakefileを作成。
```
OPENSSL_DIR = /usr/local
CPPFLAGS = -I $(OPENSSL_DIR)/include  -L $(OPENSSL_DIR)/lib
LDLIBS = -lssl -lcrypto
CXX = clang++
CXXFLAGS = -std=c++11
app : app.cpp
```

* 同じディレクトリに以下のtest.cppを作成。
```
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

#include <openssl/sha.h>
#include <openssl/ripemd.h>

string ripemd(const string str){
    unsigned char hash[RIPEMD160_DIGEST_LENGTH];
    RIPEMD160_CTX ripemd_160;
    RIPEMD160_Init(&ripemd_160);
    RIPEMD160_Update(&ripemd_160, str.c_str(), str.size());
    RIPEMD160_Final(hash, &ripemd_160);
    stringstream ss;
    for(int i = 0; i < RIPEMD160_DIGEST_LENGTH; i++)
    {
        ss << hex << setw(2) << setfill('0') << (int)hash[i];
    }
    return ss.str();
}

string sha256(const string str)
{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);
    stringstream ss;
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        ss << hex << setw(2) << setfill('0') << (int)hash[i];
    }
    return ss.str();
}

int main() {
    cout << sha256("1234567890_1") << endl;
    cout << ripemd("1234567890_1") << endl;
    return 0;
}
```
* ターミナルで以下を実行。エラーが起きなければ、OK。
```
make test
```
* 最後に、以下を実行して、ハッシュ値に変換されていれば、OK。
```
./test
```