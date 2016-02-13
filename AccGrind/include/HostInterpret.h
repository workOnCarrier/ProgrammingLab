#ifndef __HOSTINTERPRET_H__
#define __HOSTINTERPRET_H__

#include "IInterpreter.h"
#include "IOption.h"
#include "ITask.h"
#include <vector>

namespace AccGrind{
    class HostInterpret : public IInterpreter<std::string>{
    public:
        HostInterpret ();
        virtual ~HostInterpret ();
	    virtual Task interpret ( IInterpreter::InputType &) ;
        virtual void getOptions ( std::vector<std::string>& ) const ;
    private:
        int getOptionFromUsrInput ( std::string& );
        std::vector<std::shared_ptr<IOption>>   m_options;
    };
}
#endif // __HOSTINTERPRET_H__
