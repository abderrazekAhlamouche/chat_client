#include "MSocket.hpp"

MSocket::MSocket(std::string host , std::string port  ):
hostname(host),port(port){}

void MSocket::init()
{
    
memset(&hints, 0, sizeof(struct addrinfo));		/* memset_s() */
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;

     if(getaddrinfo( hostname.c_str(), port.c_str(), &hints, &host) != 0)
     throw std::runtime_error("failed to get address info") ; 

     /*create a socket*/
     if((sockFd = socket(host->ai_family,host->ai_socktype,host->ai_protocol)) == -1)
     throw std::runtime_error("failed to create socket"); 
    std::cout << "Socket initialised successfully for address "+hostname+" Port "+ port+"\n";
    
}

void MSocket::connectTp()
{
    /*connect client */
    if(connect( sockFd, host->ai_addr, host->ai_addrlen)==-1)
    throw std::runtime_error("failed to connect"); 
}

bool MSocket::recvMSocket(IMessage& msg)
{
    int reception_size ; 
    reception_size = recv(sockFd,buffer,buffer_size,0);
    if(reception_size == 0)
    {
        std::cerr << " server disconnected "<<errno<< "\n" ; 
           return false ; 
    }else if(reception_size < 0 )
    {
         perror("Error receiving data from server");
         std::cerr << " network error :  "<<errno<< "\n";
         return false ;  
    }
 
    std::string serialized_object(buffer, reception_size);
    msg.ideSerialize(serialized_object);
    return true ; 
}

bool MSocket::sendMSocket(IMessage& msg)
{
 std::string serializedMsg = msg.iserialize();
 if(send(sockFd,serializedMsg.c_str(),serializedMsg.length(),0)==-1)
 {
    std::cout << "message could not be sent !\n" ;
    return false ; 
 }
 return true ; 
}

MSocket::~MSocket()
{
    /* close-up */
	freeaddrinfo(host);
	close(sockFd);
}

