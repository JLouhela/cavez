#include <iostream>
#include "rendering/rendering_interface.hpp"

int main()
{
    auto renderer = make_rendering();
    do
    {
    } while (std::cin.get() != '\n');
    return 0;
}
