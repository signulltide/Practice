#include <stdio.h>

int count(int n) {
    if (n==0) {
        return 0;
    } else {
        if (n<0) {n*=-1;}
        if (n % 10 == 7) {
            return 1 + count(n/10);
        } else {    
            return count(n/10);
        }
    }
}

int main() {
    printf("%d", count(707));

    return 0;
}