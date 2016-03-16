#ifndef __HOSTINTERPRET_H__
#define __HOSTINTERPRET_H__

#include "IInterpreter.h"
#include "IOption.h"
#include "ITask.h"
#include <vector>
#include "PluginManager.h"

namespace AccGrind{
    class HostInterpret : public IInterpreter<std::string>{
    public:
        HostInterpret ();
        virtual ~HostInterpret ();
	    virtual Task interpret ( IInterpreter::InputType const &) ;
        virtual void getOptions ( std::vector<std::string>& ) const ;
    private:
        std::vector<std::shared_ptr<IOption>>   m_options;
        PluginManager                           m_pluginManager;
    };
}
#endif // __HOSTINTERPRET_H__
