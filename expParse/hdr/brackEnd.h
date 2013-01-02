#ifndef __BRACKEND_H__
#define  __BRACKEND_H__

#include "oper.h"
#include "plus.h"
#include "minus.h"
#include "div.h"
#include "multi.h"
#include "brackStart.h"
#include "brackEnd.h"

class BrackEnd : public operatr
{
public:
    virtual double evaluate();
    bool virtual isHigherPrecedence ( operatr* expr);
    virtual bool checkHigherPrecedence ( Plus *expr ) const;
    virtual bool checkHigherPrecedence ( Minus *expr )const;
    virtual bool checkHigherPrecedence ( Multi *expr )const;
    virtual bool checkHigherPrecedence ( Div *expr )const;
    virtual bool checkHigherPrecedence ( BrackEnd *expr )const;
    virtual bool checkHigherPrecedence ( BrackStart *expr )const;
};
#endif  //__BRACKEND_H__

