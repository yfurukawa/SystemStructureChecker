#pragma once

#include <memory>
#include <string>
#include <map>

class Link;

class Interface
{
private:
    Interface() = delete;
public:
    explicit Interface( std::string interfaceName );
    ~Interface() = default;
    void addLink( std::shared_ptr<Link> link );
    std::string name();
private:
    std::string interfaceName_{};
    std::map<std::string, std::shared_ptr<Link>> links_{};
};
