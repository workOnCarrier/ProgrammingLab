#include "StartMyServOption.h"
#include "StartServiceTask.h"


namespace AccGrind {
    StartMyServOption::StartMyServOption():m_optionString("start service dummyService"){
    }
    StartMyServOption::~StartMyServOption(){
    }
    std::string StartMyServOption::getOptionString ( )const {
        return m_optionString;
    }
    Task        StartMyServOption::getTask ( std::string& usrInput) const {
        Task newTask = std::make_shared<StartServiceTask>(usrInput);
        return newTask;
    }
}
