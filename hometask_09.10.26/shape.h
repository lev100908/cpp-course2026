#pragma once

#include <string>

class Shape
{
private:
    std::string name;
public:
    Shape();
    Shape(std::string name);

    ~Shape();

    Shape(const Shape& other);
    Shape(Shape&& other) noexcept;

    Shape& operator=(const Shape& other);
    Shape&& operator=(Shape&& other) noexcept;

    const std::string& getName() const;
    double area() const;
    double perimeter() const;
};