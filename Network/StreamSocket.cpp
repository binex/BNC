#include "StreamSocket.hpp"

bool StreamSocket::initialize(){

    if( SocketBase::initialize() )
    {
        std::cout<<"error2"<<std::endl;
        memset(&_servaddr, 0, sizeof(_servaddr));
        _servaddr.sin_family = AF_INET;
        _servaddr.sin_port = htons( getPort() );
        _servaddr.sin_addr.s_addr = inet_addr( getAddr().c_str() );
        return true; 
    } 
    else 
    {
        return false;
    }
}


bool StreamSocket::start(){
    if( SocketBase::start() ) 
    {
        std::cout<<"error1"<<std::endl;
        return -1 != connect(
                sock(), 
                (struct sockaddr*)&_servaddr, 
                sizeof(_servaddr)
                );
    }
    else
    {
        return false;
    }
}
