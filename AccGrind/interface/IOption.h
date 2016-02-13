#ifndef __IOPTION_H__
#define __IOPTION_H__

#include "ITask.h"

namespace AccGrind {
    class IOption{
    public:
        IOption( ) {}
        virtual ~IOption () {}

        virtual std::string getOptionString ( )const = 0;
        virtual Task        getTask ( std::string& ) const = 0;
    private:
    };
}
#endif // __IOPTION_H__
