#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include "expres.h"
#include "utils.h"
#include "token.h"
//#include "ExpressionParsing.h"
#include "state/context.h"

using namespace std;
ERROR_STATUS parseCommandLine ( int argc, char** argv, Exp *expression   );
ERROR_STATUS appendToTokenList ( char* tobeTokenized, ListTokens &listOfTokens );
void displayTokens ( Token & );
ERROR_STATUS populateExpression ( ListTokens &listOfTokens , Exp ** expression );

int main(int argc, char** argv)
{
        Exp *expression = NULL;
        int ret_val = FAILURE;
        for ( int argmnts = 0; argmnts < argc; argmnts++ )
        {
            cout << argv[argmnts] << endl;
        }
        ret_val = parseCommandLine ( argc, argv, expression );
        if ( SUCCESS != ret_val )
        {
                cout << "This is not a valid expression " << endl;
        }
        if ( NULL == expression )
        {
                return -1;
        }
        return (int)(expression->evaluate());
}
ERROR_STATUS parseCommandLine ( int argc, char** argv, Exp *expression )
{
    ListTokens tokenList ;
    // form a token list based on expression parsing logic
        for ( int argcount = 1; argcount < argc; argcount++ )
        {
        if ( SUCCESS != appendToTokenList ( argv [ argcount ], tokenList ) )
                {
                for_each ( tokenList.begin(), tokenList.end(), displayTokens );
                    return FAILURE;
                }
        }
        for_each ( tokenList.begin(), tokenList.end(), displayTokens );
        // form an expression tree based on the tokens from the token list
        if ( SUCCESS != populateExpression ( tokenList, &expression ) )
        {
                cout << " Error in expression parsing " << endl;
        }
        double value = expression->evaluate();
        cout << " The value of the expression is "<< value << endl;
        //expression = NULL;
    return SUCCESS;
}
ERROR_STATUS appendToTokenList ( char* tobeTokenized, ListTokens &listOfTokens )
{
    char*       carray = new char [ strlen ( tobeTokenized ) + 1 ];
        int             currentCount  = 0;
        string  tmpString;

        memset ( carray, 0, strlen(carray) );
    while ( '\0' != *tobeTokenized )
        {
            carray[ currentCount ] = *tobeTokenized;
                if ( carray [ currentCount ] == ' ' ||
                     carray [ currentCount ] == '\t' )
                {
                    continue;
                }
                if ( carray [ currentCount ] == '0' ||
                          carray [ currentCount ] == '1' ||
                          carray [ currentCount ] == '2' ||
                          carray [ currentCount ] == '3' ||
                          carray [ currentCount ] == '4' ||
                          carray [ currentCount ] == '5' ||
                          carray [ currentCount ] == '6' ||
                          carray [ currentCount ] == '7' ||
                          carray [ currentCount ] == '8' ||
                          carray [ currentCount ] == '9' ||
                          carray [ currentCount ] == '.')
                {
                        tobeTokenized++;
                        currentCount++;
                        continue;
                }
                else if ( carray [ currentCount ] == '+' ||
                     carray [ currentCount ] == '-' ||
                     carray [ currentCount ] == '/' ||
                     carray [ currentCount ] == '{' ||
                     carray [ currentCount ] == '}' ||
                     carray [ currentCount ] == '(' ||
                     carray [ currentCount ] == ')' ||
                     carray [ currentCount ] == '*' )
                {
                    if ( 0 != currentCount )
                        {
                    carray [ currentCount ] = '\0';
                                tmpString = carray;
                    listOfTokens.push_back ( Token ( tmpString, NUMBER ) );
                            currentCount = 0;
                    carray[ currentCount ] = *tobeTokenized;
                                continue;
                        }
                        else if (carray [ currentCount ] == '+' ||
                             carray [ currentCount ] == '-' ||
                             carray [ currentCount ] == '/' ||
                             carray [ currentCount ] == '*' )
                        {
                    carray[ currentCount+1 ] = '\0';
                                tmpString = carray;
                    listOfTokens.push_back ( Token ( tmpString, OPERATOR ) );
                        tobeTokenized++;
                        continue;
                        }
                        else if ( carray [ currentCount ] == '{' ||
                             carray [ currentCount ] == '(' )
                        {
                    carray[ currentCount+1 ] = '\0';
                                tmpString = carray;
                        listOfTokens.push_back ( Token ( tmpString, BRACKET_START) );
                            tobeTokenized++;
                            continue;
                        }
                        else if ( carray [ currentCount ] == '}' ||
                             carray [ currentCount ] == ')' )
                        {
                    carray[ currentCount+1 ] = '\0';
                                tmpString = carray;
                        listOfTokens.push_back ( Token ( tmpString, BRACKET_END) );
                            tobeTokenized++;
                            continue;
                        }
                        else
                        {
                            //cout << " Unidentified character sequence " << carray << endl;
                            printf( " Unidentified character sequence %s\n" , carray );
                        return FAILURE;
                        }
                }
                else
                {
                    return FAILURE;
                }
        }
        if ( 0 != currentCount )
        {
            carray[ currentCount+1 ] = '\0';
                tmpString = carray;
        listOfTokens.push_back ( Token ( tmpString, NUMBER ) );
        }
    return SUCCESS;
}
void displayTokens ( Token &token)
{
    printf( " Token ");
        token.display();
}
ERROR_STATUS populateExpression ( ListTokens &listOfTokens , Exp ** expression )
{
    ListTokens::iterator currentToken = listOfTokens.begin();
    ListTokens::iterator pastlastToken = listOfTokens.end();
    ERROR_STATUS processStatus = SUCCESS ;

        context contextObj( currentToken, pastlastToken );

    while ( !contextObj.IsEndOfList(currentToken) && processStatus == SUCCESS )
    {
                processStatus = contextObj.processToken();
    }
        contextObj.setStateListEndExp ();
        processStatus = contextObj.processToken ();
        if ( processStatus != SUCCESS ) 
        {
                return processStatus;
        }
        *expression = (contextObj.popFullExpStack());
        return SUCCESS;
}

