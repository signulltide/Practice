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
    ll n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<ll> a(x), b(y);
    vin(a); vin(b);
    
    ll pa = 0, pb = 0;
    vector<ll> a_only, b_only, both;
    
    while (pa < x && pb < y) {
        if (a[pa] < b[pb]) {
            a_only.push_back(a[pa++]);
        } else if (b[pb] < a[pa]) {
            b_only.push_back(b[pb++]);
        } else {
            both.push_back(a[pa]);
            pa++; pb++;
        }
    }
    while (pa < x) a_only.push_back(a[pa++]);
    while (pb < y) b_only.push_back(b[pb++]);

    sort(a_only.rbegin(), a_only.rend());
    sort(b_only.rbegin(), b_only.rend());
    
    vector<ll> combined;
    
    for (ll i = 0; i < min((ll)a_only.size(), n); i++) {
        combined.push_back(a_only[i]);
    }
    for (ll i = 0; i < min((ll)b_only.size(), m); i++) {
        combined.push_back(b_only[i]);
    }
    for (ll bo : both) {
        combined.push_back(bo);
    }
    
    ll c_size = combined.size();
    sort(combined.rbegin(), combined.rend());
    
    ll sum = 0;
    for (ll i = 0; i < min(c_size, n + m - 1); i++) {
        sum += combined[i];
    }
    cout << sum << endl;
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}