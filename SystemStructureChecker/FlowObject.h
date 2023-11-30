#pragma once

#include <memory>
#include <string>

class FlowObject
{
private:
    FlowObject() = delete;
public:
    explicit FlowObject( std::string name ) : objectName_( std::make_unique<std::string>( std::move(name)) ){};
    virtual FlowObject() = default;
protected:
    std::unique_ptr<std::string> objectName_{};
};
