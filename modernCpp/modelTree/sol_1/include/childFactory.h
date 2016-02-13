#ifndef __CHILDFACTORY_H__
#define __CHILDFACTORY_H__

class ChildFactory {
public:
	ChildFactory(){}
	~ChildFactory(){}
	INodePtr	getChild ( IInputDataPtr );
};
#endif  //__CHILDFACTORY_H__
