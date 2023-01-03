/*
 * COPYRIGHT (C) 2022 @ Krasokha Vitalii
 * ALL RIGHTS RESERVED
 */

#include <iostream>
#include "Calculator/Calculator.h"

using namespace strcalc::calculator;
using namespace strcalc::common;
using namespace std;

int main(int, char**) {

    Calculator<double> calculator;
    
    Value<double> result{0};

    auto status = calculator.calculate("(5+3*(5+6/(3*6)+5)/6*3^2)", result);

    cout << "Expression result - " << result << endl;
    cout << "Expression status - " << static_cast<int32_t>(status) << endl;
    
    return 0;
}
