

#include "myNew.h"
#include <iostream>

using std::cout;
using std::endl;

myNew::myNew ( const std::string& name )
:legacy ( name, -1 )
{
    cout << "myNew object created" << endl;
}

myNew::~myNew ( )
{
    cout << "myNew object destroyed" << endl;
}
