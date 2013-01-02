#include "state/startExp.h"
#include "state/context.h"

void halfExpr::processToken ( ListTokens::iterator &currentToken, context *CtxPtr )
{
        if ( BRACKET_START == currentToken->getTokenType() ) 
        {
                operatr *expr = ExpFactory::getOperatorExpression ( *currentToken );
                CtxPtr->AddHalfExpStack ( expr );
                CtxPtr->setStateStartExp ();
                return;
        }
    if ( CtxPtr->IsEndOfList( currentToken ) )
        {
                cout << "EndOfList :  This is not expected in half expression object" << endl;
                throw -1;
        }
    Exp *Leftexpr = ExpFactory::getExpression ( *currentToken );
    currentToken++;
        // process end of token list
    if ( CtxPtr->IsEndOfList( currentToken ) )
    {
        // that means this is logical end of expresstion
                operatr *node = CtxPtr->popHalfExpStack ();
                if ( NULL == node )
                {
                    cout << " Internal Error expecting half expression to attach the last token" << endl;
                        throw -3;
                }
                node->AddRight ( Leftexpr );
                CtxPtr->AddFullExpStack ( node );
                CtxPtr->setStateListEndExp ( ) ;
                return ;
    }
        // Get next expression setup
        operatr *prevNode = CtxPtr->popHalfExpStack ();
        if ( prevNode == NULL ) { cout << "Expecting half expressions " << endl; throw -4; }
    operatr *node = ExpFactory::getOperatorExpression ( *currentToken );
        currentToken++;
        if ( BRACKET_END == currentToken->getTokenType() )
        {
        prevNode->AddRight ( Leftexpr );
                operatr *morePrevNode = CtxPtr->popHalfExpStack ();
                morePrevNode->AddLeft ( prevNode );
                morePrevNode->AddRight ( Leftexpr );
                CtxPtr->AddFullExpStack ( morePrevNode );
        }else 
        // This is only a operator otherwise we are having spurious expression
        // So assuming it to be only an operator
        if ( prevNode->isHigherPrecedence ( node ) )
        {
        prevNode->AddRight ( Leftexpr );
                node->AddLeft ( prevNode );
                CtxPtr->AddHalfExpStack ( node );
        Leftexpr = NULL;
                // we retain the current state
                return ;
        }
        else
        {
                CtxPtr->AddHalfExpStack ( prevNode );
                node->AddLeft ( Leftexpr );
                CtxPtr->AddHalfExpStack ( node );
        Leftexpr = NULL;
            return ;
        }
}


