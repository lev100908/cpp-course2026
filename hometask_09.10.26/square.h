#pragma once

#include "rectangle.h"


class Square: public Rectangle
{
private:
    double side_;

public:
    Square(double side);

    ~Square();

    Square(const Square& other);
    Square(Square&& other) noexcept;

    Square& operator=(const Square& other);
    Square& operator=(Square&& other) noexcept;
};