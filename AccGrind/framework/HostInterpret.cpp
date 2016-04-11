#include "HostInterpret.h"
#include "StartMyServOption.h"
#include <string>
#include <stdexcept>
#include "genUtils.h"

namespace AccGrind{
    HostInterpret::HostInterpret (){
    }
    HostInterpret::~HostInterpret (){
    }
    Task HostInterpret::interpret ( IInterpreter::InputType const &textString ) {
        Task newTask;
        newTask  = m_pluginManager.interpret(textString);
        if ( newTask ){
            return newTask;
        }
        UserInputSplit optionSplit = getOptionFromUsrInput(textString);
        if ( optionSplit.m_optionNo  >=0 && optionSplit.m_optionNo < m_options.size() ){
            newTask = m_options[optionSplit.m_optionNo]->getTask(optionSplit.m_optionInput);
        }
        return newTask;
    }

   void HostInterpret::getOptions ( std::vector<std::string>& usrOptionVector) const {
        for ( auto option : m_options ){
            usrOptionVector.push_back ( option->getOptionString() );
        }
        m_pluginManager.getOptions ( usrOptionVector );
    }
}
