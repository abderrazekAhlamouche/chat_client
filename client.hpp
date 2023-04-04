#pragma once
#include "MSocket.hpp"
#include "message.hpp"
#include "string"
#include <memory>
#include <vector>
#include <thread>
#include <algorithm>
#include <atomic>
#include <mutex>

#define MAX_CLIENTS 10 

class Client{
   const std::string m_hostname = "127.0.0.1" ; 
    std::string m_port ;
    std::atomic<bool> stopFlag ;
    std::unique_ptr<MSocket> mSocket ;   
    std::vector<std::thread> threads ;  
    std::mutex m_mutex;
    public:
    Client() = default ; 
    virtual ~Client() = default ; 
    void setupClient();
    void initialiseSocket();
    void start();
    void sending();
    void receiving();
};