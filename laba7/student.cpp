#include "student.h"
#include <cstdlib>
#include <ctime>

using namespace std;

Student::Student(char *m_name, int m_course, int m_group, int m_record_book) :
        name(m_name), course(m_course), group(m_group), record_book(m_record_book) {
    srand(time(0));
    id = rand() % (4001) + 1000;
}

ostream &operator<<(ostream &out, const Student &student) {
    out << "Student's ID:" << student.id << '\n'
        << "Student's name:" << student.name << '\n'
        << "Student's course:" << student.course << '\n'
        << "Student's group:" << student.group << '\n'
        << "Student's record book:" << student.record_book << '\n';
    return out;
}

double CalculateAverageScoreAfter1session(const std::vector<StudentAfter1session> &group) {
    double result = 0;
    for (int j = 0; j < group.size(); j++) {
        double average = group[j].AverageScore();
        result += average;
    }
    return result / group.size();
}

double CalculateAverageScoreAfter2session(const std::vector<StudentAfter2session> &group) {
    double result = 0;
    for (int j = 0; j < group.size(); j++) {
        double second_term_average = group[j].AverageScore();
        result += second_term_average;
    }
    return result / group.size();
}