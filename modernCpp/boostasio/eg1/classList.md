boost::system::erro_code            -> error state container

asio::ip::address           -> abstraction for "ip address" (v6/v4)
asio::ip::tcp::endpoint     -> abstraction for a combination of "IP-Port"
asio::io_service            -> abstraction for "service" -- responsible for all OS interaction
asio::ip::tcp::protocol     -> abstraction for "protocol" -- obtainable from endpoint
asio::ip::tcp::socket       -> abstraction for network connection -- uses service object and endpoint protocol
asio::ip::tcp::resolver::query  -> abstraction for the DNS query -- used to check for "domain, Port -- numeric / service(http/ftp/...)"
asio::ip::tcp::resolver::query::numeric_service -> enum indicating the port represented in DNS query is expressed as numeric
asio::ip::tcp::resolver         -> abstraction for DNS object resolution logic that returns the iterator for resolved address-port combo
asio::ip::tcp::resolver::iterator   -> abstraction for one of the instances of the resolved IP-Port combo
asio::connect                       -> utility function that links "Socket" object to IP-port combo
asio::ip::tcp::acceptor             -> class object on server side to allow for receiving TCP connections
asio::ip::address_v6::any           -> abstraction indicating receiving connection request from all IP addresses on the server

asio::mutable_buffer            -> represents modifiable buffer class - gives starting address and size of buffer
asio::const_buffer              -> represents readonly buffer class - gives starting address and size of buffer
asio::mutable_buffers_1         -> adapter for adapting asio::mutable_buffer to satisfy interface MutableBufferSequence
asio::const_buffers_1           -> adapter for adapting asio::const_buffer to satisfy interface ConstBufferSequence
asio::buffer()                  -> utility function - returns objects of type asio::mutable_buffers_1 or asio::const_buffers_1

asio::streambuf                 -> class to represent stream oriented buffers - typedef basic_streambuf<>   streambuf derived from iostream

