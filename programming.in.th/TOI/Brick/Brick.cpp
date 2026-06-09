#include <iostream>
#include <string>
using namespace std;

#define MAX 20

int main() {
    char grid[MAX][MAX];
    int i, j, k, y, x;
    cin >> y >> x;
    
    for (i=0; i<y; i++) {
        for (j=0; j<x; j++) {
            cin >> grid[i][j];
        }
    }

    cin.ignore();

    string bricksChar;
    int bricks[MAX], brickCount = x-1, currentDigit = 1, currentNum = 0;
    getline(cin, bricksChar);

    for (i=bricksChar.length()-1; i>=0; i--) {
        if (bricksChar[i] != ' ') {
            currentNum += (bricksChar[i] - '0') * currentDigit;
            currentDigit *= 10;
        } else {
            bricks[brickCount] = currentNum;
            currentNum = 0; currentDigit = 1;
            brickCount--;
        }
    }
    bricks[0] = currentNum;

    bool OFlag = false;

    for (j=0; j<x; j++) {
        for (i=0; i<y; i++) {
            if (grid[i][j] == 'O') {
                OFlag = true;
                for (k=i-1; k>=i-bricks[j]; k--) {
                    if (k < 0) {continue;}
                    grid[k][j] = '#';
                }
                break;
            }
        }
        if (OFlag == false) {
            for (k=y-1; k>=y-bricks[j]; k--) {
                if (k < 0) {continue;}
                grid[k][j] = '#';
            }
        }
        OFlag = false;
    }

    for (i=0; i<y; i++) {
        for (j=0; j<x; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}