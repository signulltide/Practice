#include <iostream>
using namespace std;

int main() {
    int grid[3][7], i, j, k;
    for (i=0; i<3; i++) {
        for (j=0; j<7; j++) {
            cin >> grid[i][j];
        }
    }
    int res[5] = {0, 0, 0, 0, 0};
    for (i=0; i<5; i++) {
        for (j=0; j<3; j++) {
            for (k=0; k<3; k++) {
                res[i] += grid[j][k+i];
            }
        }
    }
    for (i=0; i<5; i++) {
        cout << res[i] << " ";
    }
}