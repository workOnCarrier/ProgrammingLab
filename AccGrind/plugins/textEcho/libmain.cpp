#include "libmain.h"
#include <string>
#include "textInterpreter.h"

using namespace AccGrindPlugin;

#pragma message ("exporting as C api : getPluginInputHandler ")

extern "C"{
    AccGrind::IInterpreter<std::string>* getPluginInputHandler () {
        return new TextInterpreter ();
    }
    void  deletePluginInputHandler ( void* ptr)
    {
        AccGrind::IInterpreter<std::string>* actualPtr = reinterpret_cast<AccGrind::IInterpreter<std::string>*> (ptr); 
        delete(actualPtr);
    }

}

