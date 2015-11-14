#ifndef __Node_3_H__
#define __Node_3_H__

#include "INode.h"
class Node_3 : public INode{
public:
	Node_3(){}
	virtual ~Node_3();
	void operate ( IOperationPtr );

private:
	std::vector<INodePtr>			m_children;
};

#endif  //__Node_3_H__
