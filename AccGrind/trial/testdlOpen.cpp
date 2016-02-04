#include "IInterpreter.h"
#include <dlfcn.h>
#include <iostream>
#include "libmain.h"

using namespace AccGrind;
using namespace std;

int main () {
    void* libHandle;
    IInterpreter<string>* interpretObj;
    libHandle = dlopen ( "./libtextEcho.so", RTLD_LAZY );
    if ( !libHandle ){
        cout << "Could not load library:" << dlerror() << endl;
        exit (1);
    }
    return 0;
}
