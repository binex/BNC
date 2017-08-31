#include "NetworkStream.hpp"

bool NetworkStream::fireRead()
{
    if( NULL == _pSock ) return false;
    
    if( INVALID_SOCKET == (*_pSock).sock() )
    {
        if( !(*_pSock).start() ) return false;
    }

    memset(_buffer, '\0', sizeof(_buffer));

    int len = recv( (*_pSock).sock(), _buffer, sizeof(_buffer)-1, 0 );
    if( len <= 0 )
    {   
        return false;
    }
    else
    {
        _buffer[len] = '\0';
        
        void *data = _buffer;
        
        for( std::list<IOHandler*>::iterator iter = _pHandlerList.begin();
                iter != _pHandlerList.end(); iter++ )
        {
            (*iter)->channelRead(_pSock, data, sizeof(data));
        }

        return true;
    }
}

bool NetworkStream::fireWrite()
{
    return true;    
}
