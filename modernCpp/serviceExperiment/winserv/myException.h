#pragma once
#include <exception>
#include <string>


class myException : public std::exception {

public:
	myException (std::string);
	myException (std::string, long);
};
