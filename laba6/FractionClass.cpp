#include "FractionClass.h"

Fraction::Fraction(int Numerator, int Denominator) {
    assert(denominator != 0);
    numerator = Denominator < 0 ? -Numerator : Numerator;
    denominator = abs(Denominator);
    Reduction(numerator, denominator);
}

Fraction::Fraction(Fraction &fraction) {
    numerator = fraction.numerator;
    denominator = fraction.denominator;
}

void Fraction::Addition(Fraction &fraction2) {
    numerator = numerator * fraction2.denominator + denominator * fraction2.numerator;
    denominator = denominator * fraction2.denominator;
    Reduction(numerator, denominator);
}

void Fraction::Multiplication(Fraction &fraction2) {
    numerator = numerator * fraction2.numerator;
    denominator = denominator * fraction2.denominator;
    Reduction(numerator, denominator);
}

void Fraction::Division(Fraction &fraction2) {
    numerator = numerator * fraction2.denominator;
    denominator = denominator * fraction2.numerator;
    numerator = denominator < 0 ? -numerator : numerator;
    denominator = abs(denominator);
    Reduction(numerator, denominator);
}

void Fraction::PrintFraction() const {
    if (numerator == 0) {
        std::cout << 0 << '\n';
        return;
    }
    if ((denominator == 1) || (numerator == denominator)) {
        std::cout << numerator / denominator << '\n';
        return;
    }
    if (abs(numerator) > denominator) {
        int a = abs(numerator) / denominator;
        std::cout << a << " " << abs(numerator) - denominator * a << '/' << denominator << '\n';
        return;
    }
    std::cout << numerator << "/" << denominator << '\n';
}

int Fraction::Nod(int Numerator, int Denominator) {
    if (Numerator % Denominator == 0)
        return Denominator;
    if (Denominator % Numerator == 0)
        return Numerator;
    if (Numerator > Denominator)
        return Nod(Numerator % Denominator, Denominator);
    return Nod(Numerator, Denominator % Numerator);
}

void Fraction::Reduction(int &Numerator, int &Denominator) {
    int nod = Nod(abs(Numerator), abs(Denominator));
    Numerator /= nod;
    Denominator /= nod;
}