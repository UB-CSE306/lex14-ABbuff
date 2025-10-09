#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "schemeValidator.h"
#include <criterion/criterion.h>


void runtest(char *input, int expected);

// Tests

Test(coverage, test00) {  runtest("4", -1);  }
Test(coverage, test01) {  runtest("-", -1);  }
Test(coverage, test02) {  runtest("-sd", -1);  }
Test(coverage, test03) {  runtest("+", -1);  }
Test(coverage, test04) {  runtest("x4567+", 1);  }
Test(coverage, test05) {  runtest("x4567-", 1);  }
Test(coverage, test06) {  runtest("x4567.", 1);  }
Test(coverage, test07) {  runtest("x45XSD5q", 1);  }
Test(coverage, test08) {  runtest("", -1);  }
Test(coverage, test09) {  runtest("x4", 1);  }
Test(coverage, test10) {  runtest("X46", 1);  }
Test(coverage, test12) {  runtest("x4567%", -1);  }
Test(coverage, test13) {  runtest("x/3c", -1);  }


void runtest(char *input, int expected) {
  int actual = schemeValidator(input);
  cr_assert_eq(expected,actual);
}
