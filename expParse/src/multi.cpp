#include "multi.h"
#include "plus.h"
#include "minus.h"
#include "div.h"
#include "multi.h"
#include <iostream>
using std::cout;
using std::endl;

double Multi::evaluate()
{
    return this->right->evaluate() * this->left->evaluate();
}
bool Multi::isHigherPrecedence ( operatr* expr)
{
        return expr->checkHigherPrecedence ( this );
}

bool Multi::checkHigherPrecedence ( Plus *expr ) const
{
        cout << "multi - plus" << endl;
        return false;
}
bool Multi::checkHigherPrecedence ( Minus *expr ) const
{
        cout << "multi - Minus" << endl;
        return false;
}
bool Multi::checkHigherPrecedence ( Multi *expr ) const
{
        cout << "multi - multi" << endl;
        return true;
}
bool Multi::checkHigherPrecedence ( Div *expr ) const
{
        cout << "multi - div" << endl;
        return true;
}
bool Multi::checkHigherPrecedence ( BrackStart *expr ) const
{
        cout << "Multi -- BrackStart " << endl;
        return false;
}
bool Multi::checkHigherPrecedence ( BrackEnd *expr ) const
{
        cout << "Multi -- BrackEnd " << endl;
        return false;
}


