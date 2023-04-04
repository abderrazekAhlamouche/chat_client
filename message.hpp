#pragma once
#include <string>

class IMessage{
public:
virtual std::string iserialize()= 0 ;
virtual void ideSerialize(std::string& sMsg)= 0 ;

virtual ~IMessage() {} ; 

};

class Message : public IMessage{
std::string sender;
std::string content ; 

public:
Message()=default;
 ~Message()=default;

virtual  void setSender(std::string& sender)
{
    this->sender = sender ; 
}

 virtual void setContent(std::string& content)
{
    this->content = content ; 
}

 virtual std::string getSender()const
{
    return sender;
}

 virtual std::string getContent() const
{
    return content;
}
template <class Archive>
void serialize(Archive &ar, const unsigned int version)
{
    // serialize member variables
    ar &this->sender;
    ar &this->content;
    // ...
}

std::string iserialize() override ;
void ideSerialize(std::string& sMsg) override ; 

};