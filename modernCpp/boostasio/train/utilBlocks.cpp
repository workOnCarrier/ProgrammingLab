// This files is not planned for stand alone 
// please include in other files -- #include utilBlocks.cpp
// rationale -- this has utility functions and 
// need a project to be used in
// ---- yes, this is an experiment - to understand the working
// ---- of the compiler




void WorkerThread(std::shared_ptr<boost::asio::io_service> iosvc, int counter) {
    global_stream_lock.lock();
    std::cout << "Thread " << counter << " Start.\n";
    global_stream_lock.unlock();

    iosvc->run();

    global_stream_lock.lock();
    std::cout << "Thread " << counter << " End.\n";
    global_stream_lock.unlock();
}
