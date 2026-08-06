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
    ll n, m;
    cin >> n >> m;
    vector<ll> stab(n);
    vector<vector<ll>> grid(n, vector<ll>(m));
    vin(stab);
    ll least_stab = LLONG_MAX;
    for (ll i=0; i<n; i++) {
        for (ll j=0; j<m; j++) {
            cin >> grid[i][j];
        }
    }
    vector<ll> cands;
    ll least = m;
    for (ll i=n-1; i>=0; i--) {
        for (ll j=0; j<m; j++) {
            cands.push_back(grid[i][j]);
        }
        sort(cands.rbegin(), cands.rend());
        cands.resize(m);
        ll curr = 0;
        for (ll j=0; j<m; j++) {
            curr += cands[j];
            if (curr >= stab[i]) {
                least = min(least, j + 1);
                break;
            }
        }
    }
    cout << least << endl;
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}