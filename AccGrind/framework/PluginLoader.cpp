#ifndef WIN32
#include <dlfcn.h>
#else
#endif
#include "PluginLoader.h"
#include <iostream>
#include <stdexcept>

namespace AccGrind{
#ifndef WIN32
    PluginLoader::PluginLoader(std::string& pluginName):m_pluginName(pluginName),m_pluginHandle(NULL),m_interpretObj(NULL) {
        m_pluginHandle = dlopen ( pluginName.c_str(), RTLD_NOW );
        if ( ! m_pluginHandle ){
            // log -- successfully not loaded library
#pragma message (" potentially throw exception here " )
            std::string errorStr = "Library";
            errorStr += pluginName;
            errorStr += " could not be loaded, due to :";
            errorStr += dlerror();
            throw std::runtime_error ( errorStr );
        }else{
            // log -- load library successful
        }
    }
    PluginLoader::~PluginLoader() {}

    StringInterpreter*   PluginLoader::load() {
        if ( m_pluginHandle ){
            Handler handler = (Handler) dlsym ( m_pluginHandle, PLUGINHANDLER );
            const char* findFunctionError = dlerror();
            if ( findFunctionError ){
                std::cout << "dlsym is returning error:"<< findFunctionError << std::endl;
                // log error findFunctionError 
            }else{ }
            //AccGrind::IInterpreter<std::string>* m_interpretObj = reinterpret_cast<AccGrind::IInterpreter<std::string>*>(  handler( ) );
            m_interpretObj = (AccGrind::IInterpreter<std::string>*)  handler( ) ;
            if  ( NULL == m_interpretObj ){
                std::cout << "reinterpret cast is failing" << std::endl;
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
#else
        PluginLoader::PluginLoader(std::string& pluginName){
			m_pluginHandle =  ::LoadLibrary ( pluginName.c_str() );
			if (!m_pluginHandle) {
				const DWORD dw = ::GetLastError();
				LPVOID lpMsgBuf(0);
				::FormatMessage( FORMAT_MESSAGE_ALLOCATE_BUFFER |
									FORMAT_MESSAGE_FROM_SYSTEM |
									FORMAT_MESSAGE_IGNORE_INSERTS,
									NULL, dw, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
									(LPTSTR)& lpMsgBuf,
									0, NULL );
#pragma message ("Report error in log")
				std::cout << __FUNCTION__ << " Can't load the pluggin because:" << (LPTSTR)lpMsgBuf << std::endl;
			}
		}
        PluginLoader::~PluginLoader(){
		}

        StringInterpreter*       PluginLoader::load(){
			if ( m_pluginHandle ){
				FARPROC function = NULL;
				try{
					function = ::GetProcAddress( m_pluginHandle, PLUGINHANDLER );
				}catch(...){}
				if (!function){
					const DWORD dw = ::GetLastError();
					LPVOID lpMsgBuf(0);
					::FormatMessage( FORMAT_MESSAGE_ALLOCATE_BUFFER |
						FORMAT_MESSAGE_FROM_SYSTEM |
						FORMAT_MESSAGE_IGNORE_INSERTS,
						NULL, dw, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
						(LPTSTR)& lpMsgBuf,
						0, NULL );
#pragma message ("Report error in log")
					std::cout << __FUNCTION__ << " Can't find the function pointer:" 
								<< (LPTSTR)lpMsgBuf << std::endl;
					::FreeLibrary(m_pluginHandle);
				}else{ 
					m_interpretObj   = (StringInterpreter*)function();
				}
			}else{
#pragma message ("TBD :: PluginLoader::load -- throw an exception")

			}
			return  m_interpretObj ;
		}
        void           PluginLoader::unload(){

		}
    
#endif //WIN32
}
