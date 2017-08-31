#ifndef STREAM_SOCKET_H_H
#define STREAM_SOCKET_H_H

#include "SocketBase.hpp"


class StreamSocket : public SocketBase
{
    public:

        StreamSocket(int port)
            :SocketBase(port)
        { }
    
        StreamSocket(std::string addr, int port)
            :SocketBase(addr, port)

        { }

        virtual bool initialize();

        virtual bool start();
    
    private:
        struct sockaddr_in _servaddr;

};

#endif
