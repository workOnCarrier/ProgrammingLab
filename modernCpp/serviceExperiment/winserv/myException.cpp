#include "myException.h"


myException::myException (std::string msg)
	: exception(msg.c_str()){ }
myException::myException(std::string msg, long errNo)
	: exception(msg.c_str(), errNo){ }
