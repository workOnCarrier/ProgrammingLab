#ifndef __MULTI_H__
#define  __MULTI_H__

#include "oper.h"
#include "plus.h"
#include "minus.h"
#include "div.h"
#include "multi.h"
#include "brackStart.h"
#include "brackEnd.h"


class Multi : public operatr
{
public:
     virtual double evaluate();
         bool virtual isHigherPrecedence ( operatr* expr);
         virtual bool checkHigherPrecedence ( Plus *expr ) const ;
         virtual bool checkHigherPrecedence ( Minus *expr )const ;
         virtual bool checkHigherPrecedence ( Multi *expr )const ;
         virtual bool checkHigherPrecedence ( Div *expr )const ;
         virtual bool checkHigherPrecedence ( BrackEnd *expr )const ;
         virtual bool checkHigherPrecedence ( BrackStart *expr )const ;
 };
 #endif  //__MULTI_H__

