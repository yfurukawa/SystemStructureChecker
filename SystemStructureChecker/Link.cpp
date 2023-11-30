#include "Link.h"

Link::Link( std::string linkName ) : linkName_( std::move(linkName) )
{
}

std::string Link::name()
{
    return linkName_;
}

void Link::bindInterface(std::shared_ptr<Interface> lhs, std::shared_ptr<Interface> rhs)
{
    lhs_ = lhs;
    rhs_ = rhs;
}
