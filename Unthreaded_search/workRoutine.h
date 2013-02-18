
#include "workQueue.h"
#include "fileWorkItem.h"

typedef workQueue<fileWorkItem> fileWorkQueue; 
void* worker_routine_unthreaded ( fileWorkQueue & );
