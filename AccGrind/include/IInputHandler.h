#ifndef __IINPUTHANDLER_H__
#define __IINPUTHANDLER_H__

#include <vector>
#include <string>

namespace AccGrind {
    class IInputHandler {
    public:
        IInputHandler (){}
        virtual ~IInputHandler () {}
        virtual bool handleInput ( std::string& )= 0;
        virtual void getOptions ( std::vector<std::string> & ) = 0;
    private:
    };
}
#endif // __IINPUTHANDLER_H__
