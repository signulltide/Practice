#include <bits/stdc++.h>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

ll n, x;
vector<ll> coral;

bool Check(ll h) {
    ll water = 0;
    for (ll c : coral) {
        if (c >= h) continue;
        water += h - c;
    }
    return (water <= x);
}

void Solve() {
    cin >> n >> x;
    coral.resize(n);
    vin(coral);
    sort(coral.begin(), coral.end());

    ll l = 1, r = 1e12, ans = -1;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (Check(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << endl;
    coral.clear();
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}