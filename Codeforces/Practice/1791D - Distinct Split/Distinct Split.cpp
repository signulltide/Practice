#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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
    vector<ll> pre(n), suf(n);
    vector<bool> ip(26), is(26);
    ll cp = 0, cs = 0;
    for (ll i=0; i<n; i++) {
        if (!ip[s[i] - 'a']) {
            ip[s[i] - 'a'] = true;
            cp++;
        }
        pre[i] = cp;
        if (!is[s[n-i-1] - 'a']) {
            is[s[n-i-1] - 'a'] = true;
            cs++;
        }
        suf[n-i-1] = cs;
    }
    ll most = 0;
    for (ll i=0; i<n-1; i++) {
        most = max(most, pre[i] + suf[i+1]);
    }
    cout << most << endl;
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}