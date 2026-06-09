#include <iostream>
using namespace std;

int main() {
    int row, col;
    char grid1[500][500], grid2[500][500], grid3[500][500];
    cin >> row >> col;

    int i, j;
    
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            cin >> grid1[i][j];
        }
    }

    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            cin >> grid2[i][j];
        }
    }

    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if (grid1[i][j] == '+' && grid2[i][j] == 'x') {
                grid3[i][j] = '*';
            } else if (grid1[i][j] == '+') {
                grid3[i][j] = '+';
            } else if (grid2[i][j] == 'x') {
                grid3[i][j] = 'x';
            } else {
                grid3[i][j] = '-';
            }
        }
    }

    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            cout << grid3[i][j];
        }
        cout << endl;
    }

    return 0;
}