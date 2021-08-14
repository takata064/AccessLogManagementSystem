#ifndef _cppconn_HPP_
#define _cppconn_HPP_

#include<string>

using namespace std;

class cppconn
{
private:

public:
    string find_name(string macadd);
    bool find_device(string macadd);
    void add_entryemmber(string macadd);
    void delete_entrymember(string macadd);
    void add_log(string macadd);
};

#endif