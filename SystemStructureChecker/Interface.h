#pragma once

#include <memory>
#include <string>
#include <map>
#include "Block.h"

class FlowObject;
class Link;

class Interface
{
private:
    Interface() = delete;
public:
    Interface( std::string interfaceId, std::string interfaceName );
    ~Interface() = default;
    void addLink( std::shared_ptr<Link> link );
    std::string name();
    void sendData( FlowObject& data ) const;
    void receiveData( FlowObject& data ) const;
    void bindPort( Block::Port* ownerPort );
    void replyData( FlowObject& data ) const;
private:
    std::string interfaceId_{};
    std::string interfaceName_{};
    std::map<std::string, std::shared_ptr<Link>> links_{};
    Block::Port* ownerPort_{};
};
