#include "triangle.h"
#include "exceptions.h"
#include <cmath>

Triangle::Triangle(double a, double b, double c) : Shape("Triangle"), a_(a), b_(b), c_(c)
{
    if (a <= 0.0 | b <= 0.0 | c <= 0.0)
        throw SidesException("one side or several sides < 0");
    if (a + b <= c | a + c <= b | b + c <= a)
        throw SidesException("the condition for the existence of a triangle is not met");
}

Triangle::~Triangle() = default;

Triangle::Triangle(const Triangle &other) : Shape(other), a_(other.a_), b_(other.b_), c_(other.c_) {}

Triangle::Triangle(Triangle &&other) noexcept : Shape(std::move(other)), a_(other.a_), b_(other.b_), c_(other.c_) {}

Triangle &Triangle::operator=(const Triangle &other)
{
    if (this != &other)
    {
        Shape& base = *this;
        base = other;
        a_ = other.a_;
        b_ = other.b_;
        c_ = other.c_;
    }
    return *this;
}

Triangle &Triangle::operator=(Triangle &&other) noexcept
{
    if (this != &other)
    {
        Shape& base = *this;
        base = std::move(other);
        a_ = other.a_;
        b_ = other.b_;
        c_ = other.c_;
        other.a_ = 0.0;
        other.b_ = 0.0;
        other.c_ = 0.0;
    }
    return *this;
}

double Triangle::area() const
{
    double half_per = perimeter() / 2;
    return pow((half_per * (half_per - a_) * (half_per - b_) * (half_per - c_)), 0.5);
}

double Triangle::perimeter() const
{
    return a_ + b_ + c_;
}
