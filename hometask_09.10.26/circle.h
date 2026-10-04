#pragma once

#include "shape.h"

const double PI = 3.1415926535;

class Circle: public Shape
{
private:
    double radius_;

public:
    Circle(double radius);

    ~Circle();

    Circle(const Circle& other);
    Circle(Circle&& other) noexcept;

    Circle& operator=(const Circle& other);
    Circle& operator=(Circle&& other) noexcept;

    double area() const override;
    double perimeter() const override;
};