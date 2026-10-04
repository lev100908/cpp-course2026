#pragma once

#include <exception>
#include <string>

class GeometryException: public std::exception
{
protected:
    std::string msg_;
public:
    explicit GeometryException(std::string msg): msg_(std::move(msg)) {}
    const char* what() const noexcept override final {return msg_.c_str(); }
};

class SidesException: public GeometryException
{
public:
    explicit SidesException(const std::string& msg): GeometryException("Invalid sides: " + msg) {}
};

class RadiusException: public GeometryException
{
public:
    explicit RadiusException(const std::string& msg): GeometryException("Invalid radius: " + msg) {}
};

