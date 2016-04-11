#ifndef __TEXTTASK_H__
#define __TEXTTASK_H__

#include "ITask.h"
#include "IOption.h"
using namespace AccGrind;

namespace AccGrindPlugin{
    class TextTask : public ITask {
    public:
        TextTask( std::string const &string);
        virtual void execute() ;
    private:
        std::string		m_textValue;
    };
    class TextOption : public IOption {
        virtual std::string getOptionString ( )const ;
        virtual Task        getTask ( std::string const& ) const ;
    };
}
#endif // __TEXTTASK_H__
