#include <iostream>
using namespace std;

int main() {
    int ax, ay, bx, by, a[50][50], b[50][50], i, j, k, r[50][50];
    cin >> ax >> ay >> bx >> by;
    if (ay != bx) {
        cout << "not multiply";
        return 0;
    }
    for (i=0; i<ay; i++) {
        for (j=0; j<ax; j++) {
            cin >> a[i][j];
        }
    }
    for (i=0; i<by; i++) {
        for (j=0; j<bx; j++) {
            cin >> b[i][j];
        }
    }
    for (i=0; i<ay; i++) {
        for (j=0; j<bx; j++) {
            r[i][j] = 0;
            for (k=0; k<ax; k++) {
                r[i][j] += a[i][k] + b[k][j];
            }
        }
    }
    for (i=0; i<ay; i++) {
        for (j=0; j<bx; j++) {
            cout << r[i][j] << " ";
        }
        cout << endl;
    }
}
