#include <iostream>
#include "textTask.h"


namespace AccGrindPlugin{

    TextTask::TextTask( std::string const &string)
    :m_textValue(string)
    { }
    void TextTask::execute()
    {
        std::cout << " value of string in task is " << m_textValue << std::endl;
    }
}
