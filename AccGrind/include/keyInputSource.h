#ifndef __KEYINPUTSOURCE_H__
#define __KEYINPUTSOURCE_H__

#include <string>
#include <cctype>
#include "iosource.h"

namespace AccGrind{
    class KeyInputSource : public IOHandler{
    public:
        typedef std::string        DataType;

        KeyInputSource():m_reading(true) {};

        virtual bool hasMoreData (){ return m_reading; }
        virtual std::string    getNextInput(){
            DataType dataItem;
            DataType upCasedataItem;
            char    userInput = '\0';
            for ( (userInput = (char)getchar()) ; EOF !=  userInput ; (userInput = (char)getchar()) )
            {
                //while ( ' ' != userInput && '\n' != userInput ){} // we take full line instead of word at a time
                while ( '\n' != userInput ){
                    dataItem += userInput;
                    upCasedataItem += std::toupper(userInput);
                    (userInput = (char)getchar());
                }
                if ( upCasedataItem == "^M" )
                {
                    m_reading = false;
                }
                break;
            }
            if ( userInput == (char) EOF )
            {
                m_reading = false;
            }
            return dataItem;
        }
        virtual std::ostream&       getOutputStream() {
            return std::cout ;
        }
    private:
        bool        m_reading;
    };
}
#endif // __KEYINPUTSOURCE_H__
