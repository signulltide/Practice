#include <stdio.h>

int main() {
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    if (a+b>c && a+c>b && b+c>a) {
        if (a != b && b != c && c != a) {
            printf("scalene");
        } else if (a == b && b == c && a == c) {
            printf("equilateral");
        } else {
            printf("isosceles");
        }
    } else {
        printf("invalid");
    }
}