#pragma once

#include <string>

class Link
{
private:
    Link() = delete;
public:
    explicit Link( std::string linkName );
    ~Link() = default;
    std::string name();
private:
    std::string linkName_{};
};
