#ifndef __IINTERPRETER_H__
#define __IINTERPRETER_H__

#include "ITask.h"

namespace AccGrind{
    template <typename InputType>
    class IInterpreter {
    public:
        virtual ~IInterpreter () {}
        virtual Task interpret ( InputType textString ) = 0;
    };
}
#endif // __IINTERPRETER_H__
