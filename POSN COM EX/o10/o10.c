#include <stdio.h>

void counter (void) {
    static int calls = 0; // keeps value across calls
    calls++;
    printf("This function was called %d times\n", calls);
}

int main() {
    counter (); // prints 1
    counter (); // prints 2
    counter (); // prints 3

    return 0;
}