#ifndef __HOSTINTERPRET_H__
#define __HOSTINTERPRET_H__

#include "IInterpreter.h"
#include "ITask.h"

namespace AccGrind{
    class HostInterpret : public IInterpret<std::string>{
    public:
        HostInterpret ();
        ~HostInterpret ();
	virtual Task interpret ( std::string &) ;
    private:
        int getOptionFromUsrInput ( std::string& );
        std::vector<std::shared_ptr<IOption>>   m_options;
    };
}
#endif // __HOSTINTERPRET_H__
