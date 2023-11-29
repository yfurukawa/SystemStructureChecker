#pragma once

#include <map>
#include <memory>
#include <string>

class Block;
class Interface;

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
    std::map<std::string, std::shared_ptr<Block>> subsystems_{};
    std::map<std::string, std::shared_ptr<Interface>> interfaces_{};
    
    void createSubsystemBlocks();
    void createPort();
    void createInterface();
    void allocateInterface();
};

