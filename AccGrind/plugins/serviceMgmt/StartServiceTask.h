#ifndef __STARTSERVICETASK_H__
#define __STARTSERVICETASK_H__

#include "ITask.h"
namespace AccGrind{
    class StartServiceTask : public ITask {
    public:
        StartServiceTask (std::string& );
        ~StartServiceTask () ;

        virtual void execute();
    private:
        std::string     m_usrInput;
    };
}
#endif // __STARTSERVICETASK_H__
