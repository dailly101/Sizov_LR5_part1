#include "CUTE/cute.h"
#include "CUTE/cute_runner.h"
#include "CUTE/cute_suite.h"
#include "Sizov_MathTask.h"

using namespace cute;
void testCalcRectangleArea() {
    ASSERT_EQUAL(15, CalcRectangleArea(3, 5));
    ASSERT_EQUAL(0, CalcRectangleArea(0, 5));
    ASSERT_EQUAL(-10, CalcRectangleArea(-2, 5));
}

void testUserInput_Empty() {
    ASSERT_EQUAL(false, UserInput(""));
}

void testUserInput_Letter() {
    ASSERT_EQUAL(false, UserInput("a"));
}

void testUserInput_NegativeValue() {
    ASSERT_EQUAL(false, UserInput("-5"));
}

void testUserInput_DigitLetterValue() {
    ASSERT_EQUAL(false, UserInput("5a"));
}

suite createMathTestSuite() {
    suite s;
    s.push_back(CUTE(testCalcRectangleArea));
    s.push_back(CUTE(testUserInput_Empty));
    s.push_back(CUTE(testUserInput_Letter));
    s.push_back(CUTE(testUserInput_NegativeValue));
    s.push_back(CUTE(testUserInput_DigitLetterValue));
    return s;
}

int main() {
    suite s = createMathTestSuite();
    cute::ide_listener<> lis;
    cute::makeRunner(lis)(s, "Math Tests Suite");
    return 0;
}