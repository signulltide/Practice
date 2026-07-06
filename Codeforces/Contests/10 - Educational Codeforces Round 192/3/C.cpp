#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    map<ll, ll> freq_map;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        freq_map[a[i]]++;
    }

    vector<ll> f;
    for (auto &[num, count] : freq_map) {
        f.push_back(count);
    }
    sort(f.begin(), f.end());

    ll res = 0;
    ll m = f.size();
    ll count = n;

    for (ll i=0; i<m; i++) {
        if (i > 0 && f[i] == f[i - 1]) {
            count -= f[i];
            continue;
        }
        ll streak = m - i;
        if ((k - count) % streak == 0) {
            ll X = (k - count) / streak;
            if (f[i] + X >= 1) {
                res++;
            }
        }
        count -= f[i]; 
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