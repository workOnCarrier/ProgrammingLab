#include "brackStart.h"
#include <iostream>
using std::cout;
using std::endl;

double BrackStart::evaluate ()
{
        return left->evaluate();
}
bool BrackStart::isHigherPrecedence ( operatr* expr)
{
        return expr->checkHigherPrecedence ( this );
}
bool BrackStart::checkHigherPrecedence ( Plus *expr ) const
{
        cout << "brackStart -- plus " << endl;
        return false;
}
bool BrackStart::checkHigherPrecedence ( Minus *expr ) const
{
        cout << "brackStart -- minus " << endl;
        return false;
}
bool BrackStart::checkHigherPrecedence ( Multi *expr ) const
{
        cout << "brackStart -- multi " << endl;
        return false;
}
bool BrackStart::checkHigherPrecedence ( Div *expr ) const
{
        cout << "brackStart -- div " << endl;
        return false;
}
bool BrackStart::checkHigherPrecedence ( BrackStart *expr ) const
{
        cout << "brackStart -- BrackStart " << endl;
        return false;
}
bool BrackStart::checkHigherPrecedence ( BrackEnd *expr ) const
{
        cout << "brackStart -- BrackEnd " << endl;
        return false;
}

