#include "EchoTextOption.h"
#include "EchoTextTask.h"
#include <string>


namespace AccGrind{
    EchoTextOption::EchoTextOption ():m_optionString("Echo text"){
    }
    EchoTextOption::~EchoTextOption (){
    }
    std::string EchoTextOption::getOptionString ( )const {
        return m_optionString;
    }
    Task        EchoTextOption::getTask ( std::string const & usrInput) const {
        std::string  localUsrInput = usrInput;
        Task newTask = std::make_shared<EchoTextTask>(localUsrInput);
        return newTask;
    }
}
