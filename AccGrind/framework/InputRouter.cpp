
#include "InputRouter.h"
#include <iostream>

namespace AccGrind {
    InputRouter::InputRouter ( KeyInputSource &inputSrc, HostInputHandler &InputHandler ): m_InputSource(inputSrc), m_InputHandler(InputHandler){
    }
    InputRouter::~InputRouter ( ){}

    void InputRouter::process (){
        while ( m_InputSource.hasMoreData() ){
            std::vector<std::string>  optionVector;
            m_InputHandler.getOptions(optionVector);
            for ( auto a:optionVector ) {
                std::cout << a.c_str() << std::endl;
            }
            std::string usrInput = m_InputSource.getNextInput();
            bool isInputHandled = m_InputHandler.handleInput ( usrInput );
            if ( !isInputHandled ){
                std::cout << "Error: Input not supported:" << usrInput << std::endl;
            }// else {continue; // the loop }
        }
    }
}

