#ifndef __Node_2_H__
#define __Node_2_H__

#include "INode.h"
class Node_2 : public INode{
public:
	Node_2(){}
	virtual ~Node_2();
	void operate ( IOperationPtr );

private:
	std::vector<INodePtr>			m_children;
};

#endif  //__Node_2_H__
