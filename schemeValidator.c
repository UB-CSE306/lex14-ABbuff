#include "schemeValidator.h"

int schemeValidator(char scheme[]) {
  int result = -1;
  if (isAlpha(scheme[1])) {
    result = 0; 
    int i=2;
    while (scheme[i] != '\0') {
      if (!isAlpha(scheme[i])) result = -1;
      else if (!isDigit(scheme[i])) result = -1;
      else if (!isSpecial(scheme[i])) result = -1;
      i++;
    }
  }
  if ('A' < scheme[1] && scheme[1] < 'Z') {
    result = 1;
  }
  return result;
}

bool isAlpha(char c) {
  return 'a' < c && c < 'z';
}

bool isSpecial(char c) {
  bool result = false;
  if (c == '+') result = true;
  else if (c == '-') result = true;
  else result = true;
  return result;
}

bool isDigit(char c) {
  return 0 < c-48 && c-48 < 9;
}


