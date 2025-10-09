#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "schemeValidator.h"
#include <criterion/criterion.h>


void runtest(char *input, int expected, int testNum);

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

Test(helpers, test00) {  runIsSpecialTest('+', 1);  }
Test(helpers, test01) {  runIsSpecialTest('-', 1);  }
Test(helpers, test02) {  runIsSpecialTest('.', 1);  }
Test(helpers, test03) {  runIsSpecialTest("%", -1);  }
Test(helpers, test04) {  runIsSpecialTest("*", -1);  }
Test(helpers, test05) {  runIsSpecialTest('a', -1);  }
Test(helpers, test06) {  runIsSpecialTest('4', -1);  }

Test(helpers, test07) {  runAlphaTest('0', 1);  }
Test(helpers, test08) {  runAlphaTest('9', 1);  }
Test(helpers, test09) {  runAlphaTest('+', -1);  }
Test(helpers, test10) {  runAlphaTest('a', -1);  }
Test(helpers, test10) {  runAlphaTest('A', -1);  }


void runtest(char *input, int expected, int testNum) {
  int actual = schemeValidator(input);
  cr_assert_eq(expected,actual, "Test %d: schemeValidator(%s) returned %d   but expected %d", testNum, input, actual, expected);
}


void runIsSpecialTest(char input, bool expected, int testNum) {
  bool actual = isSpecial(input);
  cr_assert_eq(expected,actual, "Test %d isSpecial(%s) returned %d   but expected %d", testNum, input, actual, expected);
}

void runAlphaTest(char input, bool expected, int testNum) {
  bool actual = isAlpha(input);
  cr_assert_eq(expected,actual, "Test %d: isAlpha(%s) returned %d   but expected %d", testNum, input, actual, expected);
}

void runDigittest(char input, bool expected, int testNum) {
  bool actual = isDigit(input);
  cr_assert_eq(expected,actual, "Test %d: isDigit(%s) returned %d   but expected %d", testNum, input, actual, expected);
}
