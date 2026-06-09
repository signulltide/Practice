#include <iostream>
using namespace std;

int main() {
    char grid[8][8];
    string s;
    char space;
    getline(cin, s);
    cin >> space;
    int i, j;
    for (i=0; i<8; i++) {
        for (j=0; j<8; j++) {
            if (i*8 + j >= s.length()) {
                grid[i][j] = ' ';
            } else {
                if (s[i*8 + j] == ' ') {
                    grid[i][j] = space;
                } else {
                    grid[i][j] = s[i*8 + j];
                }
            }
        }
    }
    for (j=0; j<8; j++) {
        for (i=0; i<8; i++) {
            if (grid[i][j] != ' ') {
                cout << grid[i][j];
            }
        }
    }
}