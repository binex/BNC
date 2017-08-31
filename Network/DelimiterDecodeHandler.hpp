#ifndef DELIMITER_DECODER_HANDLER_HPP
#define DELIMITER_DECODER_HANDLER_HPP
#include <iostream>
#include <string>
#include "IOHandler.hpp"
#include "SocketBase.hpp"

class DelimiterDecodeHandler : public IOHandler
{
    public:
        
        DelimiterDecodeHandler()
            :_delimiter('\n')
        { }
        
        DelimiterDecodeHandler(char delimiter)
            :_delimiter(delimiter)
        { }
        
        virtual bool channelRead(SocketBase *pSock, void *data, int size);

    private:
      char _delimiter;
      std::string _line;
};

#endif
