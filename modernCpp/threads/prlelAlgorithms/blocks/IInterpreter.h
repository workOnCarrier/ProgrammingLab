#ifndef __IINTERPRETER_H__
#define __IINTERPRETER_H__

#include "ITask.h"

template <typename InputType>
class IInterpreter {
public:
	virtual ~IInterpreter () = 0;
	virtual Task interpret ( InputType textString ) = 0;
};
#endif // __IINTERPRETER_H__
