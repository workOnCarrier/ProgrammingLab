#ifndef __MYPARSER_H__
#define __MYPARSER_H__

#include "token.h"
class Exp;

class Parser
{
public: 
     Exp* parseTokenList ( ListTokens &ListOfTokens);
};
#endif //__MYPARSER_H__
