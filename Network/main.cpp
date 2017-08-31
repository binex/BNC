#include "StreamSocket.hpp"
#include "NetworkStream.hpp"
#include "DelimiterDecodeHandler.hpp"

using namespace std;

int main(){

   /* StreamSocket sock(7777);

    if( !sock.start() )
    {
        printf("error!");
    }

    char buffer[1024];

    int len = 0;

    while( (len=recv(sock.sock(), buffer, sizeof(buffer)-1,0)) > 0 )
    {
        buffer[len]='\0';

        printf("len=%d-->%s\n", len, buffer);

        memset(buffer, '\0', 1024);
    }*/

    StreamSocket sock(7777);
    
    DelimiterDecodeHandler handler;

    NetworkStream stream(sock);
        
    stream.addHandler(handler);

    while(true){
        
        if( !stream.fireRead() )
        {
            break;
        }

    }

    return 0;
}
