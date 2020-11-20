#include <iostream>
#include "stdarg.h"

using namespace std;

int sum(int count,...)
{
    int sum1 = 0;
    va_list ap;
    va_start(ap,count);
    for(int i=0;i<count;i++)
    {
        sum1+= va_arg(ap,int);
    }
    va_end(ap);
    return sum1;
}

int budingcanshu()
{
    cout<<sum(4,2,3,4,5)<<endl;
    cout<<sum(4,2,2,2,2)<<endl;
    return 0;
}
