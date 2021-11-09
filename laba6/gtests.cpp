#include "FractionClass.h"
#include <gtest/gtest.h>

TEST(FracConstruct, TwoPositive) {
    Fraction frac(3, 4);
    ASSERT_EQ(frac.GetNumerator(), 3);
    ASSERT_EQ(frac.GetDenominator(), 4);
}

TEST(FracConstruct, TwoNegative) {
    Fraction frac(-2, -5);
    ASSERT_EQ(frac.GetNumerator(), 2);
    ASSERT_EQ(frac.GetDenominator(), 5);
}

TEST(FracConstruct, NegNumerator) {
    Fraction frac(-1, 2);
    ASSERT_EQ(frac.GetNumerator(), -1);
    ASSERT_EQ(frac.GetDenominator(), 2);
}

TEST(FracConstruct, NegDenominator) {
    Fraction frac(1, -2);
    ASSERT_EQ(frac.GetNumerator(), -1);
    ASSERT_EQ(frac.GetDenominator(), 2);
}

TEST(FracConstruct, CancellableFrac) {
    Fraction frac(2, 4);
    ASSERT_EQ(frac.GetNumerator(), 1);
    ASSERT_EQ(frac.GetDenominator(), 2);
}

TEST(FracConstruct, NotCancellableFrac) {
    Fraction frac(2, 3);
    ASSERT_EQ(frac.GetNumerator(), 2);
    ASSERT_EQ(frac.GetDenominator(), 3);
}

TEST(FracConstruct, ZeroNumerator) {
    Fraction frac(0, -5);
    ASSERT_EQ(frac.GetNumerator(), 0);
    ASSERT_EQ(frac.GetDenominator(), 1);
}

TEST(FracCopyConstrust, СancellableFrac) {
    Fraction frac1(8, 20);
    Fraction frac2(frac1);
    ASSERT_EQ(frac2.GetNumerator(), 2);
    ASSERT_EQ(frac2.GetDenominator(), 5);
}

TEST(FracCopyConstrust, NotСancellableFrac) {
    Fraction frac1(9, 20);
    Fraction frac2(frac1);
    ASSERT_EQ(frac2.GetNumerator(), 9);
    ASSERT_EQ(frac2.GetDenominator(), 20);
}

TEST(FracCopyConstrust, NegNumerator) {
    Fraction frac1(-3, 8);
    Fraction frac2(frac1);
    ASSERT_EQ(frac2.GetNumerator(), -3);
    ASSERT_EQ(frac2.GetDenominator(), 8);
}

TEST(FracCopyConstrust, NegDenominator) {
    Fraction frac1(8, -11);
    Fraction frac2(frac1);
    ASSERT_EQ(frac2.GetNumerator(), -8);
    ASSERT_EQ(frac2.GetDenominator(), 11);
}

TEST(FracCopyConstrust, NegDenominatorAndNumerator) {
    Fraction frac1(-3, -4);
    Fraction frac2(frac1);
    ASSERT_EQ(frac2.GetNumerator(), 3);
    ASSERT_EQ(frac2.GetDenominator(), 4);
}

TEST(FracAddition, AddNull) {
    Fraction frac1(1, 2);
    Fraction frac2(0, 1);
    frac1.Addition(frac2);
    ASSERT_EQ(frac1.GetNumerator(), 1);
    ASSERT_EQ(frac1.GetDenominator(), 2);
}

TEST(FracAddition, DenominatorEqOne) {
    Fraction frac1(1, 2);
    Fraction frac2(4, 1);
    frac1.Addition(frac2);
    ASSERT_EQ(frac1.GetNumerator(), 9);
    ASSERT_EQ(frac1.GetDenominator(), 2);
}

TEST(FracAddition, DenominatorNotEqOne) {
    Fraction frac1(2, 5);
    Fraction frac2(1, 4);
    frac1.Addition(frac2);
    ASSERT_EQ(frac1.GetNumerator(), 13);
    ASSERT_EQ(frac1.GetDenominator(), 20);
}

