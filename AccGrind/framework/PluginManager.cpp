#define BOOST_FILESYSTEM_NO_DEPRECATED
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>
//#include <boost/progress.hpp>
#include "PluginManager.h"


namespace AccGrind{
namespace fs = boost::filesystem;

    PluginManager::PluginManager(): m_PluginsEnumerated( false),m_PluginsLoaded(false){
    }
    PluginManager::~PluginManager(){
        // unload all plugins
    }
    void PluginManager::IdentifyPlugins(){
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
    bool PluginManager::isFileNamePlugin ( std::string &fileName ){
        // potential improvement opportunity -- use regular expressions
        std::string::size_type pos = fileName.find(".so");
        if( std::string::npos != pos ){
            return true;
        }else{
            return false;
        }
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
        return false;
    }
    void PluginManager::getOptions ( std::vector<std::string> &optionCapture ) {
        // if plugins are not loaded
        if ( m_PluginsEnumerated != true ){
            // ** get names of all plugiuns
            IdentifyPlugins();
            // ** these are options to be selected
            int num = 0;
            for ( auto plugin : m_eligibleFiles ){
                std::string  option = "";
                option += num;
                option += plugin;
                std::cout << " --- identified file name :" << option.c_str() << std::endl;
                optionCapture.push_back ( option );
            }
            std::string optionAll = "";
            optionAll += ++num;
            optionAll += " All to be done ";
            optionCapture.push_back ( optionAll );
        }
        // else
        // ** get options from each of the plugins
        // ** offset with counter of the plugin position
    }
}
