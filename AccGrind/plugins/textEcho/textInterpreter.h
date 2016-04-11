#ifndef __TEXTINTERPRETER__
#define __TEXTINTERPRETER__

#include "IInterpreter.h"
#include "IOption.h"

using namespace AccGrind;

namespace AccGrindPlugin {

    class TextInterpreter : public IInterpreter < std::string >
    {
    public:
        TextInterpreter ( );
        virtual ~TextInterpreter ( );
        virtual Task interpret ( std::string const &textString );
        virtual void getOptions ( std::vector<std::string>& ) const ;
    private:
        std::vector<std::shared_ptr<IOption>>   m_options;
    };

}

#endif // __TEXTINTERPRETER__
