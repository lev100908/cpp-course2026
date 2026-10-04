#include "square.h"

Square::Square(double side) : Rectangle("Square", side, side) {}

Square::~Square() = default;

Square::Square(const Square &other) : Rectangle(other) {}

Square::Square(Square &&other) noexcept : Rectangle(std::move(other)) {}

Square &Square::operator=(const Square &other)
{
    if (this != &other)
    {
        Rectangle& base = *this;
        base = other;
    }
}

Square &Square::operator=(Square &&other) noexcept
{
    if (this != &other)
    {
        Rectangle& base = *this;
        base = std::move(other);
    }
}
