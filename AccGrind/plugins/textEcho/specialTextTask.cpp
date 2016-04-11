#include <iostream>
#include "specialTextTask.h"

namespace AccGrindPlugin{

    SpecialTextTask::SpecialTextTask( std::string const &textVal)
    :m_textValue(textVal) { }
    void SpecialTextTask::execute()
    {
        std::cout << " value of string in SPECIAL task is ::" << m_textValue << std::endl;
    }

    std::string SpecialTextOption:: getOptionString ( )const {
        return "echo fun string";
    }
    Task        SpecialTextOption:: getTask ( std::string const& textString) const {
        return std::make_shared<SpecialTextTask>(SpecialTextTask(textString));
    }
}
