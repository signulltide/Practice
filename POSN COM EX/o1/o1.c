#include <stdio.h>

int main() {
    char name[100];
    int age;
    double weight;

    printf("Enter your name: ");
    scanf("%99s", name);
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("Enter your weight: ");
    scanf(" %lf", &weight);

    printf("\nHi, %s\nYou are %d years old, and weights %.6lf kilograms.", name, age, weight);
}