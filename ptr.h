#pragma once
#include "common.h"
class Test
{
public:
    Test(string s)
    {
        str = s;
        cout << "Test creat\n";
    }
    ~Test()
    {
        cout << "Test delete:" << str << endl;
    }
    string& getStr()
    {
        return str;
    }
    void setStr(string s)
    {
        str = s;
    }
    void print()
    {
        cout << str << endl;
    }
private:
    string str;
};


