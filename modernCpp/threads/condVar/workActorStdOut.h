#ifndef __WORKACTOR_STDOUT_H__
#define __WORKACTOR_STDOUT_H__ 
#include <iostream>

template <typename WorkItem>
class WorkActorStdOut {
public:
	WorkActorStdOut(){}
	~WorkActorStdOut(){}

	void performWork ( const WorkItem& workItem ){
		std::cout << "performing work on : "<< workItem << std::endl;
	}
};
#endif // __WORKACTOR_STDOUT_H__
