#ifndef __EXPRESS_H__
#define __EXPRESS_H__

#include <stack>

using namespace std;

class Exp
{
public:
     Exp();
     virtual ~Exp();
     virtual double evaluate() = 0;
};
typedef stack<Exp*> expStack;
#endif // __EXPRESS_H__

