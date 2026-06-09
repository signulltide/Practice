#include <iostream>
using namespace std;

int main() {
    string majorString;
    string minorString;
    getline(cin, majorString);
    getline(cin, minorString);
    int majorLength = majorString.length();
    int minorLength = minorString.length();
    int i, j, matchFlag = 1, foundCount = 0;
    for (i=0; i<=majorLength-minorLength; i++) {
        for (j=0; j<minorLength; j++) {
            if (majorString[i+j] != minorString[j]) {
                matchFlag = 0;
                break;
            }
        }
        if (matchFlag == 1) {
            foundCount++;
        }
        matchFlag = 1;
    }
    cout << foundCount;
}
