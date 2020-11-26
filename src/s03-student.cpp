#include "s03-student.h"
#include <iostream>

auto main() -> int
{
    auto student = Student{std::string{"michau"}, std::string{"J"}, std::string{"22046"}, std::string{"1"}, std::string{"5"}};


    student.to_string();
    
    std::cout << student.to_string();
}

auto Student::to_string() const -> std::string
{
    auto returnvalue = std::string{"Student details: \n"};
    returnvalue += "Name: " + sname + "\n"
                + "Surname: " + ssurname + "\n"
                + "Index nr: " + sindex + "\n"
                + "Semester: " + ssmr + "\n"
                + "Grades average: " + savggrades + "\n";

    return returnvalue;
}

Student::Student(std::string name, std::string surname, std::string index, std::string smr, std::string avggrades)
{
    sname = name;
    ssurname = surname;
    sindex = index;
    ssmr = smr;
    savggrades = avggrades;


}