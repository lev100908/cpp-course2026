#include "shape.h"

Shape::Shape(std::string name) : name_(name) {}

Shape::~Shape() = default;

Shape::Shape(const Shape &other) : name_(other.name_) {}

Shape::Shape(Shape &&other) noexcept : name_(std::move(other.name_)) {}

Shape& Shape::operator=(const Shape &other)
{
    if (this != &other)
    {
        name_ = other.name_;
    }
    return *this;
}

Shape& Shape::operator=(Shape &&other) noexcept
{
    if (this != &other)
    {
        name_ = std::move(other.name_);
    }
    return *this;
}

const std::string &Shape::getName() const
{
    return name_;
}

double Shape::area() const
{
    return 0.0;
}

double Shape::perimeter() const
{
    return 0.0;
}
