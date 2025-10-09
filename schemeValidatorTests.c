#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "schemeValidator.h"
#include <criterion/criterion.h>


void runtest(char *input, int expected, int testNum);
void runIsSpecialTest(char input, bool expected);
void runAlphaTest(char input, bool expected);
void runDigitTest(char input, bool expected);

// Tests

Test(coverage, test00) {  runtest("4", -1, 0);  }
Test(coverage, test01) {  runtest("-", -1, 1);  }
Test(coverage, test02) {  runtest("-sd", -1, 2);  }
Test(coverage, test03) {  runtest("+", -1, 3);  }
Test(coverage, test04) {  runtest("x4567+", 1, 4);  }
Test(coverage, test05) {  runtest("x4567-", 1, 5);  }
Test(coverage, test06) {  runtest("x4567.", 1, 6);  }
Test(coverage, test07) {  runtest("x45XSD5q", 1, 7);  }
Test(coverage, test08) {  runtest("", -1, 8);  }
Test(coverage, test09) {  runtest("x4", 1, 9);  }
Test(coverage, test10) {  runtest("X46", 1, 10);  }
Test(coverage, test11) {  runtest("x4567%", -1, 11);  }
Test(coverage, test12) {  runtest("x/3c", -1, 12);  }

Test(helpers, test00) {  runIsSpecialTest('+', true);  }
Test(helpers, test01) {  runIsSpecialTest('-', true);  }
Test(helpers, test02) {  runIsSpecialTest('.', true);  }
Test(helpers, test03) {  runIsSpecialTest('%', false);  }
Test(helpers, test04) {  runIsSpecialTest('*', false);  }
Test(helpers, test05) {  runIsSpecialTest('a', false);  }
Test(helpers, test06) {  runIsSpecialTest('4', false);  }

Test(helpers, test07) {  runAlphaTest('a', true);  }
Test(helpers, test08) {  runAlphaTest('Z', true);  }
Test(helpers, test09) {  runAlphaTest('+', false);  }
Test(helpers, test10) {  runAlphaTest('0', false);  }
Test(helpers, test11) {  runAlphaTest('9', false);  }

Test(helpers, test12) {  runDigitTest('0', true);  }
Test(helpers, test13) {  runDigitTest('9', true);  }
Test(helpers, test14) {  runDigitTest('a', false);  }
Test(helpers, test15) {  runDigitTest('Z', false);  }
Test(helpers, test16) {  runDigitTest('+', false);  }


void runtest(char *input, int expected, int testNum) {
  int actual = schemeValidator(input);
  cr_assert_eq(expected,actual, "Test %d: schemeValidator(%s) returned %d   but expected %d", testNum, input, actual, expected);
}


void runIsSpecialTest(char input, bool expected) {
  bool actual = isSpecial(input);
  cr_assert_eq(expected,actual, "isSpecial(%c) returned %d   but expected %d", input, (int)actual, (int)expected);
}

void runAlphaTest(char input, bool expected) {
  bool actual = isAlpha(input);
  cr_assert_eq(expected,actual, "isAlpha(%c) returned %d   but expected %d", input, (int)actual, (int)expected);
}

void runDigitTest(char input, bool expected) {
  bool actual = isDigit(input);
  cr_assert_eq(expected,actual, "isDigit(%c) returned %d   but expected %d", input, (int)actual, (int)expected);
}
