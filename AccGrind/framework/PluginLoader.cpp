#include "PluginLoader.h"

namespace AccGrind{

    PluginLoader::PluginLoader() {}
    PluginLoader::~PluginLoader() {}

    IInterpreter<string>*   PluginLoader::load(std::string& pluginName) {
    }
    void                    PluginLoader::unload(std::string& pluginName){
    }
}
