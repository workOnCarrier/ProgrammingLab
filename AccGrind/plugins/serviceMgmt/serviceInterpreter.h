#ifndef __SERVICEINTERPRETER__
#define __SERVICEINTERPRETER__

#include "IInterpreter.h"
#include "IOption.h"

using namespace AccGrind;

namespace AccGrindPlugin {

    class ServiceInterPreter : public IInterpreter <std::string>
    {
    public:
        ServiceInterPreter ();
        virtual ~ServiceInterPreter ();
        virtual Task interpret ( std::string const &textString );
        virtual void getOptions ( std::vector<std::string>& ) const ;
    private:
        std::vector<std::shared_ptr<IOption>>   m_options;
    };
}
#endif // __SERVICEINTERPRETER__
