MYSQL_CONCPP_DIR = /usr/local/mysql-connector-c++-8.0.25
OPENSSL_DIR = /usr/local
CPPFLAGS = -I $(MYSQL_CONCPP_DIR)/include -I $(OPENSSL_DIR)/include -L $(MYSQL_CONCPP_DIR)/lib64 -L $(OPENSSL_DIR)/lib
LDLIBS = -lmysqlcppconn -lssl -lcrypto 
CXX = clang++
CXXFLAGS = -std=c++11

app : app.cpp

