#include "functions.h"

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
