#include "token.h"
#include <cstdio>

using namespace std;

Token::Token( string &tmpString, TOKEN_TYPE type)
{
    m_tokenString = tmpString;
        m_tokenType = type;
        printf("  %s is the string added for type %d\n", tmpString.c_str(), m_tokenType);

        //cout << "  " << tmpString << "is the string added" << endl;
}
Token::~Token()
{
}
string Token::getTokenString()
{
    return m_tokenString;
}
TOKEN_TYPE Token::getTokenType()
{
    return m_tokenType;
}
ostream& operator<< ( ostream &ios , Token &token)
{
    ios << token.m_tokenString.c_str()  << endl;
        return ios;
}
void Token::display()
{
    printf ( "%s\n", m_tokenString.c_str() );
}

