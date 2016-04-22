#ifndef __PLUGINLOADER_H__
#define __PLUGINLOADER_H__

#include "IInterpreter.h"
#include <map>
#include <string>
#include "libmain.h"
#ifdef WIN32
#include "windows.h"
#else
#endif

namespace AccGrind{
//***********************************
// PluginLoader
//      this class handles loading and unloading the libraries
//      Keeping this functionality in separate class allows for 
//      bringing in platform independence -- by implementing 
//      the header in different platform dependent files keeping 
//      rest of the code platform independent
//***********************************
#ifndef WIN32
typedef void* LibHandle      ;
typedef void* (*Handler)();
typedef void (*Deleter)(void*);
#else
typedef HMODULE LibHandle      ;
typedef FARPROC (*Handler)();
typedef FARPROC (*Deleter)(void*);
#endif
        typedef IInterpreter<std::string>   StringInterpreter;
        typedef std::shared_ptr<StringInterpreter>  StringInterpreterPtr;

    class PluginLoader{
    public:
        typedef std::shared_ptr<PluginLoader>   Ptr;

        PluginLoader(std::string& pluginName);
        ~PluginLoader();

        StringInterpreter*       load();
    private:
        void           unload();

        std::string             m_pluginName;
        LibHandle               m_pluginHandle;
        StringInterpreter*      m_interpretObj;
    };
}
#endif // __PLUGINLOADER_H__
