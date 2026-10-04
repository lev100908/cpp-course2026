#pragma once

#include "rectangle.h"


class Square final: public Rectangle
{
private:
    double side_;

public:
    Square(double side);

    ~Square() override;

    Square(const Square& other);
    Square(Square&& other) noexcept;

    Square& operator=(const Square& other);
    Square& operator=(Square&& other) noexcept;
};