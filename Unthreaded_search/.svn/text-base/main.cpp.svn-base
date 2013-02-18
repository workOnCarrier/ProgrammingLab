#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>
#include "error.h"
#include <boost/ref.hpp>
#include "workItem.h"
#include "workQueue.h"
#include "workRoutine.h"
#include "trace.h"

using namespace std;

int main ( int argc, char** argv )
{
	int		thread_count;

	if ( argc < 3 )
	{
	    fprintf ( stderr, "Usage : %s string path [thread_count]\n", argv[0] );
		return -1;
	}

	if ( argc > 3 )
	{
	    thread_count = atoi ( argv[3] );
	}
	else
	{
		thread_count = 3;
	}
    
	string   filepath = argv[2];
	trace::getTrace()->Info() << filepath.c_str();
	fileWorkQueue		workqueue ( filepath );
	fileWorkItem  		filework( workqueue, filepath, argv[1] );
	workqueue.addWork (  filework ); 

    worker_routine_unthreaded ( workqueue );
    return 0;
}
