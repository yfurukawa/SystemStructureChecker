#pragma once

#include <memory>
#include <string>
#include <map>

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
    void bindLink( std::shared_ptr<Link> link );
    void sendData( FlowObject& data );
private:
    std::string interfaceId_{};
    std::string interfaceName_{};
    std::map<std::string, std::shared_ptr<Link>> links_{};
    std::shared_ptr<Link> link_{};
};
