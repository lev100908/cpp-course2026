#include <iostream>

#include "console_output.h"
#include "give_random_number.h"


void console_output(int output_data) 
{
    std::cout << output_data << std::endl;
}

void console_output(std::string output_data) 
{
    std::cout << output_data << std::endl;
}