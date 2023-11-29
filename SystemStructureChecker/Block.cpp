#include <iostream>
#include "Block.h"
#include "Interface.h"

Block::Block( std::string name ) : blockName_( std::move(name) ), parent_( nullptr )
{
    std::cout << blockName_ << " was created." << std::endl;
}

Block::Block( std::string name, std::shared_ptr<Block> parent ) : blockName_( std::move(name) ), parent_( parent )
{
    std::cout << blockName_ << " was created with " << parent_->name() << std::endl;
}

void Block::createPort( std::string portname )
{
    ports_.insert( std::make_pair(portname, std::make_shared<Port>(portname, this)) );
}

void Block::allocateInterface( std::string targetPort, std::shared_ptr<Interface> interface )
{
    ports_.at(targetPort)->allocateInterface(interface);
}

void Block::addLink( std::string targetPort, std::string targetIinterface, std::shared_ptr<Link> link )
{
    ports_.at(targetPort)->addLink(targetIinterface, link);
}

void Block::addPart( std::shared_ptr<Block> part)
{
    parts_.insert( std::make_pair(part->name(), part) );
}

std::string Block::name()
{
    return blockName_;
}


Block::Port::Port( std::string portName, Block* parent ) : portName_( std::move(portName) ), parent_( parent )
{
    std::cout << portName_ << " of " << parent_->name()<< " was created" << std::endl;
}

void Block::Port::allocateInterface( std::shared_ptr<Interface> interface )
{
    interfaces_.insert( std::make_pair(interface->name(), interface) );
}

void Block::Port::addLink( std::string targetInterface, std::shared_ptr<Link> link )
{
    interfaces_.at(targetInterface)->addLink(link);
}
