#include "vector3.h"
#include "vector3_operators.h"
#include <iostream>
#include <string>

struct WithoutBaseMan
{
    std::string name_;
    WithoutBaseMan(std::string name) : name_(name) {}; 
    friend std::ostream& operator<<(std::ostream& stream, const WithoutBaseMan& rhs)
    {
        stream << rhs.name_;
        return stream;
    }
};

struct BaseMan : public WithoutBaseMan
{
    std::string name_;
    BaseMan() : WithoutBaseMan("TheMan") {};
};


int main()
{
    VectorVer3<int> vec1 {1, 2, 3, 4};
    vec1[3] = 5;
    std::cout << vec1;

    VectorVer3<double> vec2(5);
    vec2.resize(6);
    std::cout << vec2;

    VectorVer3<std::string> vec3 {"one", "two", "three", "four"};
    std::cout << "Capacity vec3 before push_back: " <<  vec3.capacity() << std::endl;
    vec3.push_back("five");
    std::cout << "Capacity vec3 after push_back: " <<  vec3.capacity() << std::endl;
    std::cout << vec3;

    std::cout << "================" << std::endl;

    VectorVer3<BaseMan> vec4(3);
    std::cout << vec4;

    VectorVer3<WithoutBaseMan> vec5;
    vec5.resize(4, WithoutBaseMan("UnordinaryMan"));
    std::cout << vec5;

    std::cout << "================" << std::endl;


    try
    {
        vec5.at(123);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }

    try
    {
        vec5.at(-5);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }

    try
    {
        VectorVer3<double> vec6(-25);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
    }
    
    
}