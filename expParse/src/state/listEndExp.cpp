#include "state/listEndExp.h"
#include "state/context.h"

void ListEndExpr::processToken ( ListTokens::iterator &currentToken, context *CtxPtr )
{
    if ( !CtxPtr->IsEndOfList( currentToken ) ) 
        {
                cout << " Not expecting anything in the list iterator for listEndExp class " << endl;
                throw -200 ;
        }
        operatr *node = CtxPtr->popHalfExpStack();
        Exp *Rightexpr = NULL;
        while ( NULL != node  )
        {
                Rightexpr = CtxPtr->popFullExpStack();
                node->AddRight ( Rightexpr );
                CtxPtr->AddFullExpStack ( node );
                node = CtxPtr->popHalfExpStack();
        }
    return;
}

