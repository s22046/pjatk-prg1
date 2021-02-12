#include <iostream> // for std::cout, std::cerr, and std::cin
#include <stdlib.h>
#include <string>
#include <time.h>

auto main() -> int {
  std::cout << " Lets play a game. Give me a number(1-100): "
            << " \n";
  srand(time(NULL));
  auto secretnumber = rand() % 99 + 1;
  auto guess = std::string{};

  do {
    std::getline(std::cin, guess);
    auto intguess = std::stoi(guess);
    if (intguess > secretnumber) {

      std::cout << "Za duzo!"
                << "\n";
    }

    if (intguess < secretnumber) {

      std::cout << "Za malo!"
                << "\n";
    }
    if (intguess == secretnumber) {
      break;
    }

  } while (true);

  std::cout << "Gratuluje, zgadles!";

  return 0;
}
