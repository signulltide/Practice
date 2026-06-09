#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int length, count, i, j, diff = 0;
    string prev, curr, b = "X";

    cin >> length >> count;

    for (i=0; i<count; i++) {
        cin >> curr;
        if (i == 0) {prev = curr;}
        for (j=0; j<length; j++) {
            if (curr[j] != prev[j]) {
                diff++;
            }
        }
        if (diff > 2 && b == "X") {
            b = prev;
        }
        diff = 0;
        prev = curr;
    }

    if (b == "X") {b = curr;}

    cout << b;

}