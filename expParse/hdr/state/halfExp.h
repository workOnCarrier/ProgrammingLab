#ifndef __HALFEXP_H__
#define __HALFEXP_H__

#include "state/state.h"
class halfExpr : public state
{
     virtual void processToken ( ListTokens::iterator &currentToken, context *CtxPtr );
};
#endif //__HALFEXP_H__

