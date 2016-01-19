#ifndef __IINTERPRETER_H__
#define __IINTERPRETER_H__

#include "ITask.h"

namespace AccGrind{
    template <typename T>
    class IInterpreter {
    public:
        typedef T InputType ;
        virtual ~IInterpreter () {}
        virtual Task interpret ( InputType &textString ) = 0;
        virtual void getOptions ( std::vector<std::string>& ) const =0;
    };
}
#endif // __IINTERPRETER_H__
