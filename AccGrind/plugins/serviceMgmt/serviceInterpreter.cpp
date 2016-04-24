
#include <memory>
#include "serviceInterpreter.h"
#include "StartMyServOption.h"
#include <iostream>
#include "genUtils.h"

namespace AccGrindPlugin {
    ServiceInterPreter::ServiceInterPreter (){
        m_options.push_back ( std::make_shared<StartMyServOption>() );
    }
    ServiceInterPreter::~ServiceInterPreter (){
    }
    Task ServiceInterPreter::interpret ( std::string const &textString ){
        Task newTask;
        UserInputSplit optionSplit = getOptionFromUsrInput(textString);
        std::cout << "ServiceInterPreter::option received:" << optionSplit << std::endl;
        if ( optionSplit.m_optionNo >=0 && optionSplit.m_optionNo < m_options.size() ) {
            newTask = m_options[optionSplit.m_optionNo]->getTask(optionSplit.m_optionInput);
        }//else{}
        return newTask;
    }
    void ServiceInterPreter::getOptions ( std::vector<std::string>& vectorObj) const {
         for ( auto option : m_options ){
            vectorObj.push_back ( option->getOptionString() );
        }
    }

}
