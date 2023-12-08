#include "Link.h"
#include "Interface.h"

Link::Link( std::string linkName ) : linkName_( std::move(linkName) )
{
}

std::string Link::name()
{
    return linkName_;
}

void Link::bindInterface(std::shared_ptr<Interface> input, std::shared_ptr<Interface> output)
{
    inputSide_ = input;
    outputSide_ = output;
}

void Link::sendData(FlowObject &data) const
{
    outputSide_->receiveData(data);
}

void Link::replyData(FlowObject &data) const
{
    inputSide_->replyData(data);
}
