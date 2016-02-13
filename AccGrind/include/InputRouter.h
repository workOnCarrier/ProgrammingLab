#ifndef __INPUTROUTER_H__
#define __INPUTROUTER_H__

#include "keyInputSource.h"
#include "HostInputHandler.h"

namespace AccGrind {
    class InputRouter {
    public:
        InputRouter ( KeyInputSource &inputSrc, HostInputHandler &InputHandler );
        ~InputRouter ( );
        void process ();
    private:
        KeyInputSource      &m_InputSource;
        HostInputHandler    &m_InputHandler;
    };
}
#endif // __INPUTROUTER_H__
