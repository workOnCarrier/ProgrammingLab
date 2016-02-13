#ifndef __WORKDIRECTOR_H__
#define __WORKDIRECTOR_H__

#include <iostream>
template <typename Destination, typename SupplyLine>
class WorkDirector{
public:
	WorkDirector(SupplyLine& supplyLine):m_supplyLine(supplyLine){
	}
	void operator () (void){
		while ( true ){
			m_workActor.performWork ( *m_supplyLine.pop() );
		}
	}
private:
	SupplyLine&			m_supplyLine;
	Destination			m_workActor;
};

#endif // __WORKDIRECTOR_H__
