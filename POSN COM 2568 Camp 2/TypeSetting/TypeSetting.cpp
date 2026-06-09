#include <iostream>
#include <vector>
using namespace std;

#define ll long long int

ll wordCount, lineCount;
vector<ll> length;

bool Check(ll limit) {
    //cout << "LIMIT " << limit << endl;
    ll currLine = 1, currLineLen = 0;
    for (ll len : length) {
        //cout << "INS " << len << endl;
        if (currLineLen + len > limit) {
            currLineLen = 0;
            currLine++;
            if (currLine > lineCount) return false;
        }
        currLineLen += len;
    }
    return true;
}

int main() {
    ll lowBound = 0, upBound = 0, mid;
    cin >> wordCount >> lineCount;
    length.resize(wordCount);
    for (ll i=0; i<wordCount; i++) {
        cin >> length[i];
        lowBound = max(lowBound, length[i]);
        upBound += length[i];
    }
    //cout << "LowBound = " << lowBound << endl;
    //cout << "UpBound = " << upBound << endl;
    while (lowBound < upBound) {
        mid = lowBound + (upBound - lowBound) / 2;
        if (Check(mid)) {
            //cout << "PASS\n";
            upBound = mid;
        } else {
            //cout << "FAIL\n";
            lowBound = mid + 1;
        }
    }
    cout << lowBound;
}