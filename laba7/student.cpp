#include "student.h"
#include <ctime>
#include <cstdlib>
using namespace std;

Student::Student(char *m_name, int m_course, int m_group, int m_record_book) :
        name(m_name), course(m_course), group(m_group), record_book(m_record_book) {
    srand(time(nullptr));
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
