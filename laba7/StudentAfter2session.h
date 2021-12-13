#ifndef LAB7_STUDENTAFTER2SESSION_H
#define LAB7_STUDENTAFTER2SESSION_H

#include "StudentAfter1session.h"

class StudentAfter2session : public StudentAfter1session {
protected:
    int marksAfter2session[5]{};
public:
    StudentAfter2session(char *name, int course, int group, int record_book, const int marks[5]);

    StudentAfter2session(const StudentAfter2session &origin) = default;

    void SetStudentsGrades(int number_of_subject, int grade) override;

    int GetStudentsGrade(int number_of_subject) override;

    double AverageScore() const override;

    friend ostream &operator<<(ostream &out, const StudentAfter2session &studentAfter2Session);
};

double CalculateAverageScoreAfter1session(const vector<StudentAfter1session> &students, int group);

double CalculateAverageScoreAfter2session(const vector<StudentAfter2session> &students, int group);


#endif //LAB7_STUDENTAFTER2SESSION_H
