#pragma once

#include <map>
#include <memory>
#include <string>

class FlowObject;
class Interface;
class Link;

class Block
{
public:
    class Port
    {
    private:
        Port() = delete;
    public:
        Port( std::string portName, Block* parent );
        ~Port() = default;
        void allocateInterface( std::shared_ptr<Interface> interface );
        void addLink( std::string targetInterface, std::shared_ptr<Link> link );
        void sendData( std::string targetInterface, FlowObject& data ) const;
        void receiveData( FlowObject& data ) const;
        void replyData( FlowObject& data ) const;
    private:
        std::string portName_{};
        Block* parent_;
        std::map<std::string,std::shared_ptr<Interface>> interfaces_{};
    };
    
private:
    Block() = delete;
public:
    Block( std::string name );
    Block( std::string name, std::shared_ptr<Block> parent );
    virtual ~Block() = default;
    void createPort( std::string portname );
    void allocateInterface( std::string targetPort, std::shared_ptr<Interface> interface );
    void addLink( std::string targetPort, std::string targetInterface, std::shared_ptr<Link> link );
    void addPart( std::shared_ptr<Block> part);
    void sendData();
    void receiveData( FlowObject& data);
    std::string name();
private:
    std::string blockName_{};
    std::shared_ptr<Block> parent_{};
    std::map<std::string, std::shared_ptr<Port>> ports_{};
    std::map<std::string, std::shared_ptr<Block>> parts_{};
};
