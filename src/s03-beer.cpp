#include <iostream>
#include <string>

// 

auto main() -> int
{
    std::cout << "How many bottles of beer?\n";
    auto input = std::string{};
    std::getline(std::cin, input);
    auto startingbottles = std::stoi(input);

    for (int i = startingbottles;i > 0 ;i--)
    {
        std::cout << "\n" << i << " bottles of beer on the wall " << i << " bottles of beer.\n" << " Take one down, pass it around " << i-1 << " bottles of beer on the wall...";
    }
    
    std::cout << "No more bottles of beer on the wall, no more bottles of beer.\nGo to the store and buy some more, 99 bootles of beer on the wall.";
}