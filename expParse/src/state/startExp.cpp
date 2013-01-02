#include "state/startExp.h"
#include "state/context.h"
#include "expres.h"
#include "oper.h"

void startExpr::processToken ( ListTokens::iterator &currentToken, context *CtxPtr )
{
    // check if the call is by mistake
    if ( CtxPtr->IsEndOfList( currentToken ) )
    {
        cout << " Internal error " << endl;
        throw -3;
    }

        if ( BRACKET_START == currentToken->getTokenType() ) 
        {
                operatr *brack = ExpFactory::getOperatorExpression ( *currentToken );
                CtxPtr->AddHalfExpStack ( brack );
                return;
        }

        // else assuming the first token to be a number. and expecting the next token to be an operator
    Exp* Leftexpr = ExpFactory::getExpression ( *currentToken );
    currentToken++;
    if ( CtxPtr->IsEndOfList( currentToken ) ) { cout << "Incomplete expression " << endl; throw -2; }

    // next token is expected to be operator
        // TBD "("
    if ( OPERATOR != currentToken->getTokenType() ) { throw -1; }

    operatr *Node = NULL;
    Node = ExpFactory::getOperatorExpression ( *currentToken );
    Node->AddLeft ( Leftexpr );
    Leftexpr = NULL;

        // change the state to half expression and return
    currentToken++;
    CtxPtr->AddHalfExpStack ( Node );
        CtxPtr->setStateHalfExp ();
    return ;
}


