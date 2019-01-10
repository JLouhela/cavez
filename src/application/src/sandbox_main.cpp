#include <iostream>
#include <SFML/Window.hpp>

int main()
{   
    sf::Window window(sf::VideoMode(800, 600), "Cavez sandbox app");
    do 
    {
        std::cout << '\n' << "Success! Press a key to continue...";
    } while (std::cin.get() != '\n');
    return 0;
}