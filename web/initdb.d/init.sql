DROP DATABASE IF EXISTS eagis;
CREATE DATABASE eagis;
use eagis;
DROP TABLE IF EXISTS memberlist;
DROP TABLE IF EXISTS devicelist;
DROP TABLE IF EXISTS entrylist;
DROP TABLE IF EXISTS log;
create table memberlist(
name varchar(80) primary key,
status varchar(40),
password varchar(50) 
)DEFAULT CHARACTER SET=utf8;

create table devicelist(
amac varchar(80) primary key,
device varchar(40),
name varchar(80) 
)DEFAULT CHARACTER SET=utf8;

create table entrylist(
amac varchar(40) primary key,
name varchar(80),
entrytime datetime,
updatetime datetime,
room varchar(8)
)DEFAULT CHARACTER SET=utf8;

create table log(
amac varchar(40),
name varchar(80),
entrytime datetime,
exittime datetime,
room varchar(8)
)DEFAULT CHARACTER SET=utf8;

insert into memberlist value("高田","学部生","test");
insert into memberlist value("西田","教授","test");
insert into memberlist value("鎌田","院生","test");

insert into devicelist value("wdqdqwdqwdqwdqdqwevv","iPhone","高田");
insert into devicelist value("qwdqdwvhhtthwevv","iPhone","西田");
insert into devicelist value("abvwscwewcdqwdqwdqdqwevv","Andoroid","鎌田");

insert into entrylist value("wdqdqwdqwdqwdqdqwevv","高田","2020-12-24 12:12:53","2020-12-24 12:22:53","111");
insert into entrylist value("qwdqdwvhhtthwevv","西田","2020-12-24 12:12:53","2020-12-24 12:22:53","111");
insert into entrylist value("abvwscwewcdqwdqwdqdqwevv","鎌田","2020-12-24 12:12:53","2020-12-24 12:22:53","111");

insert into log value("wdqdqwdqwdqwdqdqwevv","高田","2020-12-24 12:12:53","2020-12-24 12:22:53","111");
insert into log value("qwdqdwvhhtthwevv","西田","2020-12-24 12:12:53","2020-12-24 12:22:53","111");
insert into log value("abvwscwewcdqwdqwdqdqwevv","鎌田","2020-12-24 12:12:53","2020-12-24 12:22:53","111");
