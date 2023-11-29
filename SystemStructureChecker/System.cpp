#include <iostream>
#include "Block.h"
#include "System.h"

System::System( std::string name ) : systemName_( std::move(name) )
{
}

void System::run()
{
    this->createSubsystemBlocks();
    this->createPort();
}

void System::createSubsystemBlocks()
{
    std::array<std::string, 2> subsystems = {"Avionics", "Engine"};
    for( auto s : subsystems) {
        subsystems_.insert( std::make_pair(s, std::make_shared<Block>(s)) );
    }
}

void System::createPort()
{
    std::multimap<std::string, std::string> ports;
    ports.insert(std::make_pair("Avionics", "p1"));
    ports.insert(std::make_pair("Avionics", "p2"));
    ports.insert(std::make_pair("Engine", "p1"));
    ports.insert(std::make_pair("Engine", "p2"));
    std::cout << ports.size() << std::endl;
    
    for(auto port = begin(ports); port != end(ports); ++port) {
        subsystems_.at(port->first)->createPort(port->second);
    }
}
