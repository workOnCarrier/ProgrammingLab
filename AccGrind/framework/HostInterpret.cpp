#include "EchoTextOption.h"
#include "HostInterpret.h"
#include <string>

namespace AccGrind{
    HostInterpret::HostInterpret (){
        // instantiate options
        m_options.push_back ( std::make_shared<EchoTextOption>() );
    }
    HostInterpret::~HostInterpret (){
    }
    Task HostInterpret::interpret ( IInterpreter::InputType &textString ) {
        Task newTask;
        int optionNo = getOptionFromUsrInput(textString);
        if ( optionNo < m_options.size() ){
            newTask = m_options[optionNo]->getTask(textString);
        }
        return newTask;
    }
    int HostInterpret::getOptionFromUsrInput ( std::string& ) {
#pragma message ("TBD:->HostInterpret::getOptionFromUsrInput-- parsing logic to be implemented")
        return 0;
    }
    void HostInterpret::getOptions ( std::vector<std::string>& usrOptionVector) const {
#pragma message ("TBD:->HostInterpret::getOptions - hardcoded values to be updated later")
        usrOptionVector.push_back("Host::1: echo");
        usrOptionVector.push_back("Host::2: continue");
    }
}
