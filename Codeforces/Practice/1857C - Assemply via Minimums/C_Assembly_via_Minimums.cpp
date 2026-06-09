#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll testCount;
    cin >> testCount;

    while (testCount--) {
        ll aLength;
        cin >> aLength;
        ll bLength = aLength*(aLength-1)/2;
        vector<ll> arr(bLength), res(aLength);
        for (ll i=0; i<bLength; i++) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        for (ll i=0; i<bLength; i+=--aLength) {
            cout << arr[i] << " ";
        }
        cout << "1000000000\n";
    }
}