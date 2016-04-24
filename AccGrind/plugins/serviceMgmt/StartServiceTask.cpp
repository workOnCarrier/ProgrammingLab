#include "StartServiceTask.h"

namespace AccGrind{
    StartServiceTask::StartServiceTask (std::string& usrInput) : m_usrInput(usrInput){
    }
    StartServiceTask::~StartServiceTask (){}

    void StartServiceTask::execute(){
        system("./startService.sh");
    }
}
/*
 * 
 * http://www.gidforums.com/t-3369.html
 * https://msdn.microsoft.com/en-us/library/windows/desktop/ms682499%28v=vs.85%29.aspx
 *
 */
