#include <ctype.h>
#include <libgeometry/function.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    const int str_lenght = 50;
    char str[str_lenght];
    fgets(str, str_lenght, stdin);
    int i = 0;
    i = Space(str_lenght, str, i);
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
    i = Space(str_lenght, str, i);
    if (i >= str_lenght) {
        printf("\nError:Volume exceeded\n");
        return 1;
    }
    float x, y, r;
    if (3 == sscanf(str + i, "(%f %f, %f)\n", &x, &y, &r)) {
        printf("%s\n", circle);
        printf(" x = %f y = %f R = %f\n\n", x, y, r);
        printf("P=%f", Perimetr(r));
        printf("  S=%f\n", Square(r));
        printf("Correct output:(%s %.2f %.2f,%.2f)\n\n Perimetr=%f \n area=%f",
               circle,
               x,
               y,
               r,
               Perimetr(r),
               Square(r));

    } else {
        printf("\nError:Incorrect input of coordinates\n");
    }
}