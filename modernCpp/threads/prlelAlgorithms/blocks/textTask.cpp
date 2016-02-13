#include <iostream>
#include "textTask.h"


TextTask::TextTask( std::string &string)
:m_textValue(string)
{ }
void TextTask::execute()
{
	std::cout << " value of string in task is " << m_textValue << std::endl;
}
