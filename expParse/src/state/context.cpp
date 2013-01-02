#include "state/context.h"
#include "expres.h"
#include "state/state.h"
#include "state/listEndExp.h"
#include "state/halfExp.h"
#include "state/startExp.h"
//
// This is for validation of the expression formed
//
//#include "state/completeExp.h"


context::context( PtrItem &startOfList, PtrItem &endOfList ):
currentToken(startOfList),
pastlastToken ( endOfList )
{
        // current state is start
        pCurrentState = &startExp;
}
context::~context()
{
}

ERROR_STATUS context::processToken ( void )
{
        try{
        pCurrentState->processToken ( currentToken, this);
        }catch(...)
        {
                return FAILURE;
        }
        return SUCCESS;
}

void context::AddFullExpStack ( Exp *expression ) { fullExpStack.push ( expression ); }
void context::AddHalfExpStack ( operatr *expression ) { partialExpStack.push ( expression ); }

bool context::IsEndOfList ( PtrItem const &currToken )
{
        if ( currToken == pastlastToken ) 
        {
                        return true;
        }
        return false;
}

void context::setStateStartExp() { pCurrentState = &startExp; }
void context::setStateHalfExp () { pCurrentState = &halfExp; }
void context::setStateListEndExp ( ){ pCurrentState = &listEndExp; }

Exp* context::popFullExpStack ( )
{
        Exp *getTopOfStack;
        if ( 0 == fullExpStack.size() )
        {
                return NULL;
        }
        getTopOfStack = fullExpStack.top();
        fullExpStack.pop();
        return getTopOfStack;
}
operatr* context::popHalfExpStack ( )
{
        operatr * getTopOfStack;
        if ( 0 == partialExpStack.size() )
        {
                return NULL;
        }
        getTopOfStack = partialExpStack.top();
        partialExpStack.pop();
        return getTopOfStack;
}

