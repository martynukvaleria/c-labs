#include "calc.h"
#include <gtest/gtest.h>

TEST(Stack,StackTests){
    Stack<int> stack;
    stack << 5;
    ASSERT_EQ(stack.empty(), false);
    ASSERT_EQ(stack.size(), 1);
    ASSERT_EQ(stack.pop(), 5);
    ASSERT_EQ(stack.top(),5);
}

TEST(Calculator, BasicOperations) {
    ASSERT_EQ(Calculator::Calculate("2+2"), 4);
    ASSERT_EQ(Calculator::Calculate("2*2"), 4);
    ASSERT_EQ(Calculator::Calculate("abs(-2)"), 2);
    ASSERT_EQ(Calculator::Calculate("2-2"), 0);
    ASSERT_EQ(Calculator::Calculate("4-(2-2)"), 4);
    ASSERT_EQ(Calculator::Calculate("4%2"), 0);
}

TEST(Calculator, notEasyExpression) {
    ASSERT_EQ(Calculator::Calculate("(2*(45/3))/(3*2)"), 5);
    ASSERT_EQ(Calculator::Calculate("(abs(-14)/7)-1"), 1);
    ASSERT_EQ(Calculator::Calculate("abs((15%6)*4-24)"), 12);
    ASSERT_EQ(Calculator::Calculate("(abs(-5-18)-3)/10"), 2);
}

TEST(Calculator, UnaryMinus){
    ASSERT_EQ(Calculator::Calculate("-2-2"),-4);
    ASSERT_EQ(Calculator::Calculate("4/-2"),-2);
    ASSERT_EQ(Calculator::Calculate("(2+2)*-2"),-8);
    ASSERT_EQ(Calculator::Calculate("-2--2"),0);
}
