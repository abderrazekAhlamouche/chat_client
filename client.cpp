#include "client.hpp"

void Client::setupClient()
{
    std::cout << "setting up server \n";
    std::cout << "port : ";
    getline(std::cin, m_port);
}

void Client::initialiseSocket()
{
    setupClient();
    mSocket = std::make_unique<MSocket>(m_hostname, m_port);
        mSocket->init();
        mSocket->connectTp();
  
}

void Client::start()
{
    start:
    try{
    initialiseSocket();
    }catch(const std::exception &e)
    {
        std::cerr << e.what() << '\n';
         char input = 'N' ; 
            std::cout << "retry ? ";
            std::cin >> input ; 
            if (input=='Y')
            goto start;
            return ; 
    }
    stopFlag = false;
    std::thread sendingThread([this]() { sending();});
    // std::thread receivingThread([this]() { receiving();});
    while (true)
    {
    //   if(receivingThread.joinable())
    //     {
    //         std::cout <<"\n"<<"server is disconected."<<"\n"<<"aborting"<<"\n";
    //         receivingThread.join();
    //         break;
    //     }

        Message msg;
        if (!mSocket->recvMSocket(msg))
            break; 
        std::cout<< "\n"<<"Message received:"<<"\n";
        std::cout<<msg.getSender()<<": "<<msg.getContent()<<"\n";
    }
    stopFlag = true;

    // join all threads before exiting
     sendingThread.join(); 
    

}

/* void Client::receiving()
{
    while (!stopFlag)
    {
        Message msg;
        if (!mSocket->recvMSocket(msg))
            break; 
        std::cout<< "\n"<<"Message received:"<<"\n";
        std::cout<<"Sender: "<<msg.getSender()<<"\n";
        std::cout<<"content:"<<msg.getContent()<<"\n";
    }
}
 */
void Client::sending()
{
    std::string clientName = "";
    std::cout << "pseudo/name : ";
    std::getline(std::cin, clientName);
    std::cout << "writing messages is now available for "+clientName << "\n";
    while(!stopFlag)
    {
    std::string message = "";
    std::getline(std::cin, message);
    
   Message Lmsg ;
   Lmsg.setSender(clientName);
   Lmsg.setContent(message);
   mSocket->sendMSocket(Lmsg);
    }
}