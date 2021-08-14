#include<iostream>
#include<string>
#include<memory>

#include<jdbc/mysql_connection.h>
#include<jdbc/mysql_driver.h>
#include <jdbc/cppconn/resultset.h>
#include <jdbc/cppconn/statement.h>
#include <jdbc/cppconn/prepared_statement.h>

#include"cppconn.hpp"

using namespace std;

sql::mysql::MySQL_Driver *driver;
sql::Connection *con;
sql::Statement *stmt;
sql::ResultSet  *res;
sql::PreparedStatement *prep_stmt;

string address="tcp://127.0.0.1:33306";
string user="root";
string password="root";

string sq="'";

string cppconn::find_name(string amac){
    string name="";
    driver = sql::mysql::get_mysql_driver_instance();
	con = driver->connect(address, user, password);
	stmt = con->createStatement();
	stmt->execute("USE eagis");

    res = stmt->executeQuery("SELECT amac,name FROM devicelist WHERE amac="+sq+amac+sq);
    while (res->next()) {
        name=res->getString("name");
        //cout << "name= '" << res->getString("name")<< endl;
    }

    delete res;
    delete stmt;
    delete con;

    if(name==""){
        return "-1";
    }else{
        return name;
    }
}

bool cppconn::find_device(string amac){
    string name="";
    driver = sql::mysql::get_mysql_driver_instance();
	con = driver->connect(address, user, password);
	stmt = con->createStatement();
	stmt->execute("USE eagis");

    res = stmt->executeQuery("SELECT amac FROM devicelist WHERE amac="+sq+amac+sq);
    while (res->next()) {
        name=res->getString("name");
        //cout << "name= '" << res->getString("name")<< endl;
    }

    delete res;
    delete stmt;
    delete con;

    if(name==""){
        return 0;
    }else{
        return 1;
    }
}