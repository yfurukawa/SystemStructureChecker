
#include "FlowObject.h"
#include "Interface.h"
#include "Link.h"
#include "Block.h"

Interface::Interface( std::string interfaceId, std::string interfaceName )
    : interfaceId_( std::move( interfaceId ) )
    , interfaceName_( std::move(interfaceName) )
{
}

void Interface::addLink(std::shared_ptr<Link> link)
{
    links_.insert( std::make_pair(link->name(), link) );
}

std::string Interface::name()
{
    return interfaceName_;
}

void Interface::sendData(FlowObject& data) const
{
    for( auto link = begin(links_); link != end(links_); ++link ) {
        link->second->sendData(data);
    }
}

void Interface::receiveData(FlowObject& data) const
{
    ownerPort_->receiveData(data);
}

void Interface::bindPort(Block::Port *ownerPort)
{
    ownerPort_ = ownerPort;
}

void Interface::replyData(FlowObject &data) const
{
    ownerPort_->replyData(data);
}
