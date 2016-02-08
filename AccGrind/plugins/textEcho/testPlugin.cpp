#include "ITask.h"
#include "libmain.h"
#include "textInterpreter.h"


using namespace AccGrindPlugin ;
    int main(){
        AccGrind::IInterpreter<std::string>* interpreterOjb = new TextInterpreter ();
        auto task = interpreterOjb->interpret("fun");
        task->execute();
        return 0;
    }

