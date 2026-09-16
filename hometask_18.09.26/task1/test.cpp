#include <iostream>
#include <map>
#include <string>
#include "give_the_month.h"

int main()
{

    std::map<int, std::string> map_of_tests {
        {1, "January"},
        {2, "February"},
        {3, "March"},
        {4, "April"},
        {5, "May"},
        {6, "June"},
        {7, "July"},
        {8, "August"},
        {9, "September"},
        {10, "November"},
        {11, "October"},
        {12, "December"},
        {13, "January"}
    };

    for (int i = 1; i <= map_of_tests.size(); i++)
    {
        std::cout << "Test" << i << " " << (give_the_month(i) == map_of_tests[i]) << std::endl;
    }

    std::cout << "Test" << map_of_tests.size()+1 << " " << (give_the_month(-25) == "Error") << std::endl;

}