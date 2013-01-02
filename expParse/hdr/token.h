#ifndef __TOKEN_H__
#define __TOKEN_H__

#include <list>
#include <iostream>
#include "utils.h"

using namespace std;
class ExpFactory;
class Token
{
public:
         Token( string &, TOKEN_TYPE );
         ~Token();
         TOKEN_TYPE getTokenType();
         void display();
         friend ostream& operator<< ( ostream &ios, Token &token ); 
 private:
     string getTokenString();
    string m_tokenString;
    TOKEN_TYPE m_tokenType;
 friend class ExpFactory;
};
typedef list<Token> ListTokens;

#endif // __TOKEN_H__
