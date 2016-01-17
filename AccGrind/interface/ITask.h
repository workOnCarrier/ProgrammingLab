#ifndef __ITASK_H__
#define __ITASK_H__

#include <memory>

namespace AccGrind{
    class ITask{
    public:
        virtual ~ITask() {};
        virtual void execute() = 0;
    };

    typedef std::shared_ptr<ITask>	Task;
}

#endif // __ITASK_H__
