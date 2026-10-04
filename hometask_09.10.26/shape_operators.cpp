#include "shape_operators.h"

bool almost_equal(double a, double b)
{
    return std::abs(a - b) < ERROR_RATE;
}

bool operator==(const Shape &lhs, const Shape &rhs)
{
    return almost_equal(lhs.area(), rhs.area());
}

bool operator^(const Shape &lhs, const Shape &rhs)
{
    return almost_equal(lhs.perimeter(), rhs.perimeter());
}

std::ostream& operator<<(std::ostream &stream, const Shape &rhs)
{
    stream << "Shape`s name: " << rhs.getName() << std::endl;
    stream << "Shape`s area: " << rhs.area() << std::endl;
    stream << "Shape`s perimeter: " << rhs.perimeter() << std::endl;

    return stream;
}
