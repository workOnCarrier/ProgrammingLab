#include "EchoTextTask.h"


namespace AccGrind{
    EchoTextTask::EchoTextTask (std::string& taskArguments):m_argumentStr(taskArguments){
    }
    EchoTextTask::~EchoTextTask (){
    }
    void EchoTextTask::execute(){
        std::cout << m_argumentStr << std::endl;
    }
}
