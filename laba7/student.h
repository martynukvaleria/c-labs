
#ifndef LAB7_STUDENT_H
#define LAB7_STUDENT_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>


using namespace std;


class Student {

protected:
    int id;
    char *name;
    int course;
    int group;
    int record_book;
public:

    Student(char *name, int course, int group, int record_book);

    Student(const Student &origin) = default;

    void SetStudentsName(char *student_name) { name = student_name; }

    void SetStudentsCourse(int course_number) { course = course_number; }

    void SetStudentsGroup(int group_number) { group = group_number; }

    char *GetStudentsName() { return name; }

    int GetStudentsCourse() const { return course; }

    int GetStudentsGroup() const { return group; }

    int GetStudentsRecordBook() const { return record_book; }

    int GetStudentsId() const { return id; }

    friend ostream &operator<<(ostream &out, const Student &student);

    [[nodiscard]] virtual double AverageScore() const = 0;
};


#endif //LAB7_STUDENT_H
