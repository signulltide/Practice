#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int a, b, c;
    scanf("%lf %lf", &a, &b);
    c = a*a + b*b;
    printf("%.6lf", sqrt(c));
}