#include "vector1.h"

#include <stdexcept>
#include <cstdint>

Vector::Vector(int size) : size_(size), data_(nullptr)
{
    if (size_ < 0)
        throw std::invalid_argument("Size must be positive.");

    data_ = new double[size_];

    for (std::size_t i = 0; i < size_; ++i)
    {
        data_[i] = 0.0;
    }
}

Vector::~Vector()
{
    delete[] data_;
}

int Vector::size() const
{
    return size_;
}

double Vector::get(int index) const
{
    if (index < 0 | index >= size_)
        throw std::out_of_range("Vector index out of range");

    return data_[index];
}

void Vector::set(int index, double value)
{
    if (index < 0 | index >= size_)
        throw std::out_of_range("Vector index out of range");

    data_[index] = value;
}
