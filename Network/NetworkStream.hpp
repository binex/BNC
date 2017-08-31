#ifndef NETWORK_STREAM_H_H
#define NETWORK_STREAM_H_H

#include <iostream>
#include <list>
#include <algorithm>
#include "IOHandler.hpp"
#include "SocketBase.hpp"

#define MAX_BUFFER_SIZE  1024

class NetworkStream
{
    public:

        NetworkStream()
            :_pSock(NULL)
        { }
        
        NetworkStream(SocketBase& sock)
            :_pSock(&sock)
        { }

        virtual NetworkStream& addHandler(IOHandler& handler)
        { _pHandlerList.push_back(&handler); return (*this); }
    
        virtual NetworkStream& setSocketBase(SocketBase& sock)
        { _pSock=&sock; return (*this); }

        virtual SocketBase& getSocketBase()
        { return (*_pSock); }

        ~NetworkStream(){
            _pHandlerList.clear();
        }

        virtual bool fireRead();

        virtual bool fireWrite();

    protected:
        char _buffer[MAX_BUFFER_SIZE];
        SocketBase* _pSock;
        std::list<IOHandler*> _pHandlerList;
};

#endif
