#ifndef __ICHILDCREATEPOLICY_B_H__
#define __ICHILDCREATEPOLICY_B_H__

#include "INode.h"

class childCreatePolicy_B : public IChildCreatePolicy {
public:
	IChildCreatePolicy(){}
	virtual ~IChildCreatePolicy();
	std::vector<INodePtr>	getChildren4Data ( IInputDataPtr ) const = 0;
};

#endif  //__ICHILDCREATEPOLICY_B_H__
