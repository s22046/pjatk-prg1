#include "s03-time.h"

auto main() -> int {
  auto time = Time(59, 59, 23);

  time.to_string();
  std::cout << time.to_string();
}

auto Time::to_string() const -> std::string {

  std::to_string(second);
  std::to_string(minute);
  std::to_string(hour);

  auto timeformat = std::string{"Time is(HH:MM:SS): \n"};
  timeformat += std::to_string(hour) + std::to_string(minute) +
                std::to_string(second) + "\n";

  return timeformat;
}

Time::Time(int thissecond, int thisminute, int thishour) {
  second = thissecond;
  minute = thisminute;
  hour = thishour;
}
