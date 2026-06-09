#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll testCount, stationCount, length, mostDiff, prev, curr;
    vector<ll> res;
    cin >> testCount;

    for (ll i=0; i<testCount; i++) {
        mostDiff = 0, prev = 0, curr = 0;
        cin >> stationCount >> length;
        for (ll j=0; j<stationCount; j++) {
            cin >> curr;
            mostDiff = max(mostDiff, curr - prev);
            prev = curr;
        }
        mostDiff = max(mostDiff, (length - curr) * 2);
        res.push_back(mostDiff);
    }
    for (ll r : res) {
        cout << r << '\n';
    }
}