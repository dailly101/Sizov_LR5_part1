#ifndef MATH_TASK_H
#define MATH_TASK_H

#include <string>
#include <iostream>
using namespace std;

bool UserInput(const string& input) {
    if (input.empty()) return false;
    for (char c : input) {
        if (!isdigit(c)) return false;
    }
    return true;
}

void EnterDigit(int& varLink, const string& label) {
    string raw_input;
    cout << label << " = ";
    getline(cin, raw_input);
    while (!UserInput(raw_input)) {
        cout << "Ошибка ввода! " << label << " = ";
        getline(cin, raw_input);
    }
    varLink = stoi(raw_input);
}

int CalcRectangleArea(int NumberA, int NumberB) {
    return NumberA * NumberB;
}

#endif