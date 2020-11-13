#include <iostream>
#include <string>

auto main() -> int
{
    std::cout << " Countdown start from:";
    auto countdownstart = std::string{};
    std::getline(std::cin, countdownstart);
    auto countstart = std::stoi(countdownstart);
    

    for(int i = countstart;i>=0;i--)
    {    
       std::cout << i << "\n";
       
    }

    return 0;

}
