#include <iostream>

#include "console_input.h"

void console_input(int &user_number)
{
    while (!(std::cin >> user_number)) 
    {
        std::cout << "Error: wrong type. Input integer number." << std::endl;
        std::cin.clear();
        std::cin.sync();
    }
}