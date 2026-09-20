#include <iostream>

#include "zoo.h"


int main()
{
    Bird bird_obj = Bird();
    Fox fox_obj = Fox();
    Bunny bunny_obj = Bunny();
    Cat cat_obj = Cat();
    Dog dog_obj = Dog();

    bird_obj.sound();
    bird_obj.moving();
    bird_obj.eat();
    bird_obj.sound();
    std::cout << "\n";

    fox_obj.sound();
    fox_obj.moving();
    fox_obj.eat();
    fox_obj.sound();
    std::cout << "\n";

    bunny_obj.sound();
    bunny_obj.moving();
    bunny_obj.eat();
    bunny_obj.sound();
    std::cout << "\n";

    cat_obj.sound();
    cat_obj.moving();
    cat_obj.eat();
    cat_obj.sound();
    std::cout << "\n";

    dog_obj.sound();
    dog_obj.moving();
    dog_obj.eat();
    dog_obj.sound();

    return 0;
}