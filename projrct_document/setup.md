# MySQL Connector/C++ のインストール手順(MAC)

## 事前に必要なもの
* boost(依存関係分かってないけど多分必要)
* cmake
* clang++
* mysql

## step1

下のリンクからOSに合ったパッケージをダウンロード後、実行。ウィンドウが現れたら手順に従いながらインストール。

> [MySQL Connector/C++](https://dev.mysql.com/downloads/connector/cpp/)


## step2

適当なディレクトリに以下のMakefileを作成。

```
MYSQL_CONCPP_DIR = /usr/local/mysql-connector-c++-8.0.25(インストール先のパス。場合に応じて変更)
CPPFLAGS = -I $(MYSQL_CONCPP_DIR)/include -L $(MYSQL_CONCPP_DIR)/lib64
LDLIBS = -lmysqlcppconn
CXX = clang++
CXXFLAGS = -std=c++11
app : app.cpp
```

## step3

同じディレクトリにtest.cppを作成。

```
// test.cpp
#include<memory>

#include<jdbc/mysql_connection.h>
#include<jdbc/mysql_driver.h>
#include <jdbc/cppconn/resultset.h>
#include <jdbc/cppconn/statement.h>

using namespace std;

int main(){

	sql::mysql::MySQL_Driver *driver;
	sql::Connection *con;
	sql::Statement *stmt;
	sql::ResultSet  *res;

	driver = sql::mysql::get_mysql_driver_instance();
	con = driver->connect("tcp://127.0.0.1:33306", "b3", "b3");
	stmt = con->createStatement();
	stmt->execute("USE playground");
	res = stmt->executeQuery("SELECT id, label FROM test ORDER BY id ASC");
	while (res->next()) {
	// You can use either numeric offsets...
	cout << "id = " << res->getInt(1); // getInt(1) returns the first column
	// ... or column names for accessing results.
	// The latter is recommended.
	cout << ", label = '" << res->getString("label") << "'" << endl;
	}

	delete res;
	delete stmt;
	delete con;
}
```

ターミナルで
```
 make test
 ```

を実行。 何事もなく終了したらOK。