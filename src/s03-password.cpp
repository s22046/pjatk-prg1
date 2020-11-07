#include <iostream> // for std::cout, std::cerr, and std::cin
#include <string>

auto main() -> int
{
    auto entered_password = std::string{};
    std::string password = "H";

    do
    {    
    std::cout << " Password:";

    std::getline(std::cin, entered_password);
    
    } while (entered_password != password);

    return 0;
}
