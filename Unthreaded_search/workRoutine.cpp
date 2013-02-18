#include <sys/types.h>
#include <sys/stat.h>
#ifdef __UNIX__
#include <dirent.h>
#endif //__UNIX__
#include <stdio.h>
#include <pthread.h>
#include "error.h"
#include "workRoutine.h"

void* worker_routine_unthreaded ( fileWorkQueue &fwQ )
{
    fileWorkQueue 		&workQue	=  fwQ;
	fileWorkItem		work(workQue) ; 
	while ( workQue.isWorkInQueue() )
	{
	    work = workQue.getWork();
		work.InitWork();
		work.doWork();
		work.cleanupWork();
	}
	return NULL;
}
