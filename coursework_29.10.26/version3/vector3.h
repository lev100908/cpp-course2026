#pragma once

#include <algorithm>
#include <memory>

template<typename T, typename A = std::allocator<T>>
class VectorVer3 {
    A alloc_;
    int size_;
    int capacity_;
    T* data_;
    int check_size(int size); // Check size: if size > 0 return size, else throw error.
    // void check_out_of_range(int index) const; // Check index for out_of_range_error: if not 0 < index < size throw error.
public:
    VectorVer3() : size_(0), capacity_(0), data_(nullptr);
    explicit VectorVer3(int size);
    VectorVer3(std::initializer_list<T> lst);

    ~VectorVer3();

    VectorVer3(const VectorVer3& other);
    VectorVer3& operator=(const VectorVer3& other);

    VectorVer3(VectorVer3&& other);
    VectorVer3& operator=(VectorVer3&& other);

    double& operator[](int index);
    double operator[](int index) const;

    int size() const;
    T get(int index) const;
    void set(int index , T value);
};
