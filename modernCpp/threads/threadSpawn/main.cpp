#include <iostream>
#include <thread>
//#include "scopedthread.h"


using namespace std;
void doSomethingUseful ( void ){
    cout << __FUNCTION__ << "Thead id:::" << this_thread::get_id() << ":::" << endl;
}

void run_thread1();
void run_thread2();

int main ( int argc, char** argv ) {
    thread   newThread ( doSomethingUseful );
	cout << "after delegating work" << endl;

    thread   thread_1 ( run_thread1 );
    thread   thread_2 ( run_thread2 );

	thread_1.join();
	thread_2.join();
	newThread.join();
	return 0;
}

void run_thread1()
 {
   std::cout << "message " << "from thread " << 1 << std::endl;
 }

 // thread2
 void run_thread2()
 {
   std::cout << "message " << "from thread " << 2 << std::endl;
 }
