#include <iostream>
using namespace std;

int main() {
    string majorString;
    string minorString;
    getline(cin, minorString);
    getline(cin, majorString);
    int majorLength = majorString.length();
    int minorLength = minorString.length();
    int i, j, matchFlag = 1, foundFlag = 0, spacesCount = 0;
    for (i=0; i<=majorLength-minorLength; i++) {
        if (majorString[i] == ' ') {
            spacesCount++;
        }
        for (j=0; j<minorLength; j++) {
            if (majorString[i+j] != minorString[j]) {
                matchFlag = 0;
                break;
            }
        }
        if (matchFlag == 1) {
            foundFlag = 1;
            break;
        }
        matchFlag = 1;
    }
    if (foundFlag == 1) {
        cout << spacesCount;
    } else {
        cout << -1;
    }
}
