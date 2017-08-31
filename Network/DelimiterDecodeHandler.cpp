#include "DelimiterDecodeHandler.hpp"

bool DelimiterDecodeHandler::channelRead(
        SocketBase *pSock, void *data, int size)
{
    char *buffer = (char*)data;
    std::string bufferLine = buffer;
    _line = _line + bufferLine;
    int pos = -1;
    //std::cout<<buffer<<"&&"<<std::endl;
    while( (pos = _line.find(_delimiter)) != std::string::npos )
    {
        //std::cout<<"pos="<<pos<<",len="<<_line.length()<<std::endl;
        std::cout<<_line.substr(0,pos)<<std::endl;
        if( pos + sizeof(_delimiter) < _line.length() ) {
            _line = _line.substr(pos+sizeof(_delimiter));
        }else{
            _line = "";
        }
    }

    return true;
}
