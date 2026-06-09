#include <iostream>
using namespace std;

#define MAX 100

struct Date {
    int day;
    int month;
    int year;
};

struct Student {
    char name[MAX];
    int age;
    double gpa;
    Date birthday;
};

void PrintStudent(Student s) {
    printf("%s aged %d has a gpa of %.2lf. Their bithday is on the %d of %d, %d", s.name, s.age, s.gpa, s.birthday.day, s.birthday.month, s.birthday.year);
}

void UpdateGPA(Student s, double ngpa) {
    s.gpa = ngpa;
}

int main() {
    Student students[MAX];
    int i, n;
    cin >> n;
    int highestGPA = 0;
    for (i=0; i<n; i++) {
        cin >> students[i].name >> students[i].age >> students[i].gpa;
        if (students[i].gpa > students[highestGPA].gpa) {
            highestGPA = i;
        }
    }
    UpdateGPA(students[3], 3.40);
    cout << students[highestGPA].name << "\n";
    for (i=0; i<n; i++) {
        PrintStudent(students[i]);
    }
}