#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    ll n, m, res = 0, leastSec = LLONG_MAX, leastMoved = LLONG_MAX;
    cin >> n;
    vector<vector<ll>> arrs(n);
    for (ll i=0; i<n; i++) {
        cin >> m;
        arrs[i].resize(m);
        vin(arrs[i]);
        sort(arrs[i].begin(), arrs[i].end());
        leastSec = min(leastSec, arrs[i][1]);
        leastMoved = min(leastMoved, arrs[i][0]);
        res += arrs[i][1];
    }
    res -= leastSec;
    res += leastMoved;
    cout << res << endl;
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) {
        Solve();
    }

    return 0;
}