TEST(FracAddition, Substraction) {
    Fraction frac1(2, 5);
    Fraction frac2(-1, 4);
    frac1.Addition(frac2);
    ASSERT_EQ(frac1.GetNumerator(), 3);
    ASSERT_EQ(frac1.GetDenominator(), 20);

    Fraction frac3(1, 4);
    Fraction frac4(-2, 5);
    frac3.Addition(frac4);
    ASSERT_EQ(frac3.GetNumerator(), -3);
    ASSERT_EQ(frac3.GetDenominator(), 20);
}

TEST(FracAddition, AddTheOpposite) {
    Fraction frac1(2, 5);
    Fraction frac2(-2, 5);
    frac1.Addition(frac2);
    ASSERT_EQ(frac1.GetNumerator(), 0);
    ASSERT_EQ(frac1.GetDenominator(), 1);
}

TEST(FracMultiplication, MultiByZero) {
    Fraction frac1(2, 5);
    Fraction frac2(0, 1);
    frac1.Multiplication(frac2);
    ASSERT_EQ(frac1.GetNumerator(), 0);
    ASSERT_EQ(frac1.GetDenominator(), 1);
}

TEST(FracMultiplication, MultiByNegative) {
    Fraction frac1(1, 5);
    Fraction frac2(-3, 4);
    frac1.Multiplication(frac2);
    ASSERT_EQ(frac1.GetNumerator(), -3);
    ASSERT_EQ(frac1.GetDenominator(), 20);
}

TEST(FracMultiplication, MultiByPositive) {
    Fraction frac1(1, 5);
    Fraction frac2(3, 4);
    frac1.Multiplication(frac2);
    ASSERT_EQ(frac1.GetNumerator(), 3);
    ASSERT_EQ(frac1.GetDenominator(), 20);
}

TEST(FracMultiplication, MultiWithReduction) {
    Fraction frac1(2, 5);
    Fraction frac2(-3, 4);
    frac1.Multiplication(frac2);
    ASSERT_EQ(frac1.GetNumerator(), -3);
    ASSERT_EQ(frac1.GetDenominator(), 10);

    Fraction frac3(2, 5);
    Fraction frac4(3, 4);
    frac3.Multiplication(frac4);
    ASSERT_EQ(frac3.GetNumerator(), 3);
    ASSERT_EQ(frac3.GetDenominator(), 10);

    Fraction frac5(4, 5);
    Fraction frac6(5, 2);
    frac5.Multiplication(frac6);
    ASSERT_EQ(frac5.GetNumerator(), 2);
    ASSERT_EQ(frac5.GetDenominator(), 1);

    Fraction frac7(4, 5);
    Fraction frac8(-5, 2);
    frac7.Multiplication(frac8);
    ASSERT_EQ(frac7.GetNumerator(), -2);
    ASSERT_EQ(frac7.GetDenominator(), 1);
}

TEST(FracDivision, TheSame) {
    Fraction frac1(5, 6);
    Fraction frac2(frac1);
    frac1.Division(frac2);
    ASSERT_EQ(frac1.GetNumerator(), 1);
    ASSERT_EQ(frac1.GetDenominator(), 1);
}

TEST(FracDivision, DivByPositive) {
    Fraction frac1(5, 6);
    Fraction frac2(5, 3);
    frac1.Division(frac2);
    ASSERT_EQ(frac1.GetNumerator(), 1);
    ASSERT_EQ(frac1.GetDenominator(), 2);
}

TEST(FracDivision, DivByNegative) {
    Fraction frac1(5, 6);
    Fraction frac2(5, -3);
    frac1.Division(frac2);
    ASSERT_EQ(frac1.GetNumerator(), -1);
    ASSERT_EQ(frac1.GetDenominator(), 2);
}