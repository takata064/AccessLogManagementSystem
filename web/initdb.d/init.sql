DROP DATABASE IF EXISTS eagis;
CREATE DATABASE eagis;
use eagis;
DROP TABLE IF EXISTS memberlist;
create table memberlist(
name varchar(40),
status varchar(40),
password varchar(50) 
)DEFAULT CHARACTER SET=utf8;
insert into memberlist (name,status,password) value("a","test","test");