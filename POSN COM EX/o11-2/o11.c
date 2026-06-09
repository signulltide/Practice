#include <stdio.h>

void swap_val(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int main() {
    int a = 3, b = 7;

    swap(&a, &b);

    printf("%d %d", a, b);

    return 0;
}