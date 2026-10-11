#include "vector2.h"

#include <exception>
#include <iostream>

void print_vector(const VectorVer2& vec)
{
    for (std::size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

int main() 
{
    VectorVer2 vec = {1.14, 1.15, 1.17};
    std::cout << "vec: "; print_vector(vec);

    VectorVer2 vec1(vec);

    std::cout << "vec1: "; print_vector(vec1);

    VectorVer2 vec2(1);
    vec2 = vec;

    std::cout << "vec2: "; print_vector(vec2);

    VectorVer2 vec3(std::move(vec));

    std::cout << "vec: "; print_vector(vec);
    std::cout << "vec3: "; print_vector(vec3);
    
    VectorVer2 vec4(1);
    vec4 = std::move(vec1);

    std::cout << "vec1: "; print_vector(vec1);
    std::cout << "vec4: "; print_vector(vec4);

    std::cout << "vec4[1] == 1.15: " << (vec4[1] == 1.15) << std::endl;

    try
    {
        VectorVer2 vec(-5);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }

    try
    {
        vec[5];
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }
    
    try
    {
        vec[5] = 41.5;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }
    
}