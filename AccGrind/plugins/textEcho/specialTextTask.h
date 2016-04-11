#ifndef __SPECIALTEXTTASK_H__
#define __SPECIALTEXTTASK_H__

#include "ITask.h"
#include "IOption.h"
using namespace AccGrind;

namespace AccGrindPlugin{
   class SpecialTextTask : public ITask {
    public:
        SpecialTextTask( std::string const &textVal);
        virtual void execute() ;
    private:
        std::string		m_textValue;
    };
    class SpecialTextOption : public IOption {
        virtual std::string getOptionString ( )const ;
        virtual Task        getTask ( std::string const& ) const ;
    };
 }
#endif // __SPECIALTEXTTASK_H__
