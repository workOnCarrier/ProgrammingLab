#ifndef __WORKSCHEDULER__
#define __WORKSCHEDULER__

#include <iostream>
#include <thread>
#include <unistd.h>
#include "inputSupplier.h"
#include "keyInputSource.h"
#include "workDirector.h"
#include "workActorStdOut.h"

template <typename WorkLineup, typename WorkItemType>
class WorkScheduler{
public:
	WorkScheduler ( WorkLineup& workLine ):m_workLineup(workLine),m_inputSupplyFromKey(workLine),m_outputDirectToStdOut(workLine){
	}
	void startScheduleing (){
		std::thread		outputThread(m_outputDirectToStdOut);
		outputThread.detach();
		std::thread		inputThread(std::ref(m_inputSupplyFromKey));
		while ( m_inputSupplyFromKey.isSupplyActive() ){
			//std::this_thread::sleep_for(1000);
			sleep(1);
		}
		if ( inputThread.joinable() ){
			std::cout << "Joining the input thread" << inputThread.get_id() << std::endl;
			inputThread.join();
		}else{
			std::cout << "Input thread not Joinable" << std::endl;
		}
	}
private:
	WorkScheduler () = delete;
	WorkLineup&			m_workLineup;
	InputSupplier<keyInputSource,WorkLineup > m_inputSupplyFromKey;
	WorkDirector<WorkActorStdOut<WorkItemType>,WorkLineup > m_outputDirectToStdOut;
};
#endif // __WORKSCHEDULER__
