#pragma once

class Vector {
    int size_;
    double& data_;
public:
    Vector(int size);
    ~Vector();

    int size() const;
    double get(int index) const;
    void set(int index , double value);
};