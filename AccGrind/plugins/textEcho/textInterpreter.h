#ifndef __TEXTINTERPRETER__
#define __TEXTINTERPRETER__

#include "IInterpreter.h"

using namespace AccGrind;

namespace AccGrindPlugin {

    class TextInterpreter : public IInterpreter < std::string >
    {
    public:
        TextInterpreter ( );
        virtual ~TextInterpreter ( );
        virtual Task interpret ( std::string textString );
    private:
    };

}

#endif // __TEXTINTERPRETER__
