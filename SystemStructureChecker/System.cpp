#include <iostream>
#include "Block.h"
#include "Interface.h"
#include "Link.h"
#include "System.h"

System::System( std::string name ) : systemName_( std::move(name) )
{
}

void System::run()
{
    this->createSubsystemBlocks();
    this->createPort();
    this->createInterface();
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

void System::createInterface()
{
    std::array<std::string, 2> interface = {"Digital Data", "Status"};
    for(auto i : interface ) {
        interfaces_.insert( std::make_pair(i, std::make_shared<Interface>(i)) );
    }
    this->allocateInterface();
}

void System::allocateInterface()
{
    std::multimap<std::string, std::pair<std::string, std::string>> interface;
    interface.insert( std::make_pair("Avionics", std::make_pair("p1", "Digital Data")) );
    interface.insert( std::make_pair("Avionics", std::make_pair("p2", "Status")) );
    interface.insert( std::make_pair("Engine", std::make_pair("p1", "Status")) );
    
    for( auto p = begin(interface); p != end(interface); ++p ) {
        subsystems_.at(p->first)->allocateInterface( (p->second).first, interfaces_.at((p->second).second) );
    }
}
