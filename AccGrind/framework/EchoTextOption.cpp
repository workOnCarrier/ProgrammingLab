#include "EchoTextOption.h"
#include "EchoTextTask.h"
#include <string>


namespace AccGrind{
    EchoTextOption::EchoTextOption (){
    }
    EchoTextOption::~EchoTextOption (){
    }
    std::string EchoTextOption::getOptionString ( )const {
        return "Echo text";
    }
    Task        EchoTextOption::getTask ( std::string& usrInput) const {
        Task newTask = std::make_shared<EchoTextTask>(usrInput);
        return newTask;
    }
}
