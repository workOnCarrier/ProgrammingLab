#ifndef __STARTMYSERVOPTION_H__
#define __STARTMYSERVOPTION_H__
#include "IOption.h"


namespace AccGrind {
    class StartMyServOption : public IOption{
    public:
        StartMyServOption();
        ~StartMyServOption();
        virtual std::string getOptionString ( )const ;
        virtual Task        getTask ( std::string& ) const ; 
    private:
        std::string     m_optionString;
    };
}
#endif // __STARTMYSERVOPTION_H__
