#include <iostream>
#include <string>

struct Student
{
    std::string sname = std::string{};
    std::string ssurname = std::string{};
    std::string sindex = std::string{};
    std::string ssmr = std::string{};
    std::string savggrades = std::string{};

    auto to_string() const -> std::string;

    Student(std::string, std::string, std::string, std::string, std::string);
};