#ifndef LAB7_STUDENTAFTER1SESSION_H
#define LAB7_STUDENTAFTER1SESSION_H

#include "student.h"
#include <iostream>

class StudentAfter1session : public Student {

protected:
    int marksAfter1session[4]{};
public:
    StudentAfter1session(char *name, int course, int group, int record_book, const int marks[4]);

    StudentAfter1session(const StudentAfter1session &origin) = default;

    virtual void SetStudentsGrades(int number_of_subject, int grade);

    virtual int GetStudentsGrade(int number_of_subject);

    virtual double AverageScore() const;

    friend ostream &operator<<(ostream &out, const StudentAfter1session &studentAfter1Session);
};

#endif //LAB7_STUDENTAFTER1SESSION_H
