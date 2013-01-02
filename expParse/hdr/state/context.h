#ifndef __CONTEXT__H__
#define __CONTEXT__H__

#include <iostream>
#include <algorithm>
#include "expres.h"
#include "oper.h"
#include "utils.h"
#include "token.h"
//#include "ExpressionParsing.h"
#include "ExpFactory.h"
#include "state/startExp.h"
#include "state/halfExp.h"
#include "state/listEndExp.h"

using namespace std;

class context
{
                 typedef ListTokens::iterator PtrItem;
 public:
     ERROR_STATUS processToken ( void );
 
         void AddFullExpStack ( Exp *expression );
         void AddHalfExpStack ( operatr *expression );
         Exp* popFullExpStack ( );
         operatr* popHalfExpStack ( );
 
     void setStateStartExp();
     void setStateListEndExp ();
     void setStateHalfExp ( );
 
     context( PtrItem &startOfList, PtrItem &endOfList );
     ~context();
         bool IsEndOfList ( PtrItem const &tokenIter );
 private:
     state    *pCurrentState;
 private:
     ListTokens::iterator &currentToken ;
     ListTokens::iterator &pastlastToken ;
     
     operatrStack   partialExpStack;
     expStack   fullExpStack;
         Exp        *expression;
 
     // states created for rotation
     ListEndExpr      listEndExp;
     startExpr      startExp;
     halfExpr      halfExp;
 };
 
#endif //__CONTEXT__H__
