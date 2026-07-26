#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
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
    sort(arr.begin(), arr.end());
    ll m1 = arr[n/2], m2 = arr[n/2 + 1];
    ll res1 = 0, res2 = 0;
    for (ll a : arr) {
        res1 += abs(a - m1);
        res2 += abs(a - m2);
    }
    cout << min(res1, res2);
}

int main() {
    fastIO;

    Solve();

    return 0;
}