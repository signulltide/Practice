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
    string a, b;
    cin >> n >> a >> b;
    ll a0 = 0, b0 = 0;
    for (ll i=0; i<n; i+=2) {
        if (a[i] == '0') a0++;
        if (b[i] == '0') b0++;
    }
    if (a0 != b0) {
        cout << "NO\n";
        return;
    }
    a0 = 0, b0 = 0;
    for (ll i=1; i<n; i+=2) {
        if (a[i] == '0') a0++;
        if (b[i] == '0') b0++;
    }
    if (a0 != b0) {
        cout << "NO\n";
        return;
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