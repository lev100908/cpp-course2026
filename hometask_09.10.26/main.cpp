#include <iostream>

#include "triangle.h"
#include "rectangle.h"
#include "circle.h"
#include "square.h"
#include "shape_operators.h"
#include "exceptions.h"

int main()
{
    Triangle tr1(2.0, 3.0, 4.0);
    Rectangle rec1(4.0, 5.0);
    Circle cir1(3.0);
    Square sq1(4.0);

    std::cout << tr1;
    std::cout << "-------------------" << std::endl;
    std::cout << rec1;
    std::cout << "-------------------" << std::endl;
    std::cout << cir1;
    std::cout << "-------------------" << std::endl;
    std::cout << sq1;

    std::cout << "-------------------" << std::endl;

    Triangle tr2(3.0, 3.0, 3.0);
    Rectangle rec2(8.0, 2.0);
    Circle cir2(3.0 + 1e-8);

    std::cout << "Perimeter tr1 = Perimeter tr2: " << (tr1 ^ tr2) << std::endl;
    std::cout << "Square sq1 = Square rec2: " << (sq1 == rec2) << std::endl;

    std::cout << "Perimeter cir1 = Perimeter cir2: " << (cir1 ^ cir2) << std::endl;
    std::cout << "Square cir1 = Square cir2: " << (cir1 == cir2) << std::endl;

    std::cout << "-------------------" << std::endl;

    try
    {
        Triangle tr_bad(-2.0, 3.0, 4.0);
    }
    catch(const SidesException& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Triangle tr_bad(2, 4, 8);
    }
    catch(const SidesException& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    try
    {
        Rectangle rec_bad(-3.13, 31);
    }
    catch(const SidesException& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Circle cir_bad(-5);
    }
    catch(const RadiusException& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}