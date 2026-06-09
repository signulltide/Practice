#include <stdio.h>

int counter = 0;

void wrong_increment(void) {
    int counter = 0;
    counter++;
}

void correct_increment(void) {
    counter++;
}

int main() {
    wrong_increment();
    printf("Wrong = %d\n", counter);
    correct_increment();
    printf("Correct = %d", counter);
    return 0;
}