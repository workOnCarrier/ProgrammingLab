#include "minus.h"
#include "plus.h"
#include "minus.h"
#include "div.h"
#include "multi.h"
#include <iostream>
using std::cout;
using std::endl;

double Minus::evaluate()
{
        return left->evaluate() - right->evaluate ();
}
bool Minus::isHigherPrecedence ( operatr* expr)
{
        return expr->checkHigherPrecedence ( this );
}


bool Minus::checkHigherPrecedence ( Plus *expr ) const
{
        cout << "Minus -- plus " << endl;
        return true;
}
bool Minus::checkHigherPrecedence ( Minus *expr ) const
{
        cout << "Minus -- minus " << endl;
        return true;
}
bool Minus::checkHigherPrecedence ( Multi *expr ) const
{
        cout << "Minus -- multi " << endl;
        return true;
}
bool Minus::checkHigherPrecedence ( Div *expr ) const
{
        cout << "Minus -- div " << endl;
        return true;
}
bool Minus::checkHigherPrecedence ( BrackStart *expr ) const
{
        cout << "Minus -- BrackStart " << endl;
        return false;
}
bool Minus::checkHigherPrecedence ( BrackEnd *expr ) const
{
        cout << "Minus -- BrackEnd " << endl;
        return false;
}

