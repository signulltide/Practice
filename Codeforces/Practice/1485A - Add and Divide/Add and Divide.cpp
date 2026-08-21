#include <iostream>
#include <algorithm>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    ll a, b;
    cin >> a >> b;
    ll res = LLONG_MAX;
    for (ll i=0; i<=30; i++) {
        ll ta = a;
        ll tb = b + i;
        if (tb == 1) continue;
        ll ops = i;
        while (ta > 0) {
            ta /= tb;
            ops++;
        }
        res = min(res, ops);
    }
    cout << res << endl;
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}