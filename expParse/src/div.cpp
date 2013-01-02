#include "div.h"
#include "plus.h"
#include "minus.h"
#include "div.h"
#include "multi.h"
#include <iostream>
using std::cout;
using std::endl;

double Div::evaluate()
{
    return right->evaluate() / left->evaluate();
}
bool Div::isHigherPrecedence ( operatr* expr)
{
        return expr->checkHigherPrecedence ( this );
}

bool Div::checkHigherPrecedence ( Plus *expr ) const
{
        cout << "Div -- plus " << endl;
        return false;
}
bool Div::checkHigherPrecedence ( Minus *expr ) const
{
        cout << "Div -- minus " << endl;
        return false;
}
bool Div::checkHigherPrecedence ( Multi *expr ) const
{
        cout << "Div -- multi " << endl;
        return false;
}
bool Div::checkHigherPrecedence ( Div *expr ) const
{
        cout << "Div -- div " << endl;
        return true;
}
bool Div::checkHigherPrecedence ( BrackStart *expr ) const
{
        cout << "Div -- BrackStart " << endl;
        return false;
}
bool Div::checkHigherPrecedence ( BrackEnd *expr ) const
{
        cout << "Div -- BrackEnd " << endl;
        return false;
}


