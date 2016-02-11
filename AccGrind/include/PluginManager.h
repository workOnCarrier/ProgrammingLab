#ifndef __PLUGINMANAGER_H__
#define __PLUGINMANAGER_H__
#include <vector>
#include <string>
namespace AccGrind{
    class PluginManager{
    public:
        PluginManager();
        ~PluginManager();
        void getOptions ( std::vector<std::string>& ) ;
    private:
        void IdentifyPlugins();
        void LoadPlugins();

        bool    m_PluginsEnumerated = false;
        bool    m_PluginsLoaded = false;
    };
}
#endif // __PLUGINMANAGER_H__
