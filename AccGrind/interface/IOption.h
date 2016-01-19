#ifndef __IOPTION_H__
#define __IOPTION_H__

#include "ITask.h"

namespace AccGrind {
    class IOption{
    public:
        IOption( std::string &optionString );
        ~IOption ();

        virtual std::string getOptionString ( )const;
        virtual Task        getTask ( std::string& ) const = 0;
    private:
        std::string     m_optionString;
    };
}
#endif // __IOPTION_H__
