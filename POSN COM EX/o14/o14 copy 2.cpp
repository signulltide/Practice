#include <iostream>
using namespace std;

#define MAX 10000

struct Student {
    char name[MAX];
    int age;
    double gpa;
};

void PrintStudent(Student s) {
    printf("%s aged %d has a gpa of %.2lf.\n", s.name, s.age, s.gpa);
}

int main() {
    Student b1 = {"Alex", 14, 3.50}, b2 = {"John", 15, 3.61};
    PrintStudent(b1); PrintStudent(b2);
}