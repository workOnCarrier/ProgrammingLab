
#include <memory>
#include "textInterpreter.h"
#include "specialTextTask.h"
#include "textTask.h"
#include <iostream>

namespace AccGrindPlugin {
    TextInterpreter::TextInterpreter ( ) {
    }

    TextInterpreter::~TextInterpreter ( ) {
        std::cout << "deleting the interpreter object " << std::endl;
    }

    Task TextInterpreter::interpret ( std::string const &textString ) {
        if (textString == "fun"){
            return std::make_shared<SpecialTextTask>(SpecialTextTask(textString));
        }else {
            return std::make_shared<TextTask>(TextTask(textString));
        }
    }
     void TextInterpreter::getOptions ( std::vector<std::string>& vectorObj) const {
         vectorObj.push_back("test");
     }
}
