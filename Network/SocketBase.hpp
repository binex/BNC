#ifndef SOCKET_BASE_HPP
#define SOCKET_BASE_HPP

#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>


#ifndef INVALID_SOCKET
#define INVALID_SOCKET -1
#endif


class SocketBase {

    public:


        SocketBase(int port)
            :_addr("127.0.0.1"), _port(port), _sock(INVALID_SOCKET)
        { }


        SocketBase(std::string addr, int port)
            :_addr(addr), _port(port), _sock(INVALID_SOCKET)
        { }
    
        
        virtual bool initialize(){
            _sock = socket(AF_INET, SOCK_STREAM, 0);
            return INVALID_SOCKET != _sock;
        }

        virtual bool start(){
            return initialize();
        }

        int getPort()
        { return _port; }
        
        std::string getAddr()
        { return _addr; }
        
        SocketBase& setPort(int port)
        { _port = port; return (*this); }

        SocketBase& setAddr(std::string addr)
        { _addr = addr; return (*this); }

        int sock()
        { return _sock; }
        
    protected:
        int _sock;
        int _port;
        std::string _addr;
};

#endif
