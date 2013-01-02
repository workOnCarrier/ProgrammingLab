#include "plus.h"
#include "plus.h"
#include "minus.h"
#include "div.h"
#include "multi.h"
#include <iostream>
using std::cout;
using std::endl;

double Plus::evaluate()
{
    return right->evaluate() + left->evaluate();
}
bool Plus::isHigherPrecedence ( operatr* expr)
{
        return expr->checkHigherPrecedence ( this );
}

bool Plus::checkHigherPrecedence ( Plus *expr ) const
{
        cout << "Plus -- plus " << endl;
        return true;
}
bool Plus::checkHigherPrecedence ( Minus *expr ) const
{
        cout << "Plus -- minus " << endl;
        return true;
}
bool Plus::checkHigherPrecedence ( Multi *expr ) const
{
        cout << "Plus -- multi " << endl;
        return true;
}
bool Plus::checkHigherPrecedence ( Div *expr ) const
{
        cout << "Plus -- div " << endl;
        return true;
}
bool Plus::checkHigherPrecedence ( BrackStart *expr ) const
{
        cout << "Plus -- BrackStart " << endl;
        return false;
}
bool Plus::checkHigherPrecedence ( BrackEnd *expr ) const
{
        cout << "Plus -- BrackEnd " << endl;
        return false;
}

