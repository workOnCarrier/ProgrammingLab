#include "EchoTextTask.h"
#include <iostream>


namespace AccGrind{
    EchoTextTask::EchoTextTask (std::string& taskArguments):m_argumentStr(taskArguments){
    }
    EchoTextTask::~EchoTextTask (){
    }
    void EchoTextTask::execute(){
        std::cout << "Echo Task ::" <<  m_argumentStr << std::endl;
    }
}
