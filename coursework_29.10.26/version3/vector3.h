#pragma once

#include <algorithm>
#include <memory>
#include <stdexcept>

template<typename T, typename A = std::allocator<T>>
class VectorVer3 {
    std::allocator<T> alloc_;
    int size_;
    int capacity_;
    T* data_;
    int check_size(int size); // Check size: if size > 0 return size, else throw error.
    void check_out_of_range(int index) const; // Check index for out_of_range_error: if not 0 < index < size throw error.
public:
    VectorVer3() : size_(0), capacity_(0), data_(nullptr) {};
    explicit VectorVer3(int size);
    VectorVer3(std::initializer_list<T> lst);

    ~VectorVer3();

    VectorVer3(const VectorVer3& other);
    VectorVer3& operator=(const VectorVer3& other);

    VectorVer3(VectorVer3&& other);
    VectorVer3& operator=(VectorVer3&& other);

    T& operator[](int index);
    const T& operator[](int index) const;

    T& at(int index);
    const T& at(int index) const;

    int size() const;
    int capacity() const;

    void reserve(int new_alloc);
    void resize(int new_size, T val = T());
    void push_back(const T& val);
};

template <typename T, typename A>
inline int VectorVer3<T, A>::check_size(int size)
{
    if (size < 0)
        throw std::invalid_argument("Size must be positive.");
    return size;
}

template <typename T, typename A>
inline void VectorVer3<T, A>::check_out_of_range(int index) const
{
    if (index < 0 | index >= size_)
        throw std::range_error("Index out of range");
}

template <typename T, typename A>
inline VectorVer3<T, A>::VectorVer3(int size) : size_(0), capacity_(0), data_(nullptr)
{
    resize(check_size(size));
}

template <typename T, typename A>
inline VectorVer3<T, A>::VectorVer3(std::initializer_list<T> lst) :
    size_(0), capacity_(0), data_(nullptr)
{
    resize(check_size(lst.size()));
    std::copy(lst.begin(), lst.end(), data_);
}

template <typename T, typename A>
inline VectorVer3<T, A>::~VectorVer3()
{
    for (std::size_t i = 0; i < size_; i++)
    {
        alloc_.destroy(&data_[i]);
    }

    alloc_.deallocate(data_, capacity_);
    
}

template <typename T, typename A>
inline VectorVer3<T, A>::VectorVer3(const VectorVer3 &other)
{
    if (other.size_ == 0) 
        return;

    data_ = alloc_.allocate(other.size);
    capacity_ = other.capacity_;

    for (std::size_t i = 0; i < other.size_; i++)
    {
        alloc_.construct(&data_[i], other.data_[i]);
    }

    size_ = other.size_;
        
}

template <typename T, typename A>
inline VectorVer3<T, A>& VectorVer3<T, A>::operator=(const VectorVer3 &other)
{
    if (this == &other)
        return *this;

    for (std::size_t i = 0; i < size_; i++)
    {
        alloc_.destroy(&data_[i]);
    }

    size_ = 0;
    
    reserve(other.size_);

    for (std::size_t i = 0; i < other.size_; i++)
    {
        alloc_.construct(&data_[i], other.data_[i]);
    }

    size_ = other.size_;
}

template <typename T, typename A>
inline VectorVer3<T, A>::VectorVer3(VectorVer3 &&other) :
    alloc_(std::move(other.alloc_)),
    size_(other.size_),
    capacity_(other.capacity_),
    data_(other.data_)
{
    other.capacity_ = 0;
    other.size_ = 0;
    other.data_ = nullptr;
}

template <typename T, typename A>
inline VectorVer3<T, A>& VectorVer3<T, A>::operator=(VectorVer3 &&other)
{
    if (this == &other)
        return *this;

    for (std::size_t i = 0; i < size_; i++)
    {
        alloc_.destroy(&data_[i]);
    }

    alloc_.deallocate(data_, capacity_);

    capacity_ = other.capacity_;
    size_ = other.size_;
    data_ = other.data_;

    other.capacity_ = 0;
    other.size_ = 0;
    other.data_ = nullptr;

    return *this;
}

template <typename T, typename A>
inline T &VectorVer3<T, A>::operator[](int index)
{
    return data_[index];
}

template <typename T, typename A>
inline const T &VectorVer3<T, A>::operator[](int index) const
{
    return data_[index];
}

template <typename T, typename A>
inline T &VectorVer3<T, A>::at(int index)
{
    check_out_of_range(index);
    return (*this)[index];
}

template <typename T, typename A>
inline const T &VectorVer3<T, A>::at(int index) const
{
    check_out_of_range(index);
    return (*this)[index];
}

template <typename T, typename A>
inline int VectorVer3<T, A>::size() const
{
    return size_;
}

template <typename T, typename A>
inline int VectorVer3<T, A>::capacity() const
{
    return capacity_;
}

template <typename T, typename A>
inline void VectorVer3<T, A>::reserve(int new_alloc)
{
    if (capacity_ >= new_alloc) 
        return;

    T* tmp_data = alloc_.allocate(new_alloc);

    for (std::size_t i = 0; i < size_; ++i)
    {
        alloc_.construct(&tmp_data[i], data_[i]);
        alloc_.destroy(&data_[i]);
    }

    alloc_.deallocate(data_, capacity_);

    data_ = tmp_data;
    capacity_ = new_alloc;
    
    
}

template <typename T, typename A>
inline void VectorVer3<T, A>::resize(int new_size, T val)
{
    check_size(new_size);

    reserve(new_size);

    // Сужение вектора
    for (std::size_t i = new_size; i < size_; i++) 
        alloc_.destroy(&data_[i]);
    
    // Расширение вектора
    for (std::size_t i = size_; i < new_size; i++) 
        alloc_.construct(&data_[i], val);

    size_ = new_size;
    
}

template <typename T, typename A>
inline void VectorVer3<T, A>::push_back(const T &val)
{
    if (capacity_ == 0)
        reserve(8);
    else if (size_ == capacity_)
        reserve(2 * capacity_);

    alloc_.construct(&data_[size_], val);
    ++size_;
}
