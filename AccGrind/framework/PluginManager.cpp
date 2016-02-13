#include "PluginManager.h"


namespace AccGrind{
    PluginManager::PluginManager(){
        // IdentifyPlugins
        m_PluginsEnumerated = true;
        // LoadPlugins
        m_PluginsLoaded = true;
    }
    PluginManager::~PluginManager();
    void PluginManager::IdentifyPlugins();
    void PluginManager::LoadPlugins();
    void PluginManager::getOptions ( std::vector<std::string>& ) ;
}
