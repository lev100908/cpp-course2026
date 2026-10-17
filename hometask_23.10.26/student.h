#pragma once
#include <string>
#include <vector>

class Student
{
private:
    std::string name_;
    std::string group_;
    std::vector<std::string> marks_;
    double averageScore_;

public:
    Student(std::string name, std::string group);

    ~Student();

    Student(const Student& other);
    Student(Student&& other);

    Student& operator=(const Student& other);
    Student& operator=(Student&& other) noexcept;

    void addMark(int mark);
    std::vector<std::string>& getMarks() const;
    double getAverageScore() const;
};

bool operator<(const Student& lhs, const Student& rhs);
std::ofstream& operator<<(std::ofstream& stream, const Student& rhs);