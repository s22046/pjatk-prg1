#include <iostream>
#include <string>

struct Time  
{
    int second = 0;
    int minute = 0;
    int hour = 0;

    Time(int, int, int);

    auto to_string() const -> std::string;
    auto next_second() -> void;
    auto next_minute() -> void;
    auto next_hour() -> void;
    
};
