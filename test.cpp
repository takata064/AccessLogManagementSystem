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