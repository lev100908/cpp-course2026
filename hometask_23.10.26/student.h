#pragma once
#include <string>
#include <vector>

class Student
{
private:
    std::string name_;
    std::string group_;
    std::vector<int> marks_;
    double sum_marks_;
    double averageScore_;
    void upgradeAverageScore();

public:
    Student(std::string name, std::string group);

    ~Student();

    Student(const Student& other);
    Student(Student&& other);

    Student& operator=(const Student& other);
    Student& operator=(Student&& other) noexcept;

    void addMark(int mark);
    void addMark(int mark, int quantity);
    const std::vector<int>& getMarks() const;
    double getAverageScore() const;
    friend std::ostream& operator<<(std::ostream& stream, const Student& rhs);
};

bool operator<(const Student& lhs, const Student& rhs);
