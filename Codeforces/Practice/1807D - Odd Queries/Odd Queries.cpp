#include <iostream>
#include <vector>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    ll n, q;
    cin >> n >> q;
    vector<ll> pref(n + 1, 0);
    for (ll i=1; i<=n; i++) {
        ll temp;
        cin >> temp;
        pref[i] = pref[i - 1] + temp;
    }
    
    while (q--) {
        ll l, r, k;
        cin >> l >> r >> k;
        ll newSum = pref[n] - (pref[r] - pref[l - 1]) + (r - l + 1) * k;
        
        if (newSum % 2 != 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}