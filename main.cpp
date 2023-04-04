#include <iostream>
#include "MSocket.hpp"
#include "message.hpp"
#include "client.hpp"


using namespace std ; 

int main()
{
    //declaring a socket 
  //   string  hostname = "127.0.0.1";
  //   string  port = "12000";
  //   MSocket m_socket(hostname,port);

  //   ; 

  //  if( !m_socket.init())
  //  {
  //   cout << "socket initialization failed \n aborting program ... " ; 
  //   return 0;
  //  }
  //  while (1)
  //  {
  //   /* code */
  //   string message = "";
  //  cout << "your message : ";
  //   std::getline(std::cin, message);
  //   string name = "client ";
  //  Message Lmsg ;
  //  Lmsg.setSender(name);
  //  Lmsg.setContent(message);
  //  m_socket.sendMSocket(Lmsg);
  //  m_socket.recvMSocket(Lmsg);
  //  cout << "sender : " << Lmsg.getSender()<<"\n";
  //  cout << "content : "<< Lmsg.getContent() << "\n" ;
  //  }
   
    

  // m_socket.recvMSocket();
Client client ; 
client.start();
}