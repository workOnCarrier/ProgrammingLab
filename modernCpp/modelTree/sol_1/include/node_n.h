#ifndef __Node_n_H__
#define __Node_n_H__

#include "INode.h"
class Node_n : public INode{
public:
	Node_n(){}
	virtual ~Node_n();
	void operate ( IOperationPtr );

private:
	std::vector<INodePtr>			m_children;
};

#endif  //__Node_n_H__
