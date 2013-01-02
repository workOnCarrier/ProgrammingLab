#include "brackEnd.h"
#include <iostream>
using std::cout;
using std::endl;

double BrackEnd::evaluate()
{
        throw -1;
        return 0.0;
}
bool BrackEnd::isHigherPrecedence ( operatr* expr)
{
        return expr->checkHigherPrecedence ( this );
}
bool BrackEnd::checkHigherPrecedence ( Plus *expr ) const
{
        cout << "brackEnd -- plus " << endl;
        return false;
}
bool BrackEnd::checkHigherPrecedence ( Minus *expr ) const
{
        cout << "brackEnd -- minus " << endl;
        return false;
}
bool BrackEnd::checkHigherPrecedence ( Multi *expr ) const
{
        cout << "brackEnd -- multi " << endl;
        return false;
}
bool BrackEnd::checkHigherPrecedence ( Div *expr ) const
{
        cout << "brackEnd -- div " << endl;
        return false;
}
bool BrackEnd::checkHigherPrecedence ( BrackStart *expr ) const
{
        cout << "brackEnd -- BrackStart " << endl;
        return false;
}
bool BrackEnd::checkHigherPrecedence ( BrackEnd *expr ) const
{
        cout << "brackEnd -- BrackEnd " << endl;
        return false;
}

