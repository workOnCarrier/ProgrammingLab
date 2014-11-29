

#include "legacy.h"
#include <iostream>

using namespace std;

legacy::legacy ( const std::string &name, int randomCount )
: m_objName(name), m_randomCount(randomCount)
{
    cout << "Legacy object created " << m_objName.c_str() << endl;
}

legacy::~legacy ( ) 
{
    cout << "Legacy object destroyed " << m_objName.c_str() << endl;
}
