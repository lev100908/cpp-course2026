#pragma once
#include <string>

class Animal
{
    public:
    Animal();
    ~Animal();
    Animal(const Animal& other); 
    Animal(Animal&& other);
    Animal& operator=(const Animal& other); 
    Animal& operator=(Animal&& other);

    int pos;
    int hp;
    std::string name;

    virtual void sound();
    virtual void moving();
    virtual void eat();
};

class Bird : public Animal
{
    public:
    Bird();
    ~Bird();
    Bird(const Bird& other); 
    Bird(Bird&& other);
    Bird& operator=(const Bird& other); 
    Bird& operator=(Bird&& other);
    virtual void sound() override;
    virtual void moving() override;
    virtual void eat() override;
};

class Fox : public Animal
{
    public:
    Fox();
    ~Fox();
    Fox(const Fox& other); 
    Fox(Fox&& other);
    Fox& operator=(const Fox& other); 
    Fox& operator=(Fox&& other);
    virtual void sound() override;
    virtual void moving() override;
    virtual void eat() override;
};

class Bunny : public Animal
{
    public:
    Bunny();
    ~Bunny();
    Bunny(const Bunny& other); 
    Bunny(Bunny&& other);
    Bunny& operator=(const Bunny& other); 
    Bunny& operator=(Bunny&& other);
    virtual void sound() override;
    virtual void moving() override;
    virtual void eat() override;
};

class Cat : public Animal
{
    public:
    Cat();
    ~Cat();
    Cat(const Cat& other); 
    Cat(Cat&& other);
    Cat& operator=(const Cat& other); 
    Cat& operator=(Cat&& other);
    virtual void sound() override;
    virtual void moving() override;
    virtual void eat() override;
};

class Dog : public Animal
{
    public:
    Dog();
    ~Dog();
    Dog(const Dog& other); 
    Dog(Dog&& other);
    Dog& operator=(const Dog& other); 
    Dog& operator=(Dog&& other);
    virtual void sound() override;
    virtual void moving() override;
    virtual void eat() override;
};




