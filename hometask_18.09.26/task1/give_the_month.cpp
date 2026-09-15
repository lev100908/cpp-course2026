#include <string>
#include <array>


std::string give_the_month(int number_of_month)
{
    
    std::array<std::string, 12> months {
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "November",
        "December"
    };

    return months[(number_of_month % 12) - 1];
}