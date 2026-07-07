#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    vin(arr);
    ll least = LLONG_MAX, most = 0, rd = 0;
    for (ll i=0; i<n; i++) {
        least = min(least, arr[i]);
        most = max(most, arr[i]);
        if (i == n-1) continue;
        rd = max(rd, arr[i] - arr[i+1]);
    }
    ll ra = most - arr[0], rb = arr[n-1] - least, rc = arr[n-1] - arr[0];
    cout << max(max(ra, rb), max(rc, rd)) << endl;
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}