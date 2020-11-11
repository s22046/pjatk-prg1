#include <iostream>
#include <string>

auto main() -> int
{

    std::cout << "countdown start from:";
    auto countdownstart = std::string{};

    for(i=countdownstart;i=0;i--)
    {    
    std::getline(std::cin, countdownstart);
    std::cout << i;
    }


    return 0;
