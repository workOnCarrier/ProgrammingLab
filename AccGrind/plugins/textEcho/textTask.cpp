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
    std::string TextOption::getOptionString ( )const {
        return " Echo Text ";
    }
    Task        TextOption::getTask ( std::string const& textString) const {
       return std::make_shared<TextTask>(TextTask(textString));
    }
}
