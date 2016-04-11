#include "IInterpreter.h"
#include "ITask.h"
#include <dlfcn.h>
#include <iostream>
#include "libmain.h"
#include <sstream>
#include "genUtils.h"

using namespace AccGrind;
using namespace std;

int main () {
    void* libHandle;
    AccGrind::IInterpreter<std::string>* interpretObj;
//    string libname = "./libGenUtils.so";
//    libHandle = dlopen ( libname.c_str() , RTLD_NOW );
//    if ( !libHandle ){
//        cout << "Could not load library:" << libname<< " due to:" << dlerror() << endl;
//        exit (1);
//    } else {
//        cout << "Successfully  loaded the library:" << libname  << endl;
//    }

    std::string     testStr = "1:: this is fun";
    auto output = getOptionFromUsrInput  ( testStr );
    std::cout << output << endl;

    string libname = "./libtextEcho.so";
    libHandle = dlopen ( libname.c_str() , RTLD_NOW );
    if ( !libHandle ){
        cout << "Could not load library " << libname <<  ":" << dlerror() << endl;
        exit (1);
    } else {
        cout << "Successfully  loaded the library:" << libname << endl;
    }
    typedef void* (*getHandlers)();

    dlerror();
    getHandlers handler =  (getHandlers) dlsym(libHandle, PLUGINHANDLER);
    const char* findFunctionError = dlerror();
    if ( findFunctionError ){
        cout << "Cannot load the symbol 'getPluginInputHandler' due to :"<< findFunctionError << endl;
    }else{
        cout << "Successfully loaded the symbol 'getPluginInputHandler'"<< endl;
    }
    interpretObj = (AccGrind::IInterpreter<std::string>*)  handler( );
    if ( NULL == interpretObj ){
        cout << "Null pointer obtained from the symbol 'getPluginInputHandler'"<< endl;
    } else{
        interpretObj ->interpret ( "1:fun" )->execute();
        interpretObj ->interpret ( "1:some text" )->execute();
        std::vector<std::string>    pluginOptions;
        interpretObj ->getOptions ( pluginOptions );
        int num = 1;
        for ( auto optionStr : pluginOptions ){
            std::stringstream option  ;
            option << num++ << "." << optionStr;
            cout << " option string :" << option.str() << endl;
        }
    }

    typedef void (*deleteHandlers)(void*);
    deleteHandlers delhandler =  (deleteHandlers ) dlsym(libHandle, "deletePluginInputHandler");
    findFunctionError = dlerror();
    if ( findFunctionError ){
        cout << "Cannot load the symbol 'deletePluginInputHandler' due to :"<< findFunctionError << endl;
    }else{
        cout << "Successfully loaded the symbol 'detelePluginInputHandler'"<< endl;
    }
    delhandler(interpretObj);
    return 0;
}
