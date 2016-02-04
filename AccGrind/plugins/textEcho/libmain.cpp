#include "libmain.h"
#include <string>
#include "textInterpreter.h"

using namespace AccGrindPlugin;
AccGrind::IInterpreter<std::string>* getPluginInputHandler () {
    return new TextInterpreter ();
}


