
#include <memory>
#include "textInterpreter.h"
#include "specialTextTask.h"
#include "textTask.h"

TextInterpreter::TextInterpreter ( ) {
}

TextInterpreter::~TextInterpreter ( ) {
}

Task TextInterpreter::interpret ( std::string textString ) {
	if (textString == "fun"){
		return std::make_shared<SpecialTextTask>(SpecialTextTask(textString));
	}else {
		return std::make_shared<TextTask>(TextTask(textString));
	}
}
