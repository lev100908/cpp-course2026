#include "circle.h"
#include "exceptions.h"
#include <numbers>

Circle::Circle(double radius) : Shape("Circle"), radius_(radius) 
{
    if (radius <= 0)
    {
        throw RadiusException("radius < 0");
    }
}

Circle::~Circle() = default;

Circle::Circle(const Circle &other) : Shape(other), radius_(other.radius_) {}

Circle::Circle(Circle &&other) noexcept  : Shape(std::move(other)), radius_(other.radius_) {}

Circle &Circle::operator=(const Circle &other)
{
    if (this != &other)
    {
        Shape& base = *this;
        base = other;
        radius_ = other.radius_;
    }
    return *this;
}

Circle &Circle::operator=(Circle &&other) noexcept
{
    if (this != &other)
    {
        Shape& base = *this;
        base = std::move(other);
        radius_ = other.radius_;
        other.radius_ = 0.0;
    }
    return *this;
}

double Circle::area() const
{
    return PI * radius_ * radius_;
}

double Circle::perimeter() const
{
    return 2 * PI * radius_;
}
