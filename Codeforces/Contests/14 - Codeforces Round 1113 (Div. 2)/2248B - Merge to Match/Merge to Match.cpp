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
    vector<ll> a(n), b(m);
    vin(a); vin(b);

    if (n < 2 * m) {
        cout << "NO\n";
        return;
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    for (ll i=0; i<m; i++) {
        if (a[i] >= b[i] || a[n-m+i] <= b[i]) {
            cout << "NO\n";
            return;
        }
    }
    
    cout << "YES\n";
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}