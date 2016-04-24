
#include <iostream>
#include "InputRouter.h"
#include "keyInputSource.h"
#include "HostInputHandler.h"


void startProcessing();
int main (int argc, char* argv[]){
    std::cout << "Starting main" << std::endl;

    std::cout << "Starting input processing" << std::endl;

    startProcessing();
    return 0;
}
void startProcessing(){
    AccGrind::KeyInputSource keyInputSrc;
    AccGrind::HostInputHandler hostInputHandler;

    AccGrind::InputRouter inputRouter( keyInputSrc, hostInputHandler );
    inputRouter.process();

}
