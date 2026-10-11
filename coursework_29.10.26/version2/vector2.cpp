#include "vector2.h"

#include <stdexcept>
#include <algorithm>


int VectorVer2::check_size(int size)
{
    if (size_ < 0)
        throw std::invalid_argument("Size must be positive.");
    return size;
}

void VectorVer2::check_out_of_range(int index) const
{
    if (index < 0 | index >= size_)
        throw std::out_of_range("Vector index out of range");
}

VectorVer2::VectorVer2(int size) : size_(check_size(size)), data_(new double[size_])
{
    for (std::size_t i = 0; i < size_; ++i)
    {
        data_[i] = 0.0;
    }
}

VectorVer2::VectorVer2(std::initializer_list<double> lst)
{
    std::copy(lst.begin(), lst.end(), data_);
}

VectorVer2::~VectorVer2()
{
    delete[] data_;
}

VectorVer2::VectorVer2(const VectorVer2 &other) : size_(other.size_), data_(new double[other.size_]) 
{
    std::copy(other.data_, other.data_ + size_, data_);
}

VectorVer2 &VectorVer2::operator=(const VectorVer2 &other)
{
    if (this != &other)
    {
        double* tmp_data = new double[other.size_];
        std::copy(other.data_, other.data_ + other.size_, tmp_data);

        delete[] data_;
        data_ = tmp_data;
        size_ = other.size_;
    }
    return *this;
}

VectorVer2::VectorVer2(VectorVer2 &&other) : size_(other.size_), data_(other.data_)
{
    other.size_ = 0;
    other.data_ = nullptr;
}

VectorVer2 &VectorVer2::operator=(VectorVer2 &&other)
{
    if (this != &other)
    {
        delete[] data_;
        data_ = other.data_;
        size_ = other.size_;

        other.data_ = nullptr;
        other.size_ = 0;
    }
    return *this;
}

double &VectorVer2::operator[](int index)
{
    check_out_of_range(index);
    return data_[index];
}

double VectorVer2::operator[](int index) const
{
    check_out_of_range(index);
    return data_[index];
}

int VectorVer2::size() const
{
    return size_;
}

double VectorVer2::get(int index) const
{
    return (*this)[index];
}

void VectorVer2::set(int index, double value)
{
    (*this)[index] = value;
}
