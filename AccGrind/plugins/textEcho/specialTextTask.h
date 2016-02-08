#ifndef __SPECIALTEXTTASK_H__
#define __SPECIALTEXTTASK_H__

#include "ITask.h"
using namespace AccGrind;

namespace AccGrindPlugin{
    class SpecialTextTask : public ITask {
    public:
        SpecialTextTask( std::string const &textVal);
        virtual void execute() ;
    private:
        std::string		m_textValue;
    };
}
#endif // __SPECIALTEXTTASK_H__
