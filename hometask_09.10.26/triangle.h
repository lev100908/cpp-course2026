#pragma once

#include "shape.h"


class Triangle: public Shape
{
private:
    double a_;
    double b_;
    double c_;

public:
    Triangle(double a, double b, double c);

    ~Triangle();

    Triangle(const Triangle& other);
    Triangle(Triangle&& other) noexcept;

    Triangle& operator=(const Triangle& other);
    Triangle&& operator=(Triangle&& other) noexcept;

    double area() const override;
    double perimeter() const override;
};