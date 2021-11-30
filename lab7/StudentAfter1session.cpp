#include "StudentAfter1session.h"
#include "StudentAfter2session.h"

#include <iostream>

StudentAfter1session::StudentAfter1session(char *name, int course, int group, int record_book, const int marks[4])
        : Student(name, course, group, record_book) {
    for (int i = 0; i < 4; ++i) {
        marksAfter1session[i] = marks[i];
    }
}

void StudentAfter1session::SetStudentsGrades(int number_of_subject, int grade) {
    marksAfter1session[number_of_subject - 1] = grade;
}

int StudentAfter1session::GetStudentsGrade(int number_of_subject) {
    return marksAfter1session[number_of_subject - 1];
}

double StudentAfter1session::AverageScore() const {
    int sum = 0;
    for (int i = 0; i < 4; ++i) {
        sum += marksAfter1session[i];
    }
    return sum / 4;
}

ostream &operator<<(ostream &out, const StudentAfter1session &studentAfter1Session) {
    Student student(studentAfter1Session);
    out << student;
    out << "Student's grades: ";
    for (int i = 0; i < 4; i++) {
        out << studentAfter1Session.marksAfter1session[i] << " ";
    }
    return out;
}



