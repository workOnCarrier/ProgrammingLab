#define BOOST_FILESYSTEM_NO_DEPRECATED
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>
//#include <boost/progress.hpp>
#include "PluginManager.h"
#include <sstream>
#include "genUtils.h"

#include <iostream>


namespace AccGrind{
namespace fs = boost::filesystem;

    PluginManager::PluginManager(): m_PluginsEnumerated( false),m_PluginsLoaded(false){
    }
    PluginManager::~PluginManager(){
        // unload all plugins
    }
    void PluginManager::IdentifyPlugins() const{
        if (m_PluginsEnumerated==true) return;
        // enumerate the plugins that can be loaded
        fs::path full_path ( fs::initial_path<fs::path>() );
        if ( !fs::exists(full_path) ){
#pragma message ( "TBD::PluginManager::IdentifyPlugins  --- throw exception for non obtainable full path" )
        }
        if ( fs::is_directory(full_path) ){
            fs::directory_iterator endIter;
            for ( fs::directory_iterator dirIter(full_path); dirIter != endIter; ++dirIter ){
                try{
                    if ( fs::is_directory ( dirIter->status() ) ){
                        continue;
                    }else if ( fs::is_regular_file ( dirIter->status() ) ){
                        // interesting
                        // checking if it is an so / dll 
                        std::string fileName = dirIter->path().string();
                        if ( true == isFileNamePlugin ( fileName ) ){
                            m_eligibleFiles.push_back ( fileName );
                        }
                    }
                    else{
                        // could by symbolic link / device /etc... not interested in this version
                    }
                }catch( const std::exception &e ){

                    throw;
                }
            }
        }
        m_PluginsEnumerated = true;
    }
    bool PluginManager::isFileNamePlugin ( std::string &fileName ) const{
        // potential improvement opportunity -- use regular expressions
#ifdef WIN32
        std::string::size_type pos = fileName.find(".dll");
#else
        std::string::size_type pos = fileName.find(".so");
#endif        
        if( std::string::npos != pos ){
            return true;
        }else{
            return false;
        }
    }
    void PluginManager::LoadPlugins(){
             int pluginPos = 1;
            for ( auto plugin : m_eligibleFiles ){
                PluginLoader::Ptr pluginPtr = std::make_shared<PluginLoader>(plugin);
                StringInterpreter* strInterPtr = pluginPtr->load();
                m_Interpreters.insert ( std::make_pair(pluginPos++,strInterPtr) );
                m_plugins.push_back ( pluginPtr );
            }
            m_PluginsLoaded = true ;
        // load the plugins as specified by the user
    }
    Task PluginManager::interpret ( InputType const &input ) {
        if ( m_PluginsLoaded != true ){
            // as a temporary measure, load all plugins
            auto loader = [&](void)->void {
                //std::cout << "Loading plugins" << std::endl;
                this->LoadPlugins();
            };
            std::function<void(void)>   loaderFunction(loader);
            return std::make_shared<LoadPluginTask> ( loaderFunction );
        }else{
            std::string  pluginId = getFirstPart ( input) ;
            UserInputSplit  optionSplit = getOptionFromUsrInput  ( input );
           auto pos = m_Interpreters.find ( optionSplit.m_optionNo );
            if ( pos != m_Interpreters.end() ){
                return pos->second->interpret ( input );
            }
            return Task();
        }
    }
    void PluginManager::getOptions ( std::vector<std::string> &optionCapture ) const {
        // if plugins are not loaded
        if ( m_PluginsEnumerated != true ){
            // ** get names of all plugiuns
            IdentifyPlugins();
            // ** these are options to be selected
            int num = 0;
            for ( auto plugin : m_eligibleFiles ){
                std::stringstream  option ;
                option << num << ":";
                option << plugin;
                std::cout << " --- identified file name :" << option.str().c_str() << std::endl;
                optionCapture.push_back ( option.str() );
            }
            std::stringstream optionAll ;
            optionAll << ++num <<":" << " All to be done ";
            optionCapture.push_back ( optionAll.str() );
        } else if ( m_PluginsLoaded == true ) {
            // ** get options from each of the plugins
            for ( auto pair : m_Interpreters ) {
                std::vector<std::string>    pluginOptions;
                std::cout << " Getting options from plugin:" << std::endl;
                pair.second->getOptions ( pluginOptions );
                std::cout << " obtained options from plugin:" << pluginOptions.size() << std::endl;
                for ( auto optionStr : pluginOptions ){
                    std::stringstream option  ;
                    option << pair.first << "." << optionStr;
                    optionCapture.push_back ( option.str() );
                }
            }
        } else {
            throw "Plugins are enumerated but not loaded";
        }
    }
}
