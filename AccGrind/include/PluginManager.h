#ifndef __PLUGINMANAGER_H__
#define __PLUGINMANAGER_H__
#include <vector>
#include <string>
#include "IInputHandler.h"
namespace AccGrind{
    class PluginManager: public IInputHandler{
    public:
        PluginManager();
        ~PluginManager();
        virtual bool handleInput ( std::string& ) ;
        virtual void getOptions ( std::vector<std::string> & ) ;
    private:
        void IdentifyPlugins();
        void LoadPlugins();

        bool    m_PluginsEnumerated = false;
        bool    m_PluginsLoaded = false;
    };
}
#endif // __PLUGINMANAGER_H__
