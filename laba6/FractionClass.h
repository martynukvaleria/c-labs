#pragma once

#include <cmath>
#include <iostream>
#include <cassert>

class Fraction {
public:
    Fraction(int Numerator, int Denominator);

    Fraction(Fraction &fraction);

    int GetNumerator() const { return numerator; }

    int GetDenominator() const { return denominator; }

    void Addition(Fraction &fraction2);

    void Multiplication(Fraction &fraction2);

    void Division(Fraction &fraction2);

    void PrintFraction() const;

private:
    int Nod(int Numerator, int Denominator);

    void Reduction(int &Numerator, int &Denominator);

    int numerator;
    int denominator;
};