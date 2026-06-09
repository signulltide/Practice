#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

void Solve() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (ll i=0; i<n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(), greater<ll>());
    for (ll i=2; i<n; i++) {
        if (arr[i] != arr[i-2] % arr[i-1]) {
            cout << "-1\n";
            return;
        }
    }
    cout << arr[0] << " " << arr[1] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll testCount;
    cin >> testCount;

    while (testCount--) {
        Solve();
    }

    return 0;
}