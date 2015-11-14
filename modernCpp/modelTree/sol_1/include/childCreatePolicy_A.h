#ifndef __ICHILDCREATEPOLICY_A_H__
#define __ICHILDCREATEPOLICY_A_H__

#include "INode.h"

class childCreatePolicy_A : public IChildCreatePolicy {
public:
	IChildCreatePolicy(){}
	virtual ~IChildCreatePolicy();
	std::vector<INodePtr>	getChildren4Data ( IInputDataPtr ) const = 0;
};

#endif  //__ICHILDCREATEPOLICY_A_H__
