#include "vector1.h"

#include <exception>
#include <iostream>

int main() 
{
    VectorVer1 vec(5);

    std::cout << "Vector size: " << vec.size() << std::endl;

    vec.set(0, 1.4);
    vec.set(1, 1.5);
    vec.set(2, 1.6);
    vec.set(3, 1.7);
    vec.set(4, 1.8);

    std::cout << "vec[3] == 1.7: " << (vec.get(3) == 1.7) << std::endl;

    std::cout << "================" << std::endl;

    try
    {
        VectorVer1 vec(-5);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }

    try
    {
        vec.get(5);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }
    
    try
    {
        vec.set(5, 45.1);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }
}