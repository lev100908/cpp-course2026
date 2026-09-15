#include <random>

#include "console_output.h"
#include "give_random_number.h"

int give_random_number()
{
    std::random_device rd;
    std::uniform_int_distribution<int> dist(1, 100);

    unsigned int random_number = dist(rd);

    return random_number;
}