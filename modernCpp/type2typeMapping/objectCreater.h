#ifndef __OBJECTCREATER_H__
#define __OBJECTCREATER_H__

#include "legacy.h"

template <typename T>
class Type2Type
{
    typedef T OriginalType;
};

template <typename T, typename U>
T* create ( const U& argument, Type2Type<T> )
{
    return new T(argument);
}

template <typename U>
legacy* create ( const U &argument, Type2Type<legacy> )
{
    return new legacy(argument, -1);
}

#endif //__OBJECTCREATER_H__
