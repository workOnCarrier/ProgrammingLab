#include "genUtils.h"
#include <stdexcept>
#include <exception>



namespace AccGrind{

    std::string getFirstPart ( std::string const & usrInput){
        // assuming following behavior from users
        // different oformats from usrs are
        // _1_: " *## *"  -- 0 or more occurences of space
        // _2_: " *##:[A-Za-z0-9]*"
        // _3_: " *## :[A-Za-z0-9]*"
        // _4_: " *##: [A-Za-z0-9]*"
        // _5_: " *## *[A-Za-z0-9]*"
        // from these formats, we need to take out the number ## 
        const std::string   delimiters ("|: ;,");
        std::string  firstPart ;
        int pos = 0;
        // skip leading spaces
        while ( ' ' == usrInput[pos] ){++pos; }
        std::string trimedInput = usrInput.substr(pos);
        int minFound = 0; 
        for ( size_t delpos = 0; delpos < delimiters.length(); delpos++ ){
            int newPos = 0;
            newPos = ( trimedInput.find(delimiters[delpos]) == std::string::npos ) ? -1 : (trimedInput.find(delimiters[delpos]));
            if ( newPos != -1 && (newPos < minFound || minFound==0) ) {
                minFound = newPos;
            }
        }
        if ( 0 != minFound ){
            firstPart  = usrInput.substr ( pos, minFound );
        }else{
            firstPart  = usrInput.substr ( pos );
        }
        return firstPart ;
    }
    UserInputSplit getOptionFromUsrInput ( std::string const & usrInput){
        UserInputSplit optionSplit ;
        std::size_t conversionCount = 0;
        try{
            optionSplit.m_optionNo = std::stoi ( usrInput, &conversionCount  );
            std::string optionInput = usrInput.substr ( conversionCount, usrInput.length()-conversionCount );
            while ( optionInput.length() > 0 &&
                        ( optionInput[0] == ' ' || optionInput[0] == ':'|| optionInput[0] == '.'
                          || optionInput[0] == ';' || optionInput[0] == ',' )
                   ) {
                optionInput = optionInput.substr( 1, optionInput.length()-1);
            }
            optionSplit.m_optionInput = optionInput ;
        }catch (std::invalid_argument &e){
        }catch ( std::out_of_range &e){
        }catch (...){
        }
        return optionSplit ;
    }
}
