#ifndef __HOSTINPUTHANDLER_H__
#define __HOSTINPUTHANDLER_H__

#include "IInputHandler.h"

namespace AccGrind {
    class HostInputHandler : public IInputHandler {
    public:
        HostInputHandler ();
        ~HostInputHandler ();
        virtual bool handleInput ( std::string& );
        virtual void getOptions ( std::vector<std::string> & );
    private:
    };
}
#endif // __HOSTINPUTHANDLER_H__
