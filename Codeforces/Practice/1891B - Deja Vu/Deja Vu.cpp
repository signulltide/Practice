#include <iostream>
#include <vector>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

ll llpow(ll base, ll exp) {
    ll res = 1;
    ll b = base;
    while (exp > 0) {
        if (exp % 2 == 1) res *= b;
        b *= b;
        exp /= 2;
    }
    return res;
}

void Solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    vin(a); vin(b);
    ll mn = b[0];
    for (ll i=0; i<m; i++) {
        if (i > 0 && b[i] >= mn) continue;
        mn = b[i];
        for (ll j=0; j<n; j++) {
            if (a[j] % llpow(2, b[i]) == 0) {
                a[j] += llpow(2, b[i]-1);
            }
        }
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