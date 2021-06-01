MYSQL_CONCPP_DIR = /usr/local/mysql-connector-c++-8.0.25
CPPFLAGS = -I $(MYSQL_CONCPP_DIR)/include -L $(MYSQL_CONCPP_DIR)/lib64
LDLIBS = -lmysqlcppconn
CXX = clang++
CXXFLAGS = -std=c++11
app : app.cpp

