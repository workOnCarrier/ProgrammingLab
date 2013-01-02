#ifndef __FULLEXP_H__
#define __FULLEXP_H__

#include "state.h"
class ListEndExpr : public state
{
virtual void processToken ( ListTokens::iterator &currentToken, context *CtxPtr );
};

#endif //__FULLEXP_H__

