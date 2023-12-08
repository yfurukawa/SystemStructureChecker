#include <iostream>
#include "Block.h"
#include "Interface.h"
#include "Link.h"
#include "System.h"
#include "FlowObject.h"

System::System( std::string name ) : systemName_( std::move(name) )
{
}

void System::run()
{
    this->createSubsystemBlocks();
    this->createPort();
    this->createInterface();
    this->createLink();
    
    struct FlowObject data("test");
    subsystems_.at("Avionics")->sendData();
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
    std::array<std::string, 4> interfaces = {"Avionics,p1,DigitalData","Avionics,p1,TacticalData", "Avionics,p2,Status", "Engine,p1,Status"};
    std::string name{};
    for( auto id : interfaces ) {
        name =  id.substr( id.rfind(',')+1 );
        interfaces_.insert( std::make_pair(id, std::make_shared<Interface>(id, name)) );
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
    this->bindInterfaceAndLink();
}

void System::bindInterfaceAndLink()
{
    links_.at("link1")->bindInterface(interfaces_.at("Avionics,p2,Status"), interfaces_.at("Engine,p1,Status"));
    interfaces_.at("Avionics,p2,Status")->addLink(links_.at("link1"));
    interfaces_.at("Engine,p1,Status")->addLink(links_.at("link1"));
}
