#ifndef __Node_1_H__
#define __Node_1_H__

#include "INode.h"
class Node_1 : public INode{
public:
	Node_1(){}
	virtual ~Node_1();
	void operate ( IOperationPtr );

private:
	std::vector<INodePtr>			m_children;
};

#endif  //__Node_1_H__
