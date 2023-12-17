#ifndef CXX17_V1_HELLO_WORLD_H
#define CXX17_V1_HELLO_WORLD_H

#include <iostream>

namespace cxx17
{
    class HelloWorld
    {
    private:
        std::string caption_;

    public:
        explicit HelloWorld(const std::string &caption);
        ~HelloWorld();

        const std::string &caption() const;
    };

}
#endif