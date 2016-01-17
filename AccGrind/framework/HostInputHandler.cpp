
#include <iostream>
#include "HostInputHandler.h"

namespace AccGrind {
    HostInputHandler::HostInputHandler () {
    }
    HostInputHandler::~HostInputHandler () {}
    bool HostInputHandler::handleInput ( std::string& usrInput ) {
        std::cout << "Input handled : " << usrInput << std::endl;
        std::vector<std::string>  optionVector;
        this->getOptions(optionVector);
        for ( auto a:optionVector ) {
            std::cout << a.c_str() << std::endl;
        }
        return true;
    }
    void HostInputHandler::getOptions ( std::vector<std::string> & usrOptionVector ) {
        usrOptionVector.push_back("Host:: 1: continue");
        usrOptionVector.push_back("Host:: 2: continue");
        usrOptionVector.push_back("Host:: 3: continue");
        usrOptionVector.push_back("Host:: 4: continue");
    }
}
