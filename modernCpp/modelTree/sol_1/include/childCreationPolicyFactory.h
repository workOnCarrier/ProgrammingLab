#ifndef __ICHILDCREATEPOLICYFACTORY_H__
#define __ICHILDCREATEPOLICYFACTORY_H__

#include "INode.h"

class childCreatePolicyFactory {
public:
	childCreatePolicyFactory(){}
	virtual ~childCreatePolicyFactory();
	IChildCreatePolicyPtr getChildCreationPolicy ( IInputDataPtr ) const = 0;
};

#endif  //__ICHILDCREATEPOLICYFACTORY_H__
