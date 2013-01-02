#ifndef __STATE_H__
#define __STATE_H__

#include "token.h"

class context;

class state
{
public:
     virtual void processToken ( ListTokens::iterator &currentToken, context *CtxPtr ) = 0;
};

#endif //__STATE_H__

