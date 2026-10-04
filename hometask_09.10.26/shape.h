#pragma once

#include <string>

class Shape
{
private:
    std::string name_;
public:
    Shape(std::string name);

    virtual ~Shape();

    Shape(const Shape& other);
    Shape(Shape&& other) noexcept;

    Shape& operator=(const Shape& other);
    Shape& operator=(Shape&& other) noexcept;

    const std::string& getName() const;
    virtual double area() const;
    virtual double perimeter() const;
};