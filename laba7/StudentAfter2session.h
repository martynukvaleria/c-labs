#ifndef LAB7_STUDENTAFTER2SESSION_H
#define LAB7_STUDENTAFTER2SESSION_H

#include "StudentAfter1session.h"
#include <iostream>

class StudentAfter2session : public StudentAfter1session {
protected:
    int marksAfter2session[5]{};
public:
    StudentAfter2session(char *name, int course, int group, int record_book, const int marks[5]);

    StudentAfter2session(const StudentAfter2session &origin) = default;

    void SetStudentsGrades(int number_of_subject, int grade) override;

    int GetStudentsGrade(int number_of_subject) override;

    double AverageScore() override;

    friend ostream &operator<<(ostream &out, const StudentAfter2session &studentAfter2Session);
};


#endif //LAB7_STUDENTAFTER2SESSION_H
