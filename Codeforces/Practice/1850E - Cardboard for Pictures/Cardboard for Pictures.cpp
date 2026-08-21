#include <bits/stdc++.h>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    ll n, card;
    cin >> n >> card;
    vector<ll> s(n);
    vin(s);
    ll l = 1, r = 1e9, ans = -1;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        ll curr = 0;
        ll flag = true;
        for (ll i=0; i<n; i++) {
            curr += (s[i] + (2 * mid)) * (s[i] + (2 * mid));
            if (curr > card) {
                flag = false;
                break;
            }
        }
        if (flag) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << endl;
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}