#include "Link.h"

Link::Link( std::string linkName ) : linkName_( std::move(linkName) )
{
}

std::string Link::name()
{
    return linkName_;
}
