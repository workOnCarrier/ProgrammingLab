#ifndef __INODE_H__
#define __INODE_H__

#include <memory>
#include <vector>

#include "IOperation.h"

class INode{
public:
	INode(){}
	virtual ~INode();
	void operate ( IOperationPtr );

	typdef std::shared_ptr<INode>	INodePtr;
private:
	std::vector<INodePtr>			m_children;
};

#endif  //__INODE_H__
