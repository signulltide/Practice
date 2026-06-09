#include <iostream>
using namespace std;

int main() {
    int n, i, j, sizeX;
    cin >> n;
    if (n%2==0) {
        sizeX = n - 1;
    } else {
        sizeX = n;
    }
    for (i=0; i<n; i++) {
        for (j=0; j<sizeX; j++) {
            if (i < n/2) {
                if (j == sizeX/2 - i || j == sizeX/2 + i) {
                    cout << "*";
                } else {
                    cout << "-";
                }
            } else {
                if (j == i - n/2 || j == sizeX - 1 - (i - (n/2))) {
                    cout << "*";
                } else {
                    cout << "-";
                }
            }
        }
        cout << endl;
    }
}