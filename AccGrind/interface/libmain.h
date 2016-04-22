#include "IInterpreter.h"
#include <string>

#ifdef WIN32
#ifdef DLLEXPORT
#define INTERFACE_EXPORT __declspec(dllexport)
#else
#define INTERFACE_EXPORT __declspec(dllimport)
#endif
#else
#define INTERFACE_EXPORT 
#endif

extern "C"{
#define PLUGINHANDLER "getPluginInputHandler" 
#define DELETEPLUGIN "deletePluginInputHandler"
INTERFACE_EXPORT AccGrind::IInterpreter<std::string>* getPluginInputHandler ( );
INTERFACE_EXPORT void  deletePluginInputHandler ( void*);

}

