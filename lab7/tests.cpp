#include "gtest/gtest.h"
#include "student.h"
#include "StudentAfter1session.h"
#include "StudentAfter2session.h"


TEST(Student,GetTests){
    Student student("name",1,4,1234);
   // ASSERT_EQ(student.GetStudentsName(),"name");
    ASSERT_EQ(student.GetStudentsCourse(),1);
    ASSERT_EQ(student.GetStudentsGroup(),4);
    ASSERT_EQ(student.GetStudentsRecordBook(),1234);
}
TEST(Student,SetTests){
    Student student("name",1,4,1234);
    student.SetStudentsName("name");
    student.SetStudentsCourse(1);
    student.SetStudentsGroup(4);
    // ASSERT_EQ(student.GetStudentsName(),"name");
    ASSERT_EQ(student.GetStudentsCourse(),1);
    ASSERT_EQ(student.GetStudentsGroup(),4);
}
TEST(Student, OutputTest) {
    Student student("name",1,4,1234);
    testing::internal::CaptureStdout();
    std::cout << student;
    std::string output = testing::internal::GetCapturedStdout();
    //   ASSERT_TRUE(output == "student\n1\n4\n1234\n");
}
TEST(StudentAfter1session,GetTests){
    int mas[4] = {10, 10, 10, 10};
    StudentAfter1session student("name",1,4,1234, mas);
    student.SetStudentsName("name");
    // ASSERT_EQ(student.GetStudentsName(),"name");
    student.SetStudentsCourse(1);
    ASSERT_EQ(student.GetStudentsCourse(),1);
    student.SetStudentsGroup(4);
    ASSERT_EQ(student.GetStudentsGroup(),4);
}

TEST(StudentAfter1session,SetTests){
    int mas[4] = {10, 10, 10, 10};
    StudentAfter1session student("name",1,4,1234, mas);
    student.SetStudentsName("name");
    // ASSERT_EQ(student.GetStudentsName(),"name");
    student.SetStudentsCourse(1);
    ASSERT_EQ(student.GetStudentsCourse(),1);
    student.SetStudentsGroup(4);
    ASSERT_EQ(student.GetStudentsGroup(),4);
}

TEST (StudentAfter1session, AverageMark) {
    int mas[4] = {10, 10, 10, 10};
    StudentAfter1session student("name",1,4,1234, mas);
    ASSERT_EQ(student.AverageScore(), 10);
}

TEST(StudentAfter1session, SetGetStudentsGrades){
    int mas[4] = {10, 10, 10, 10};
    StudentAfter1session student("name",1,4,1234, mas);
    student.SetStudentsGrades(4, 10);
    ASSERT_EQ(mas, student.GetStudentsGrade(4));
}

TEST (StudentAfter2session, SetGetStudentsGrades) {
    int mas[5] = {12, 12, 12, 12, 12};
    StudentAfter2session student( "name", 1, 5, 212, mas);
    student.SetStudentsGrades(5,12);
    ASSERT_EQ(mas, student.GetStudentsGrade(5));
}

TEST(GroupAfter1session, avg){
    int mas1[4] = {12, 12, 12, 12};
    int mas2[4] = {12, 12, 12, 12};
    int mas3[4] = {0, 0, 0, 0};
    StudentAfter1session student1("name1",1 ,2,123, mas1);
    StudentAfter1session student2("name2",1 ,2,124, mas2);
    StudentAfter1session student3("name3",1 ,2,125, mas3);
    std::vector<StudentAfter1session> students = {student1, student2, student3};
    ASSERT_EQ(12, CalculateAverageScoreAfter1session(students,2));
}

TEST(GroupAfter2session, avg){
    int mas1[5] = {12, 12, 12, 12, 12};
    int mas2[5] = {12, 12, 12, 12, 12};
    int mas3[5] = {0, 0, 0, 0, 0};
    StudentAfter2session student1("name1",1 ,2,123, mas1);
    StudentAfter2session student2("name2",1 ,2,124, mas2);
    StudentAfter2session student3("name3",1 ,2,125, mas3);
    std::vector<StudentAfter2session> students = {student1, student2, student3};
    ASSERT_EQ(12,CalculateAverageScoreAfter2session(students,2));
}

TEST (Student, CopyTests) {
    Student Man("name", 2, 2, 257);
    Student Woman(Man);
    ASSERT_EQ(Man.GetStudentsGroup(), Woman.GetStudentsGroup());
    ASSERT_EQ(Man.GetStudentsName(), Woman.GetStudentsName());
    ASSERT_EQ(Man.GetStudentsCourse(), Woman.GetStudentsCourse());
    ASSERT_EQ(Man.GetStudentsRecordBook(), Woman.GetStudentsRecordBook());
}


