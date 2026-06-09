#include <iostream>
#include <string.h>
using namespace std;

int main() {
    string yell;
    cin >> yell;
    int i, j, uCount = 0, uHigh = 0;
    int bPos[8], bCount = 0;
    string pattern = "BUU";
    for (i=0; i<yell.length(); i++) {
        if (yell[i] == 'B' || yell[i] == 'b') {
            bPos[bCount] = i;
            bCount++;
        }
    }
    if (bCount == 0) {
        for (i=0; i<yell.length(); i++) {
            cout << pattern[i%3];
        }
    } else {
        for (i=0; i<bCount; i++) {
            if (yell[bPos[i]+1] == 'U' || yell[bPos[i]+1] == 'u') {
                for (j=bPos[i]+1; j<8; j++) {
                    if (yell[j] == 'U' || yell[j] == 'u') {
                        uCount++;
                    } else {
                        break;
                    }
                }
                if (uCount > uHigh) {
                    uHigh = uCount;
                }
                uCount = 0;
            }
        }
        if (uHigh == 0) {
            for (j=bPos[0]+1; j<8; j++) {
                yell[j] = 'U';
            }
            cout << yell;
        } else {
            cout << "Yes " << uHigh;
        }
    }
}