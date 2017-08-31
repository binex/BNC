#ifndef IO_HANDLER_HPP
#define IO_HANDLER_HPP
#include "SocketBase.hpp"
#include "IOHandler.hpp"

class IOHandler {
    
    public:

        IOHandler()
        { }
    
        virtual bool channelRead(SocketBase* pSock, void* data, int size)=0;

};

#endif
