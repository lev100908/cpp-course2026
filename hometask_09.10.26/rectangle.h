#pragma once

#include "shape.h"


class Rectangle: public Shape
{
private:
    double width;
    double height;

protected:
    // Конструктор с именем и размерами длины и высоты для Square
    Rectangle(std::string name, double w, double h);

public:
    Rectangle(double w, double h);

    ~Rectangle();

    Rectangle(const Rectangle& other);
    Rectangle(Rectangle&& other) noexcept;

    Rectangle& operator=(const Rectangle& other);
    Rectangle&& operator=(Rectangle&& other) noexcept;

    double area() const override;
    double perimeter() const override;
};