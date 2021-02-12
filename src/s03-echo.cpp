#include <iostream>
#include <string>

//

auto main() -> int {
  std::cout << " Hello. \n What can I echo for you?"
            << "\n{Write exit to leave.)\n";
  auto input = std::string{};
  auto const exit = std::string{"exit"};
  do {
    std::getline(std::cin, input);
    std::cout << input << " \n";

  } while (input != exit);
}