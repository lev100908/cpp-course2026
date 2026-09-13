#include "give_random_number.h"
#include "console_output.h"
#include "console_input.h"


void logic()
{
    console_output("Try to guess the number.");

    unsigned int user_number = 0;
    unsigned int random_number = give_random_number();

    console_input(user_number);
    
    while (random_number != user_number)
    {
        if (random_number < user_number)
        {
            console_output("Lower");
        }

        else 
        {
            console_output("Greater");
        }

        console_input(user_number);
    }

    console_output("You find it!");
}