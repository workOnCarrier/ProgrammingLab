#ifndef __EXPFACTORY_H__
#define __EXPFACTORY_H__
#include <iostream>
#include "utils.h"
#include "token.h"
//#include "expres.h"
using namespace std;
class Exp;
class operatr;
class ExpFactory
{
public:
    static Exp* getExpression ( Token &pToken );
    static operatr* getOperatorExpression ( Token &pToken );
};
#endif //__EXPFACTORY_H__

