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
    ll n, res = 0;
    cin >> n;
    vector<ll> arr(n), sorted(n);
    vin(arr);
    sorted = arr;
    sort(arr.begin(), arr.end());
    if (sorted != arr) {
        cout << "0\n";
        return;
    }
    ll least = LLONG_MAX;
    for (ll i=0; i<n-1; i++) {
        least = min(least, (arr[i+1] - arr[i]) / 2);
    }
    cout << least + 1 << endl;
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}