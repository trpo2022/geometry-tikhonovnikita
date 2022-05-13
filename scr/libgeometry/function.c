#include "function.h"

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
PI = 3.14159265358979323846;
int Spaces(const int str_lenght, char str[], int i) {
  for (; i < str_lenght; i++) {
    if (str[i] == ' ') {
      continue;
    } else {
      break;
    }
  }
  return i;
}

float Square(float r) {
  float S;
  S = PI * r * r;
  return S;
}

float Perimetr(float r) {
  float P;
  P = 2 * PI * r;
  return P;
}