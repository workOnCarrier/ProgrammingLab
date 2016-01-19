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
        Task getHostTaskFrom ( std::string & );
        void scheduleTask ( Task );
        bool plugin_handleInput ( std::string&  );

        HostInterpret m_interpreter;
    };
}
#endif // __HOSTINPUTHANDLER_H__
