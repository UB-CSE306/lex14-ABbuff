#include "schemeValidator.h"

int schemeValidator(char scheme[]) {
  int result = 1;
  if (isAlpha(scheme[0])) { 
    for (int i=1; scheme[i] != '\0'; i++) {
      if (!isAlpha(scheme[i])  &&  !isDigit(scheme[i])  &&  !isSpecial(scheme[i])) result = -1;
    }
  }else{
    result = -1;
  }
  return result;
}

bool isAlpha(char c) {
  bool isLetter;
  isLetter = ('A' <= c && c <= 'Z')  ||  ('a' <= c && c <= 'z');

  return isLetter;
}

bool isSpecial(char c) {
  bool result = false;
  if (c == '+') result = true;
  else if (c == '-') result = true;
  else if (c == '.') result = true;
  return result;
}

bool isDigit(char c) {
  int charNum = (int)c - 48;
  return 0 <= charNum  &&  charNum <= 9;
}


