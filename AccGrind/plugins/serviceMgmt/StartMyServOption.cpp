#include "StartMyServOption.h"
#include "StartServiceTask.h"

const std::string optionString = 
" -->1. Start Service \
  -->2. Stop Service \
  -->3. kill process \
  -->4. check status";
namespace AccGrind {
    StartMyServOption::StartMyServOption():m_optionString(optionString){
    }
    StartMyServOption::~StartMyServOption(){
    }
    std::string StartMyServOption::getOptionString ( )const {
        return m_optionString;
    }
    Task        StartMyServOption::getTask ( std::string const& usrInput) const {
        std::string  localUsrInput = usrInput;
        Task newTask = std::make_shared<StartServiceTask>( localUsrInput );
        return newTask;
    }
}
