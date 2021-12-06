
#ifndef LAB7_STUDENT_H
#define LAB7_STUDENT_H

#include <iostream>
#include <string>
#include <vector>
#include "StudentAfter1session.h"
#include "StudentAfter2session.h"

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

    int GetSudentsRecordBook() const { return record_book; }

    int GetStudentsId() const { return id; }

    friend ostream &operator<<(ostream &out, const Student &student);
};

double CalculateAverageScoreAfter1session(const vector<StudentAfter1session> &students, int group);

double CalculateAverageScoreAfter2session(const vector<StudentAfter2Session> &students, int group);

#endif //LAB7_STUDENT_H
