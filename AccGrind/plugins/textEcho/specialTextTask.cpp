#include <iostream>
#include "specialTextTask.h"

namespace AccGrindPlugin{

    SpecialTextTask::SpecialTextTask( std::string &textVal)
    :m_textValue(textVal) { }
    void SpecialTextTask::execute()
    {
        std::cout << " value of string in SPECIAL task is " << m_textValue << std::endl;
    }
}
