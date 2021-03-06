#ifndef __SPECIALTEXTTASK_H__
#define __SPECIALTEXTTASK_H__

#include "ITask.h"

class SpecialTextTask : public ITask {
public:
	SpecialTextTask( std::string &textVal);
	virtual void execute() ;
private:
	std::string		m_textValue;
};
#endif // __SPECIALTEXTTASK_H__
