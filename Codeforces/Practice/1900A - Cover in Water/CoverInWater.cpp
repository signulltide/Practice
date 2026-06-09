#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll testCount, length, currentLongestEmpty = 0, total = 0;
    string line;
    cin >> testCount;

    for (ll i=0; i<testCount; i++) {
        cin >> length >> line;
        currentLongestEmpty = 0, total = 0;
        bool infWater = false;
        for (ll j=0; j<length; j++) {
            if (line[j] == '.') {
                currentLongestEmpty++;
            } else {
                total += currentLongestEmpty;
                currentLongestEmpty = 0;
            }
            if (currentLongestEmpty >= 3) {
                infWater = true;
                break;
            }
        }
        total += currentLongestEmpty;
        if (infWater) {
            cout << "2\n";
        } else {
            cout << total << '\n';
        }
    }
}