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
    ll n, m;
    cin >> n >> m;

    vector<ll> exists(26);

    string s;
    for (ll i = 0; i < n; i++) {
        cin >> s;
        exists[s[0] - 'a'] = true;
    }

    bool flag = true;

    for (ll i=0; i<m; i++) {
        cin >> s;
        for (char c : s) {
            if (!exists[c - 'A']) {
                flag = false;
            }
        }
    }

    cout << (flag ? "YES" : "NO") << endl;
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}