
#include <memory>
#include "textInterpreter.h"
#include "specialTextTask.h"
#include "textTask.h"
#include <iostream>
#include "genUtils.h"

namespace AccGrindPlugin {
    TextInterpreter::TextInterpreter ( ) {
        m_options.push_back ( std::make_shared<SpecialTextOption>() );
        m_options.push_back ( std::make_shared<TextOption>() );
    }

    TextInterpreter::~TextInterpreter ( ) {
        std::cout << "deleting the interpreter object " << std::endl;
    }

    Task TextInterpreter::interpret ( std::string const &textString ) {
        Task newTask;
        UserInputSplit optionSplit = getOptionFromUsrInput(textString);
        if ( optionSplit.m_optionNo  >=0 && optionSplit.m_optionNo < m_options.size() ){
            newTask = m_options[optionSplit.m_optionNo]->getTask(optionSplit.m_optionInput);
        }
        return newTask;
    }
     void TextInterpreter::getOptions ( std::vector<std::string>& vectorObj) const {
         for ( auto option : m_options ){
            vectorObj.push_back ( option->getOptionString() );
         }
     }
}
