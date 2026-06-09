#include <iostream>
using namespace std;

#define MAX 10000

struct Student {
    char name[MAX];
    int age;
    double gpa;
};

int main() {
    struct Student b1 = {"Alex", 14, 3.50}, b2 = {"John", 15, 3.61};
    printf("%s aged %d has a gpa of %.2lf.\n", b1.name, b1.age, b1.gpa);
    printf("%s aged %d has a gpa of %.2lf.", b2.name, b2.age, b2.gpa);
}