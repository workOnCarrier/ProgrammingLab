#include "IInterpreter.h"
#include "ITask.h"
#include <dlfcn.h>
#include <iostream>
#include "libmain.h"

using namespace AccGrind;
using namespace std;

int main () {
    void* libHandle;
    IInterpreter<string>* interpretObj;
    libHandle = dlopen ( "./libtextEcho.so", RTLD_NOW );
    if ( !libHandle ){
        cout << "Could not load library:" << dlerror() << endl;
        exit (1);
    } else {
        cout << "Successfully  loaded the library:" << endl;
    }
    typedef void* (*getHandlers)();

    dlerror();
    getHandlers handler =  (getHandlers) dlsym(libHandle, "getPluginInputHandler");
    const char* findFunctionError = dlerror();
    if ( findFunctionError ){
        cout << "Cannot load the symbol 'getPluginInputHandler' due to :"<< findFunctionError << endl;
    }else{
        cout << "Successfully loaded the symbol 'getPluginInputHandler'"<< endl;
    }
    AccGrind::IInterpreter<std::string>* interruptObj = (AccGrind::IInterpreter<std::string>*)  handler( );
    if ( NULL == interruptObj ){
        cout << "Null pointer obtained from the symbol 'getPluginInputHandler'"<< endl;
    } else{
        interruptObj ->interpret ( "fun" )->execute();
        interruptObj ->interpret ( "some text" )->execute();
    }

    return 0;
}
