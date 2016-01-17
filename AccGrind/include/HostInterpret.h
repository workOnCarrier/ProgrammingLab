#ifndef __HOSTINTERPRET_H__
#define __HOSTINTERPRET_H__

#include "IInterpreter.h"
#include "ITask.h"

namespace AccGrind{
    class HostInterpret : public IInterpret<std::string>{
    public:
        HostInterpret ();
        ~HostInterpret ();
	virtual Task interpret ( InputType textString ) ;
    private:
    };
}
#endif // __HOSTINTERPRET_H__
