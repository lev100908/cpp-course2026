#include "zoo.h"
#include <iostream>

Animal::Animal()
{
    pos = 0;
    hp = 100;
    name = "";
}

Animal::~Animal() = default;

Animal::Animal(const Animal &other)
{
    pos = other.pos;
    hp = other.hp;
    name = other.name;
}

Animal::Animal(Animal &&other)
{
    pos = other.pos;
    hp = other.hp;
    name = std::move(other.name);
}

Animal &Animal::operator=(const Animal &other)
{
    pos = other.pos;
    hp = other.hp;
    name = other.name;
    return *this;
}

Animal &Animal::operator=(Animal &&other)
{
    pos = other.pos;
    hp = other.hp;
    name = std::move(other.name);
    return *this;
}

void Animal::sound()
{
    std::cout << "Base sound" << std::endl;
}

void Animal::moving()
{
    pos += 1;
}

void Animal::eat()
{
    std::cout << "Base eat" << std::endl;
}

Bird::Bird()
{
    name = "CHICKCHIRIK";
}

Bird::~Bird() = default;

Bird::Bird(const Bird &other)
{
    pos = other.pos;
    hp = other.hp;
    name = other.name;
}

Bird::Bird(Bird &&other)
{
    pos = other.pos;
    hp = other.hp;
    name = std::move(other.name);
}

Bird &Bird::operator=(const Bird &other)
{
    pos = other.pos;
    hp = other.hp;
    name = other.name;
    return *this;
}

Bird &Bird::operator=(Bird &&other)
{
    pos = other.pos;
    hp = other.hp;
    name = std::move(other.name);
    return *this;
}

void Bird::sound()
{
    std::cout << "Chik Chirik. My name is " << name << " And i am in position " << pos << " My hp is "<< hp << std::endl;
}

void Bird::moving()
{
    std::cout << "I`m flying!!!" << std::endl;
    pos += 14;
}

void Bird::eat()
{
    std::cout << "I am eating. Chirik." << std::endl;
    hp += 5;
}

Fox::Fox()
{
    name = "Foxy";
}

Fox::~Fox() = default;

Fox::Fox(const Fox &other)
{
    pos = other.pos;
    hp = other.hp;
    name = other.name;
}

Fox::Fox(Fox &&other)
{
    pos = other.pos;
    hp = other.hp;
    name = std::move(other.name);
}

Fox &Fox::operator=(const Fox &other)
{
    pos = other.pos;
    hp = other.hp;
    name = other.name;
    return *this;
}

Fox &Fox::operator=(Fox &&other)
{
    pos = other.pos;
    hp = other.hp;
    name = std::move(other.name);
    return *this;
}

void Fox::sound()
{
    std::cout << "Ring-ding-ding! My name is " << name << " And i am in position " << pos << " My hp is "<< hp << std::endl;
}

void Fox::moving()
{
    std::cout << "Moving in silently. Nobody will even know I'm here." << std::endl;
    pos += 5;
}

void Fox::eat()
{
    std::cout << "Crunch crunch... mmm, just caught a juicy mouse. Tastes like chicken, but wilder. 🐭" << std::endl;
}

Bunny::Bunny()
{
    name = "Bunny";
}

Bunny::~Bunny() = default;

Bunny::Bunny(const Bunny &other)
{
    pos = other.pos;
    hp = other.hp;
    name = other.name;
}

Bunny::Bunny(Bunny &&other)
{
    pos = other.pos;
    hp = other.hp;
    name = std::move(other.name);
}

Bunny &Bunny::operator=(const Bunny &other)
{
    pos = other.pos;
    hp = other.hp;
    name = other.name;
    return *this;
}

Bunny &Bunny::operator=(Bunny &&other)
{
    pos = other.pos;
    hp = other.hp;
    name = std::move(other.name);
    return *this;
}

void Bunny::sound()
{
    std::cout << "... (silence) ... thump thump thump! My name is " << name << " And i am in position " << pos << " My hp is "<< hp << std::endl;
}

void Bunny::moving()
{
    std::cout << "Moving was scary but the new place has SO many hiding spots." << std::endl;
    pos+= 8;
}

void Bunny::eat()
{
    std::cout << "Nibble nibble nibble... carrots are life. 🥕 Also, I may or may not have eaten your garden. Sorry not sorry." << std::endl;
    hp += 3;
}

Cat::Cat()
{
    name = "KittyCat";
}

Cat::~Cat() = default;

Cat::Cat(const Cat &other)
{
    pos = other.pos;
    hp = other.hp;
    name = other.name;
}

Cat::Cat(Cat &&other)
{
    pos = other.pos;
    hp = other.hp;
    name = std::move(other.name);
}

Cat &Cat::operator=(const Cat &other)
{
    pos = other.pos;
    hp = other.hp;
    name = other.name;
    return *this;
}

Cat &Cat::operator=(Cat &&other)
{
    pos = other.pos;
    hp = other.hp;
    name = std::move(other.name);
    return *this;
}

void Cat::sound()
{
    std::cout << "Meow. Purrrrrr. MROW! My name is " << name << " And i am in position " << pos << " My hp is "<< hp << std::endl;
}

void Cat::moving()
{
    std::cout << "Explored the whole new place in 5 minutes. It's mine now." << std::endl;
    pos += 6;
}

void Cat::eat()
{
    std::cout << "Sniff sniff... I shall eat this gourmet salmon pâté. Or I shall knock it off the table. Depends on my mood." << std::endl;
    hp += 13;
}

Dog::Dog()
{
    name = "Doggy";
}

Dog::~Dog() = default;

Dog::Dog(const Dog &other)
{
    pos = other.pos;
    hp = other.hp;
    name = other.name;
}

Dog::Dog(Dog &&other)
{
    pos = other.pos;
    hp = other.hp;
    name = std::move(other.name);
}

Dog &Dog::operator=(const Dog &other)
{
    pos = other.pos;
    hp = other.hp;
    name = other.name;
    return *this;
}

Dog &Dog::operator=(Dog &&other)
{
    pos = other.pos;
    hp = other.hp;
    name = std::move(other.name);
    return *this;
}

void Dog::sound()
{
    std::cout << "Woof! WOOF! Bark bark bark! My name is " << name << " And i am in position " << pos << " My hp is "<< hp << std::endl;
}

void Dog::moving()
{
    std::cout << "NEW HOUSE?! NEW YARD?! NEW SMELLS?! BEST DAY EVER!!" << std::endl;
    pos += 10;
}

void Dog::eat()
{
    std::cout << "Wait... is that MY bowl? IS THAT MY BOWL?! CHOMP CHOMP CHOMP. Best day ever." << std::endl;
    hp += 12;
}