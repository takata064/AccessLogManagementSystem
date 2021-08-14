#include<memory>
#include<string>

#include<jdbc/mysql_connection.h>
#include<jdbc/mysql_driver.h>
#include <jdbc/cppconn/resultset.h>
#include <jdbc/cppconn/statement.h>
#include <jdbc/cppconn/prepared_statement.h>

using namespace std;

sql::mysql::MySQL_Driver *driver;
sql::Connection *con;
sql::Statement *stmt;
//sql::ResultSet  *res;
sql::PreparedStatement *prep_stmt;

string address="tcp://127.0.0.1:33306";
string user="root";
string password="root";

int main(){

	driver = sql::mysql::get_mysql_driver_instance();
	con = driver->connect(address, user, password);
	stmt = con->createStatement();
	stmt->execute("USE eagis");

	prep_stmt = con->prepareStatement("INSERT INTO entrylist(id, entrytime, room) VALUES (?, ?, ?)");

	prep_stmt->setString(1, "k19555");
	prep_stmt->setString(2, "2015-03-13 21:01:59");
	prep_stmt->setString(3, "111");
	prep_stmt->execute();

	//stmt->execute("insert into member values('k19064','高田優一')");

	delete prep_stmt;
	//delete res;
	delete stmt;
	delete con;
}