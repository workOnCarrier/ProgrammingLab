#ifndef __STARTEXP_H__
#define __STARTEXP_H__

#include "state.h"
class startExpr :public state
{
     virtual void processToken ( ListTokens::iterator &currentToken, context *CtxPtr );
};

#endif //__STARTEXP_H__

