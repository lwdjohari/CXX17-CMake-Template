#include <cxx17/HelloWorld.h>

namespace cxx17
{
    HelloWorld::HelloWorld(const std::string &caption) : caption_(std::string(caption))
    {
    }

    HelloWorld::~HelloWorld()
    {
    }

    const std::string &HelloWorld::caption() const
    {
        return caption_;
    }

}
