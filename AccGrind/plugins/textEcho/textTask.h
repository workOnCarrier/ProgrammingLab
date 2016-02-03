#ifndef __TEXTTASK_H__
#define __TEXTTASK_H__

#include "ITask.h"
using namespace AccGrind;

namespace AccGrindPlugin{
    class TextTask : public ITask {
    public:
        TextTask( std::string &string);
        virtual void execute() ;
    private:
        std::string		m_textValue;
    };
}
#endif // __TEXTTASK_H__
