#ifndef __ECHOTEXTOPTION_H__
#define __ECHOTEXTOPTION_H__

#include "IOption.h"
#include "ITask.h"

namespace AccGrind{
    class EchoTextOption : public IOption {
    public:
        EchoTextOption ();
        virtual ~EchoTextOption ();
        virtual std::string getOptionString ( )const;
        virtual Task        getTask ( std::string& ) const ;
    private:
        std::string     m_optionString;
    };
}
#endif // __ECHOTEXTOPTION_H__
