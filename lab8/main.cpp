#include <iostream>
#include "Stack.h"
#include "calc.h"

int main() {
    Stack<int> s;
//    s.push(5);
//    s.push(7);
//    s.push(9);
//    s.push(4);
//    int temp, p;
//    s >> temp >> p;
//    std::cout << temp << " " << p << " " << s.size();
std::cout << Calculator::Calculate("12345679*1000");

}

