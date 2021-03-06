#ifndef __TASKCREATER_H__
#define __TASKCREATER_H__

#include <iostream>
#include <memory>
//#include "IInterpreter.h"

template < typename Source,typename TaskQueue, typename IInterpreter >
class TaskCreater {
public:
	TaskCreater( TaskQueue &taskQueue , std::shared_ptr<IInterpreter> interpreter)
		:m_taskQueue(taskQueue), m_isSupplyActive(true), m_taskInterpreter(interpreter) {}

	void process (void ){
		while ( m_sourceObject.hasMoreData() ){
			auto	task = m_taskInterpreter->interpret ( m_sourceObject.getNextInput() );
			m_taskQueue.push ( task );
		}
		m_isSupplyActive = false;
	}
	bool	isSupplyActive () { return m_isSupplyActive; }

//	TaskCreater(TaskCreater&& src) {
//		m_sourceObject ( std::move(src.m_sourceObject) );
//		m_taskQueue = src.m_taskQueue;
//		m_taskInterpreter ( src.m_taskInterpreter );
//		m_isSupplyActive = src.m_isSupplyActive;
//	}
private:
	TaskCreater() = delete;
	TaskCreater(const TaskCreater&) = delete;

	Source								m_sourceObject;
	TaskQueue							&m_taskQueue;
	bool								m_isSupplyActive;
	std::shared_ptr<IInterpreter>	m_taskInterpreter;
};
#endif // __TASKCREATER_H__
