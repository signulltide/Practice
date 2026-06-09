#include <iostream>
using namespace std;

const int MAX = 100000;

int CustomABS(int an) {
    if (an < 0) {
        return an * -1;
    } else {
        return an;
    }
}

#pragma optimize( "O3", on )
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int i, j, n;
    int x[MAX], y[MAX];
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }
    int biggest = 0;
    for (i=0; i<n; ++i) {
        for (j=i+1; j<n; ++j) {
            if (CustomABS(x[i] - x[j]) == CustomABS(y[i] - y[j]) && CustomABS(x[i] - x[j]) > biggest) {
                biggest = CustomABS(x[i] - x[j]);
            }
        }
    }
    printf("%d", biggest);
    return 0;
}