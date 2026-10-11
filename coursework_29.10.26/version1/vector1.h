#pragma once

class VectorVer1 {
    int size_;
    double* data_;
public:
    VectorVer1(int size);
    ~VectorVer1();

    int size() const;
    double get(int index) const;
    void set(int index , double value);
};