#include <iostream>
using namespace std;

int main() {
    int n, grid[24][24];
    cin >> n;
    int i, j;
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            if (i<=n/2) {
                if (j <= i || j >= n-i-1) {
                    cout << grid[i][n-j-1] << " ";
                } else {
                    cout << grid[i][j] << " ";
                }
            } else {
                if (j >= i || j <= n-i-1) {
                    cout << grid[i][n-j-1] << " ";
                } else {
                    cout << grid[i][j] << " ";
                }
            }
        }
        cout << endl;
    }
}