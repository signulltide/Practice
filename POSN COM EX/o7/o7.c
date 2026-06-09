#include <stdio.h>

int main() {
    char c = getchar();
    if (isdigit(c)) {
        printf("digit");
    } else if (isupper(c)) {
        printf("upper");
    } else if (islower(c)) {
        printf("lower");
    }
}