#include <stdio.h>

int main() {
    int n, i;
    double num[100], weight[100], total = 0, tW = 0;
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%lf %lf", &num[i], &weight[i]);
    }
    for (i=0; i<n; i++) {
        total += num[i] * weight[i];
        tW += weight[i];
    }
    printf("Avg = %.2lf", total / tW);
}