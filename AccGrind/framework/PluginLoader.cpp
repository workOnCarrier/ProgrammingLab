#include <dlfcn.h>
#include "PluginLoader.h"
#include <iostream>

namespace AccGrind{
#ifndef WIN32
    PluginLoader::PluginLoader(std::string& pluginName):m_pluginName(pluginName),m_pluginHandle(NULL),m_interpretObj(NULL) {
        m_pluginHandle = dlopen ( pluginName.c_str(), RTLD_NOW );
        if ( ! m_pluginHandle ){
            // log -- successfully not loaded library
#pragma message (" potentially throw exception here " )
        }else{
            // log -- load library successful
        }
    }
    PluginLoader::~PluginLoader() {}

    IInterpreter<std::string>*   PluginLoader::load() {
        if ( m_pluginHandle ){
            Handler handler = (Handler) dlsym ( m_pluginHandle, PLUGINHANDLER );
            const char* findFunctionError = dlerror();
            if ( findFunctionError ){
                // log error findFunctionError 
            }else{ }
            AccGrind::IInterpreter<std::string>* m_interPretObj = reinterpret_cast<AccGrind::IInterpreter<std::string>*>(  handler( ) );
            if  ( NULL == m_interPretObj ){
#pragma message ( " TBD --> PluginLoader::load throw exception " )
            }
        }
        return m_interpretObj;
    }
    void    PluginLoader::unload(){
        // delete the member object
        Deleter delhandler =  (Deleter ) dlsym( m_pluginHandle, DELETEPLUGIN );
        const char* findFunctionError = dlerror();
        if ( findFunctionError ){
#pragma message ("Nitin TBD::: --  PluginLoader::unload add to logg" )
            std::cout << "Cannot load the symbol 'deletePluginInputHandler' due to :"<< findFunctionError << std::endl;
        }else{
            std::cout << "Successfully loaded the symbol 'detelePluginInputHandler'"<< std::endl;
        }
        std::cout << " Deleteing the object " << std::endl;
        delhandler(m_interpretObj);
        // unload the library
        std::cout << " Unloading the library:"<< m_pluginName.c_str() << std::endl;
        dlclose(m_pluginHandle);
    }
#endif //WIN32
}
