#include "Block.h"
#include "System.h"

System::System( std::string name ) : systemName_( std::move(name) )
{
}

void System::run()
{
    this->createSubsystemBlocks();
}

void System::createSubsystemBlocks()
{
    std::array<std::string, 2> subsystems = {"Avionics", "Engine"};
    for( auto s : subsystems) {
        subsystems_.insert( std::make_pair(s, std::make_shared<Block>(s)) );
    }
}
