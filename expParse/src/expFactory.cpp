//#include <stdlib>
#include "ExpFactory.h"
#include "oper.h"
#include "div.h"
#include "multi.h"
#include "plus.h"
#include "minus.h"
#include "num.h"
#include "brackStart.h"
#include "brackEnd.h"

#include <string.h>
#include <stdlib.h>


operatr* ExpFactory::getOperatorExpression ( Token &pToken )
{
    if ( OPERATOR == pToken.getTokenType() )
    {
            if ( 0 == strcmp ( pToken.getTokenString().c_str(), "+" ) )
                {
                    return new Plus();
                }else 
                if ( 0 == strcmp ( pToken.getTokenString().c_str(), "-" ) )
                {
                    return new Minus();
                } else
                if ( 0 == strcmp ( pToken.getTokenString().c_str(), "*" ) )
                {
                    return new Multi();
                } else
                if ( 0 == strcmp ( pToken.getTokenString().c_str(), "/" ) )
                {
                    return new Div();
                }
        cout << "Invalid token Operator" << endl;
                throw -1;
                return NULL;
    }
        throw -1;
        return NULL;
}
Exp* ExpFactory::getExpression ( Token &pToken )
{
    if ( NUMBER == pToken.getTokenType() )
    {
            double number = strtod(pToken.getTokenString().c_str(), NULL);
            return new Num( number );
    }
    else if ( BRACKET_START == pToken.getTokenType() )
    {
            return new BrackStart();
    }
    else if ( BRACKET_END == pToken.getTokenType() )
    {
            return new BrackEnd();
    }
        return getOperatorExpression ( pToken );
}

