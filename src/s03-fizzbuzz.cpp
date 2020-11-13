#include <iostream>
#include <string>

auto main() -> int
{

    auto input = std::string{};
    std::getline(std::cin, input);
    auto n = std::stoi(input);

    for (auto i = 1; i <= n; i++)
    {
        std::cout << i << " ";

        if (i%3 == 0)
        {
            std::cout << "Fizz";
        } 
        if (i%5 == 0)
        {
            std::cout << "Buzz";
        }
        std::cout << " \n";
        
    }

}