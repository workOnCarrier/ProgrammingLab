
#include "InputRouter.h"

namespace AccGrind {
    InputRouter::InputRouter ( KeyInputSource &inputSrc, HostInputHandler &InputHandler ): m_InputSource(inputSrc), m_InputHandler(InputHandler){
    }
    InputRouter::~InputRouter ( ){}

    void InputRouter::process (){
        while ( m_InputSource.hasMoreData() ){
            std::string usrInput = m_InputSource.getNextInput();
            m_InputHandler.handleInput ( usrInput );
        }
    }
}

