#include "StudentAfter2session.h"
#include <iostream>

StudentAfter2session::StudentAfter2session(char *name, int course, int group, int record_book, const int *marks)
        : StudentAfter1session(name, course, group, record_book, marks) {
    for (int i = 0; i < 5; ++i) {
        marksAfter2session[i] = marks[i];
    }
}

void StudentAfter2session::SetStudentsGrades(int number_of_subject, int grade) {
    marksAfter2session[number_of_subject - 1] = grade;
}

int StudentAfter2session::GetStudentsGrade(int number_of_subject) {
    return marksAfter2session[number_of_subject - 1];
}

double StudentAfter2session::AverageScore() const {
    double sum = 0;
    for (int i = 0; i < 5; ++i) {
        sum += marksAfter2session[i];
    }
    sum = ((sum / 5) + StudentAfter1session::AverageScore() / 4);
    return sum / 2;
}

ostream &operator<<(ostream &out, const StudentAfter2session &studentAfter2Session) {
    out << dynamic_cast<const StudentAfter1session&>(studentAfter2Session);
    out << "Student's grades: ";
    for (int i = 0; i < 5; i++) {
        out << studentAfter2Session.marksAfter2session[i] << " ";
    }
    return out;
}


