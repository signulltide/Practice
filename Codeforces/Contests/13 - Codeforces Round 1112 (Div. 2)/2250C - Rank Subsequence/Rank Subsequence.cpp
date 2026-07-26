#include <iostream>
#include <vector>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    ll n;
    cin >> n;
    vector<vector<ll>> cons(n, vector<ll>(4));
    for (ll i=0; i<n; i++) {
        for (ll j=0; j<4; j++) {
            cin >> cons[i][j];
        }
    }
    for (ll m=n; m>=0; m--) {
        ll curr = 0, last = 0;

        for (ll j=1; j<=m; j++) {
            ll l = j, r = m - j + 1;
            bool found = false;
            for (ll i=last; i<n; i++) {
                if ((l < cons[i][0] || l > cons[i][1]) && (r < cons[i][2] || r > cons[i][3])) {
                    curr++;
                    last = i + 1;
                    found = true;
                    break;
                }
            }
            if (!found) break; 
        }

        if (curr == m) {
            cout << curr << endl;
            return;
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