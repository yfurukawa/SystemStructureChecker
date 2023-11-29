#pragma once

#include <string>

class System final
{
private:
    System() = delete;
public:
    System( std::string name );
    ~System() = default;
    void run();
private:
    std::string systemName_{};
};

