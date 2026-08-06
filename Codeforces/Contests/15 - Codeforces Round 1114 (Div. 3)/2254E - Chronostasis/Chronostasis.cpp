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
    vector<ll> b(n), a;
    vin(b);
    ll sum = 0;
    for (ll i=0; i<n; i++) {
        sum += b[i];
    }
    if (sum < 1) {
        cout << "-1\n";
        return;
    }
    ll curr = 0;
    for (ll i=0; i<n; i++) {
        auto it = lower_bound(b.begin(), b.end(), 1 - curr);
        curr += *it;
        a.push_back(curr);
        b.erase(it);
    }
    vout(a);
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}