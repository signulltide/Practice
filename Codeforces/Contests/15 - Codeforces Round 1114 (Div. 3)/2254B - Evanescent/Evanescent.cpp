#include <iostream>
#include <string>
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
    ll res = 1;
    char last = s[0];
    for (ll i=1; i<n; i++) {
        if (s[i] != last) {
            last = s[i];
            res++;
        }
    }
    for (ll i=1; i<n-1; i++) {
        if (s[i-1] == s[i+1] && s[i-1] != s[i]) {
            cout << res - 2 << endl;
            return;
        }
    }
    for (ll i=1; i<n-1; i++) {
        if (s[i-1] != s[i] && s[i] != s[i+1]) {
            cout << res - 1 << endl;
            return;
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