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
    this->createLink();
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
    
    for(auto port = begin(ports); port != end(ports); ++port) {
        subsystems_.at(port->first)->createPort(port->second);
    }
}

void System::createInterface()
{
    std::array<std::string, 4> interface = {"Avionics,p1,DigitalData","Avionics,p1,TacticalData", "Avionics,p2,Status", "Engine,p1,Status"};
    for( auto interfaceName : interface ) {
        interfaces_.insert( std::make_pair(interfaceName, std::make_shared<Interface>(interfaceName)) );
    }
    this->allocateInterface();
}

void System::allocateInterface()
{
    std::array<std::tuple<std::string, std::string, std::string>, 4> targetPort = {std::make_tuple("Avionics","p1","Avionics,p1,DigitalData")
                                                                                    , std::make_tuple("Avionics","p1","Avionics,p1,TacticalData")
                                                                                    , std::make_tuple("Avionics","p2","Avionics,p2,Status")
                                                                                    , std::make_tuple("Engine","p1","Engine,p1,Status")};
    for( auto port : targetPort ) {
        subsystems_.at(std::get<0>(port))->allocateInterface( std::get<1>(port), interfaces_.at(std::get<2>(port)) );
    }

}

void System::createLink()
{
    std::array<std::string, 1> links = {"link1"};
    for( auto link : links ) {
        links_.insert( std::make_pair(link, std::make_shared<Link>(link)) );
    }
}
