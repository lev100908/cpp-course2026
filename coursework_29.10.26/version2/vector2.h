#pragma once

#include <algorithm>

class VectorVer2 {
    int size_;
    double* data_;
    int check_size(int size); // Check size: if size > 0 return size, else throw error.
    void check_out_of_range(int index) const; // Check index for out_of_range_error: if not 0 < index < size throw error.
public:
    explicit VectorVer2(int size);
    VectorVer2(std::initializer_list<double> lst);

    ~VectorVer2();

    VectorVer2(const VectorVer2& other);
    VectorVer2& operator=(const VectorVer2& other);

    VectorVer2(VectorVer2&& other);
    VectorVer2& operator=(VectorVer2&& other);

    double& operator[](int index);
    double operator[](int index) const;

    int size() const;
    double get(int index) const;
    void set(int index , double value);
};