#include "rectangle.h"
#include "exceptions.h"

Rectangle::Rectangle(const std::string& name, double w, double h) : Shape(name), width_(w), height_(h) 
{
    if (w <= 0 | h <= 0)
        throw SidesException("sides < 0");
}

Rectangle::Rectangle(double w, double h) : Rectangle("Rectangle", w, h) {}

Rectangle::~Rectangle() = default;

Rectangle::Rectangle(const Rectangle &other) : Shape(other), width_(other.width_), height_(other.height_) {}

Rectangle::Rectangle(Rectangle &&other) noexcept : Shape(std::move(other)), width_(other.width_), height_(other.height_) 
{
    other.width_ = 0;
    other.height_ = 0;
}

Rectangle &Rectangle::operator=(const Rectangle &other)
{
    if (this != &other)
    {
        Shape& base = *this;
        base = other;
        width_ = other.width_;
        height_ = other.height_;
    }
    return *this;
}

Rectangle &Rectangle::operator=(Rectangle &&other) noexcept
{
    if (this != &other)
    {
        Shape& base = *this;
        base = std::move(other);
        width_ = other.width_;
        height_ = other.height_;
        other.width_ = 0;
        other.height_ = 0;
    }
    return *this;
}

double Rectangle::area() const
{
    return width_ * height_;
}

double Rectangle::perimeter() const
{
    return 2.0 * (width_ + height_);
}
