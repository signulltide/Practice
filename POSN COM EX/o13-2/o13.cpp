#include <iostream>
using namespace std;

int main() {
    int table[2][3];

    int i, j;
    
    for (i=0; i<3; i++) {
        for (j=0; j<2; j++) {
            cin >> table[i][j];
        }   
    }

    for (i=0; i<3; i++) {
        cout << table[i][0] + table[i][1];
    }

    return 0;
}