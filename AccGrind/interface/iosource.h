#ifndef __IOSOURCE_H__
#define __IOSOURCE_H__

#include <iostream>
namespace AccGrind{
    class IOHandler{
    public:
        IOHandler(){}
        virtual  ~IOHandler() {};

        virtual bool            hasMoreData () = 0 ;
        virtual std::string     getNextInput() = 0 ;
        virtual std::ostream&   getOutputStream() = 0 ;
    };
}

#endif //__IOSOURCE_H__
