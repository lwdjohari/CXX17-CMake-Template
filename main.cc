#include <cxx17/HelloWorld.h>
#include <iostream>
#include <string>

int main()
{
    // application main
    std::string caption = "Hello World from C++17";
    cxx17::HelloWorld h(caption);

    std::cout << h.caption() << std::endl;    
    return 0;
}