#ifndef __PLUGINMANAGER_H__
#define __PLUGINMANAGER_H__
#include <vector>
#include <string>
#include "IInputHandler.h"
#include "PluginLoader.h"
#include "ITask.h"
#include <functional>

#include <iostream>


namespace AccGrind{
    class PluginManager: public IInterpreter<std::string>{
    public:
        typedef IInterpreter<std::string>::InputType    InputType;
        PluginManager();
        ~PluginManager();
        virtual Task interpret ( InputType const &) ;
        virtual void getOptions ( std::vector<std::string> & ) const;
    private:
        void IdentifyPlugins() const;
        void LoadPlugins();
        bool isFileNamePlugin ( std::string & ) const;

        mutable bool    m_PluginsEnumerated = false;
        mutable bool    m_PluginsLoaded = false;

        mutable std::vector<std::string>    m_eligibleFiles;
        std::vector<PluginLoader::Ptr>   m_plugins;
        std::map<int,StringInterpreter*>    m_Interpreters;
        // nested class of type ITask
        class LoadPluginTask : public  ITask{
        public:
            LoadPluginTask ( std::function<void(void)>& function):m_executer(function){
            }
            virtual void execute() {
                std::cout << "LoadPluginTask :: about to execute" << std::endl;
                m_executer();
            }
        private:
            std::function<void(void)>   m_executer;
        };
    };
}
#endif // __PLUGINMANAGER_H__
