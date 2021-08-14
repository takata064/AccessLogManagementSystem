#include<iostream>
#include<string>

#include"cppconn.hpp"

using namespace std;

int main(){
    string name="a",res;

    cppconn con;

    res=con.find_name(name);

    cout<<res<<endl;
}