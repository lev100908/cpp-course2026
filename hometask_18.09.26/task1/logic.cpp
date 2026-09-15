#include "console_input.h"
#include "console_output.h"
#include "give_the_month.h"

void logic()
{
    int user_number;

    console_output("Input number of the month");

    console_input(user_number);

    console_output(give_the_month(user_number));
}