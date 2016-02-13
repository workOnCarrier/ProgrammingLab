create a future -- std::async ( parameters )
	parameters
		a list of function to be called and the arguments
		member function to be called - second -- object,  followed by other parameters
	support move symantics

invokation plan parameters -- std::launch enum
	std::launch::defered -- defer the call untill wait() / get() is invoked on the future
	std::launch::async -- launch the future in a separate thread
	std::launch::defered | std::launch::async -- let the system decide

task can also be wrapped into
* std::packaged_task<>


packaged_task<> is higher level abstraction than promise<>
	works in a pair with future<>
	invoke the operator() on the task object -- invokes the object stored with parameters passed at time of task creation.
	if the operator() throws and exception, the exception is passed to the stack of future<> object -- get/wait() call
	if the task object is destroyed without call to operator(), exception is passed to future<> object -- get/wait() call
	
Functional communication can happen using 
* std::promise<>

promise<>
	works in a pair with future<>
	provides a means for setting a value - to be read with associated future<> obtained from get_future() member of promise
	when the value of promise is set -- the return of the future becomes available
	when the promise object is destroyed - without the value being set -- registers an exception in the future call.
	if the code setting promise value -- needs to report error instead of actual value, it can set_exception() with value
		This exception value will be thrown in the call to get()/wait().
	
Multiple threads need to wait / want the value of the future
* std::shared_future() is used

shared_future()
	is obtained from future object obtained from promise or package_task -- take ownership of the underlying object/data


to learn --
	usage of package_task and future -- how they are implemented


