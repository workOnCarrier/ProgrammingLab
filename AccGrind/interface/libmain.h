#include "IInterpreter.h"
#include <string>

extern "C"{
#define PLUGINHANDLER "getPluginInputHandler" 
#define DELETEPLUGIN "deletePluginInputHandler"
AccGrind::IInterpreter<std::string>* getPluginInputHandler ( );
void  deletePluginInputHandler ( void*);

}

