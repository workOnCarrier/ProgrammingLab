#ifndef __ICHILDCREATEPOLICY_H__
#define __ICHILDCREATEPOLICY_H__

#include "INode.h"

class IChildCreatePolicy {
public:
	IChildCreatePolicy(){}
	virtual ~IChildCreatePolicy();
	std::vector<INodePtr>	getChildren4Data ( IInputDataPtr ) const = 0;
};

#endif  //__ICHILDCREATEPOLICY_H__
