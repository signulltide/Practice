#include <iostream>
using namespace std;

int main() {
    int table[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };

    int i, j, sum = 0;
    
    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }

    for (i=0; i<3; i++) {
        sum += table[0][i];
    }
    cout << sum;

    return 0;
}