#ifndef __PLUGINLOADER_H__
#define __PLUGINLOADER_H__

#include "IInterpreter.h"
#include <map>
#include <string>

namespace AccGrind{
//***********************************
// PluginLoader
//      this class handles loading and unloading the libraries
//      Keeping this functionality in separate class allows for 
//      bringing in platform independence -- by implementing 
//      the header in different platform dependent files keeping 
//      rest of the code platform independent
//***********************************
    class PluginLoader{
    public:
        PluginLoader();
        ~PluginLoader();

        IInterpreter<string>*   load(std::string& pluginName);
        void                    unload(std::string& pluginName);
    private:
        struct {
            LibHandle  pluginHandle;
            IInterpreter<string>*   pluginInterpreter;
        }PluginDetail;
        std::map<std::string,PluginDetail>     m_pluginStore;
    };
}
#endif // __PLUGINLOADER_H__
