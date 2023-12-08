#pragma once

#include <memory>
#include <string>

class FlowObject;
class Interface;

class Link
{
private:
    Link() = delete;
public:
    explicit Link( std::string linkName );
    ~Link() = default;
    std::string name();
    void bindInterface( std::shared_ptr<Interface> input, std::shared_ptr<Interface> output );
    void sendData( FlowObject& data ) const;
    void replyData( FlowObject& data ) const;
private:
    std::string linkName_{};
    std::shared_ptr<Interface> inputSide_{};
    std::shared_ptr<Interface> outputSide_{};
};
