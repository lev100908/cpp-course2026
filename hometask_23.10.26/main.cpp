#include "student.h"
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    Student s1 ("Ivan", "784");    
    s1.addMark(2, 6);
    s1.addMark(3, 8);
    s1.addMark(4, 2);
    s1.addMark(5, 1);

    Student s2 ("Sasha", "785");    
    s2.addMark(2, 2);
    s2.addMark(3, 5);
    s2.addMark(4, 10);
    s2.addMark(5, 12);

    Student s3 ("Igor", "786");    
    s3.addMark(2, 1);
    s3.addMark(3, 4);
    s3.addMark(4, 7);
    s3.addMark(5, 9);

    Student s4 ("Slava", "784");    
    s4.addMark(2, 4);
    s4.addMark(3, 3);
    s4.addMark(4, 1);
    s4.addMark(5, 12);

    std::cout << s1 << s2 << s3 << s4;

    std::vector<Student> students{s1, s2, s3, s4};

    std::sort(students.begin(), students.end()); 
    // lambda-функция или функтор не нужны, так как перегружен operator< 
    // (если сортировать нужно по возрастанию среднего балла)
    // Если использовать lambda-функцию:
    // std::sort(students.begin(), students.end(), [](const Student& lhs, const Student& rhs) { return lhs.getAverageScore() < rhs.getAverageScore();});

    std::cout << students;
}