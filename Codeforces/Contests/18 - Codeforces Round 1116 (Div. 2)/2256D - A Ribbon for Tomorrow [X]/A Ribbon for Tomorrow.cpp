#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    ll n;
    string s;
    cin >> n >> s;

    vector<ll> prefix(n, 0);
    for (ll i=1; i<n; i++) {
        if (s[i] != s[i-1]) {
            prefix[i] = prefix[i-1] + 1;
        } else {
            prefix[i] = prefix[i-1];
        }
    }

    ll res = 1;
    for (ll len=3; len<=n; len++) {
        for (ll i=0; i+len<n; i++) {
            ll l = i, r = i + len;
            if (s[l] == s[r]) {
                ll d = prefix[r] - prefix[l];
                if (d%2 == len%2) {
                    res++;
                }
            }
        }
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