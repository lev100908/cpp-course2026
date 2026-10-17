#include "student.h"
#include <iostream>
#include <stdexcept>

void Student::upgradeAverageScore()
{
    int marks_quantity = marks_.size();

    if (marks_quantity > 0)
    {
        averageScore_ = sum_marks_ / marks_quantity;
    }
}

Student::Student(std::string name, std::string group) : name_(name), group_(group), averageScore_(0.0), sum_marks_(0.0) {}

Student::~Student() = default;

Student::Student(const Student &other) : 
    name_(other.name_), group_(other.group_), marks_(other.marks_), averageScore_(other.averageScore_), sum_marks_(other.sum_marks_) {}

Student::Student(Student &&other) :
    name_(std::move(other.name_)), group_(std::move(other.group_)), marks_(std::move(other.marks_)), averageScore_(other.averageScore_), sum_marks_(other.sum_marks_)
{
    other.averageScore_ = 0.0;
    other.sum_marks_ = 0.0;
}
Student &Student::operator=(const Student &other) 
{
    if (this != &other)
    {
        name_ = other.name_;
        group_ = other.group_;
        marks_ = other.marks_;
        averageScore_ = other.averageScore_;
        sum_marks_ = other.sum_marks_;
    }

    return *this;    
}

Student &Student::operator=(Student &&other) noexcept
{
    if (this != &other)
    {
        name_ = std::move(other.name_);
        group_ = std::move(other.group_);
        marks_ = std::move(other.marks_);
        averageScore_ = other.averageScore_;
        sum_marks_ = other.sum_marks_;

        other.averageScore_ = 0.0;
        other.sum_marks_ = 0.0;
    }

    return *this;  
}

void Student::addMark(int mark)
{
    marks_.push_back(mark);
    sum_marks_ += mark;
    upgradeAverageScore();
}

void Student::addMark(int mark, int quantity)
{
    if (quantity <= 0)
        throw std::invalid_argument("Quantity must be positive.");

    marks_.insert(marks_.end(), quantity, mark);
    sum_marks_ += mark * quantity;
    upgradeAverageScore();

}

const std::vector<int> &Student::getMarks() const
{
    return marks_;
}

double Student::getAverageScore() const
{
    return averageScore_;
}

std::ostream& operator<<(std::ostream &stream, const Student &rhs)
{
    stream << "Name: " << rhs.name_ << "\n"
            << "Group: " << rhs.group_ << "\n"
            << "Marks: ";

    for (std::size_t i = 0; i < rhs.marks_.size(); i++)
        stream << rhs.marks_[i] << ", ";

    stream << "\n" << "Average: " << rhs.averageScore_ << std::endl;

    return stream;
}

std::ostream &operator<<(std::ostream &stream, const std::vector<Student> &rhs)
{
    for (Student student : rhs)
        stream << student.name_ << " ";
    
    return stream;
}

bool operator<(const Student &lhs, const Student &rhs)
{
    return lhs.getAverageScore() < rhs.getAverageScore();
}


