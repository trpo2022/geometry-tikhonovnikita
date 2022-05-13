#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M_PI ;
#include "libgeometry/function.h"
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
int main() {
  const int str_lenght = 50;
  char str[str_lenght];
  fgets(str, str_lenght, stdin);
  int i = 0;
  i = Spaces(str_lenght, str, i);
  if (i >= str_lenght) {
    printf("\nError:Volume exceeded\n");
    return 1;
  }
  const char circle[] = "circle";
  for (int g = 0; g < 6; g++, i++) {
    if (tolower(str[i]) == circle[g]) {
      continue;
    } else {
      printf("\nError:Wrong text input\n");
      return 2;
    }
  }
  i = Spaces(str_lenght, str, i);
  if (i >= str_lenght) {
    printf("\nError:Volume exceeded\n");
    return 1;
  }
  float x, y, r;
  if (3 == sscanf(str + i, "(%f %f, %f)\n", &x, &y, &r)) {
    printf("%s\n", circle);
    printf(" x = %f y = %f R = %f\n\n", x, y, r);
    printf("P=%7.3f", Perimetr(r));
    printf("S=%7.3f", Squre(r));
    printf("Correct output:(%s %.2f %.2f,%.2f)\n perimetr=%7.3f\n area=%7.3f\n",
           circle, x, y, r, Perimetr(r), Squre(r));
  } else {
    printf("\nError:Incorrect input of coordinates\n");
  }
}