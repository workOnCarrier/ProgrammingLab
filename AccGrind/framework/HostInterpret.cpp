#include "EchoTextOption.h"
#include "HostInterpret.h"
#include "StartMyServOption.h"
#include <string>
#include <stdexcept>

namespace AccGrind{
    HostInterpret::HostInterpret (){
        // instantiate options
        //m_options.push_back ( std::make_shared<EchoTextOption>() );
        //m_options.push_back ( std::make_shared<StartMyServOption>() );
    }
    HostInterpret::~HostInterpret (){
    }
    Task HostInterpret::interpret ( IInterpreter::InputType const &textString ) {
        Task newTask;
        newTask  = m_pluginManager.interpret(textString);
        if ( newTask ){
            return newTask;
        }
        size_t optionNo = getOptionFromUsrInput(textString);
        if ( optionNo >=0 && optionNo < m_options.size() ){
            newTask = m_options[optionNo]->getTask(textString);
        }
        return newTask;
    }
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
    int HostInterpret::getOptionFromUsrInput ( std::string const & usrInput) {
        int optionNumber = -1;
        std::string firstPart = getFirstPart ( usrInput);
        try{
            optionNumber = stoi( firstPart );
        }catch (std::invalid_argument &e){
        }catch ( std::out_of_range &e){
        }catch (...){
        }
        return optionNumber ;
    }
    void HostInterpret::getOptions ( std::vector<std::string>& usrOptionVector) const {
        for ( auto option : m_options ){
            usrOptionVector.push_back ( option->getOptionString() );
        }
        m_pluginManager.getOptions ( usrOptionVector );
    }
}
