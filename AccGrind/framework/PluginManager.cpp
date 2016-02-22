
#include "PluginManager.h"


namespace AccGrind{
    PluginManager::PluginManager(): m_PluginsEnumerated( false),m_PluginsLoaded(false);
    }
    PluginManager::~PluginManager(){
        // unload all plugins
    }
    void PluginManager::IdentifyPlugins(){
        // enumerate the plugins that can be loaded
    }
    void PluginManager::LoadPlugins(){
        // load the plugins as specified by the user
    }
    bool PluginManager::handleInput ( std::string& ) {
        // if plugins are not loaded
        // ** expected csv value showing plugin numbers to load
        // ** Load the plugins as required by the user
        // else
        // pass inputs to plugins using the plugin map
    }
    void PluginManager::getOptions ( std::vector<std::string> &optionCapture ) {
        // if plugins are not loaded
        // ** get names of all plugiuns
        // ** these are options to be selected
        // else
        // ** get options from each of the plugins
        // ** offset with counter of the plugin position
    }
}
