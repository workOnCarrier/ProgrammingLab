#ifndef __NUM_H__
#define  __NUM_H__

#include "expres.h"

class Num : public Exp
{
public:
         Num(double pvalue):value(pvalue){}
     virtual double evaluate();
private:
         double  value;
};
#endif  //__NUM_H__
