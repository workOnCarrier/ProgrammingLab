#ifndef __OPER_H__
#define __OPER_H__

#include "expres.h"
class Plus;
class Minus;
class Multi;
class Div;
class BrackEnd;
class BrackStart;

class operatr : public Exp
{
public:
         operatr ();
         bool virtual isHigherPrecedence ( operatr* expr) = 0;
     virtual double evaluate() ;
 public:
         virtual bool checkHigherPrecedence ( Plus *expr ) const =0;
         virtual bool checkHigherPrecedence ( Minus *expr ) const =0;
         virtual bool checkHigherPrecedence ( Multi *expr ) const =0;
         virtual bool checkHigherPrecedence ( Div *expr ) const =0;
         virtual bool checkHigherPrecedence ( BrackEnd *expr ) const =0;
         virtual bool checkHigherPrecedence ( BrackStart *expr ) const =0;
 
     void AddRight(Exp* node);
     void AddLeft(Exp* node);
 protected:
     Exp* right;
     Exp* left;
};
typedef stack<operatr*> operatrStack;
#endif //__OPER_H__

