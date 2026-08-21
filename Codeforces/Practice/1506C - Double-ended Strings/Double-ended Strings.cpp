#include <iostream>
#include <string>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define endl '\n'
#define vin(v) for (auto &x : v) cin >> x
#define vout(v) for (auto &x : v) cout << x << ' '; cout << endl

void Solve() {
    string a, b;
    cin >> a >> b;
    ll n = a.size(), m = b.size();
    ll lcs = 0;

    for (ll len=1; len<=min(n, m); len++) {
        for (ll i=0; i<=n-len; i++) {
            for (ll j=0; j<=m-len; j++) {
                string sub_A = a.substr(i, len);
                string sub_B = b.substr(j, len);
                if (sub_A == sub_B) lcs = max(lcs, len);
            }
        }
    }

    ll op = n + m - 2 * lcs;
    cout << op << endl;
}

int main() {
    fastIO;

    ll testCount;
    cin >> testCount;

    while (testCount--) Solve();

    return 0;
}