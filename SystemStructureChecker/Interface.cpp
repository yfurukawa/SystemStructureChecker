#include "FlowObject.h"
#include "Interface.h"
#include "Link.h"

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

void Interface::bindLink( std::shared_ptr<Link> link )
{
    link_ = link;
}

void Interface::sendData(FlowObject& data)
{
    
}
