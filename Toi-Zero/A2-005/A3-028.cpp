#include <iostream>
using namespace std;

const int MAX = 10000;

int main() {
    int field[MAX][MAX];
    int x, y, mineCount, mineX[MAX], mineY[MAX], i, j, k, a, b, surroundingCount;
    cin >> y >> x >> mineCount;
    for (i=0; i<mineCount; i++) {
        cin >> mineY[i] >> mineX[i];
    }
    bool mineFlag;
    for (i=0; i<y; i++) {
        for (j=0; j<x; j++) {
            mineFlag = false;
            for (k=0; k<mineCount; k++) {
                if (i == mineY[k] && j == mineX[k]) {
                    cout << "x";
                    mineFlag = true;
                    break;
                }
            }
            if (!mineFlag) {
                surroundingCount = 0;
                for (a=i-1; a<=i+1; a++) {
                    for (b=j-1; b<=j+1; b++) {
                        for (k=0; k<mineCount; k++) {
                            if (a == mineY[k] && b == mineX[k]) {
                                surroundingCount++;
                            }
                        }
                    }
                }
                cout << surroundingCount;
            }
            cout << " ";
        }
        cout << "\n";
    }
    return 0;
}