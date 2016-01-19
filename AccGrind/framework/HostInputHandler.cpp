
#include <iostream>
#include "HostInputHandler.h"

namespace AccGrind {
    HostInputHandler::HostInputHandler () {
    }
    HostInputHandler::~HostInputHandler () {}

    bool HostInputHandler::handleInput ( std::string& usrInput ) {
        Task task = getHostTaskFrom ( usrInput );
        if ( task ) {
            scheduleTask( task );
            std::vector<std::string>  optionVector;
            this->getOptions(optionVector);
            for ( auto a:optionVector ) {
                std::cout << a.c_str() << std::endl;
            }
        }else{
            if ( false == plugin_handleInput ( usrInput ) ) {
                // report error -- invalid input
                return false;
            }
        }
        return true;
    }
    Task HostInputHandler::getHostTaskFrom ( std::string & usrInput ) {
        Task newTask;
        std::cout << "Input handled : " << usrInput << std::endl;
        newTask = m_interpreter.interpret ( usrInput );
        return newTask;
    }
    void HostInputHandler::getOptions ( std::vector<std::string> & usrOptionVector ) {
        m_interpreter.getOptions(usrOptionVector);
    }
    void HostInputHandler::scheduleTask ( Task task){
        //m_hostTaskQueue.add ( task );
    }
    bool HostInputHandler::plugin_handleInput ( std::string&  ){
        return false
    }
}
