#pragma once

#include <memory>
#include <string>

class Interface;

class Link
{
private:
    Link() = delete;
public:
    explicit Link( std::string linkName );
    ~Link() = default;
    std::string name();
    void bindInterface( std::shared_ptr<Interface> lhs, std::shared_ptr<Interface> rhs );
private:
    std::string linkName_{};
    std::shared_ptr<Interface> lhs_{};
    std::shared_ptr<Interface> rhs_{};
};
