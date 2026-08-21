#include <iostream>
#include <vector>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> va(n), vb(m);
    ll a = 0, b = 0;
    vin(va); vin(vb);
    for (ll i=0; i<n; i++) {
        a += va[i];
        if (i+1 < n) {
            a -= va[i+1] - 1;
        }
    }
    for (ll i=0; i<m; i++) {
        b += vb[i];
        if (i+1 < m) {
            b -= vb[i+1] - 1;
        }
    }
    //cout << a << " " << b << endl;
    cout << (a >= b ? "1" : "2") << endl;
    //cout << endl;
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}