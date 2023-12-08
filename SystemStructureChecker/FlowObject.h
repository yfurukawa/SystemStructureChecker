#pragma once

#include <memory>
#include <string>

class FlowObject
{
private:

public:
    FlowObject(){};
    explicit FlowObject( std::string name ) : objectName_( std::make_unique<std::string>( std::move(name)) ){};
    virtual ~FlowObject() {};
    std::string name() const
    {
        return objectName_->c_str();
    }
protected:
    std::unique_ptr<std::string> objectName_{};
};
