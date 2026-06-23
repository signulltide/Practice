#include <iostream>
#include <vector>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    ll n, range;
    cin >> n >> range;
    vector<ll> food(n);
    vin(food);
    ll l = food[0] - range, r = food[0] + range;
    ll breaks = 0;
    for (ll i=1; i<n; i++) {
        ll cl = food[i] - range, cr = food[i] + range;
        if (cl > r || cr < l) {
            breaks++;
            l = cl; r = cr;
        } else {
            l = max(l, cl);
            r = min(r, cr);
        }
    }
    cout << breaks << endl;
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}