#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll testCount;
    cin >> testCount;

    while (testCount--) {

        ll length, operations;
        vector<ll> arr;
        cin >> length >> operations;
        arr.resize(length);

        for (ll i=0; i<length; i++) {
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());

        if (operations == 1) {
            ll minDiff = arr[0];
            for (ll i=1; i<length; i++) {
                minDiff = min(minDiff, arr[i] - arr[i-1]);
            }
            cout << minDiff;
        } else if (operations == 2) {
            ll best = arr[0];
            for (ll i=1; i<length; i++) {
                best = min(best, arr[i] - arr[i-1]);
            }
            for (ll i=0; i<length; i++) {
                for (ll j=i+1; j<length; j++) {
                    ll diff = arr[j] - arr[i];
                    // cout << arr[j] << " - " << arr[i] << " = " << diff << '\n';
                    auto closest = lower_bound(arr.begin(), arr.end(), diff);
                    // cout << "CLOSEST: " << *closest << '\n';
                    // cout << "CURRENT: " << *closest - diff << '\n';
                    if (closest != arr.end()) {
                        best = min(best, *closest - diff);
                    }
                    if (closest != arr.begin()) {
                        best = min(best, diff - *(closest-1));
                    }
                }
            }
            cout << best;
        } else {
            cout << "0";
        }

        cout << '\n';
    }
}