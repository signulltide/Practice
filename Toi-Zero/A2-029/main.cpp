#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int i, j;
    for (i=0; i<n; i++) {
        for (j=0; j<=i; j++) {
            if (j == i || i == n-1 || j == 0) {
                cout << "0 ";
            } else {
                cout << "1 ";
            }
        }
        cout << endl;
    }
}